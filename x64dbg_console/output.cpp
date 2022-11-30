#include "bridge.h"

#define COLOR_ADDRESS         CROSSLINE_FGCOLOR_BLUE
#define COLOR_HEX             CROSSLINE_FGCOLOR_CYAN
#define COLOR_INSTR_NORMAL    crossline_color_e(CROSSLINE_FGCOLOR_WHITE | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_INSTR_BRANCH    crossline_color_e(CROSSLINE_FGCOLOR_CYAN | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_INSTR_STACK     crossline_color_e(CROSSLINE_FGCOLOR_BLUE | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_ARG_NORMAL      CROSSLINE_FGCOLOR_WHITE
#define COLOR_ARG_MEMORY      crossline_color_e(CROSSLINE_FGCOLOR_MAGENTA | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_ARG_DIGITAL     crossline_color_e(CROSSLINE_FGCOLOR_YELLOW | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_HEADER          crossline_color_e(CROSSLINE_FGCOLOR_BLACK | CROSSLINE_BGCOLOR_WHITE)
#define COLOR_REG_NAME        crossline_color_e(CROSSLINE_FGCOLOR_BLUE | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_REG_VALUE       crossline_color_e(CROSSLINE_FGCOLOR_WHITE | CROSSLINE_FGCOLOR_BRIGHT)
#define COLOR_COMMENT         CROSSLINE_FGCOLOR_CYAN

std::vector <ColorPicker> Bridge::_colors =
{
    { "Invalid value",   CROSSLINE_FGCOLOR_RED    },
    { "Unknown command", CROSSLINE_FGCOLOR_RED    },
    { "[ERROR]",         CROSSLINE_FGCOLOR_RED    },
    { "[TODO]",          CROSSLINE_FGCOLOR_RED    },
    { "[SYMBOL]",        CROSSLINE_FGCOLOR_YELLOW },
    { "[LOG]",           CROSSLINE_FGCOLOR_BLUE   },
    { "[PLUGIN]",        CROSSLINE_FGCOLOR_GREEN  }
};

void Bridge::_WaitOutput()
{
    while (GetTickCount() - _lastLogTime < 500 || _dbgState == running)
    {
        Sleep(200);
    }
}

int Bridge::Printf(const char *format, ...)
{
    std::lock_guard <std::mutex> lock(_printMutex);

    for (auto c : _colors)
    {
        if (c.prefix.compare(0, c.prefix.size(), format, c.prefix.size()) == 0)
        {
            crossline_color_set(c.color);
            break;
        }
    }
    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);
    crossline_color_set(crossline_color_e(CROSSLINE_FGCOLOR_DEFAULT | CROSSLINE_BGCOLOR_BLACK));
    return result;
}

int Bridge::Printf(const wchar_t *format, ...)
{
    va_list args;
    va_start(args, format);
    int result = vwprintf(format, args);
    va_end(args);
    return result;
}

#define INSTR_BUF_SIZE    10

void Bridge::_PrintDisasm(duint addr, int count)
{
    DISASM_INSTR  instr;
    unsigned char buf[INSTR_BUF_SIZE];
    std::lock_guard <std::mutex> lock(_printMutex);
    for (int i = 0; i < count; i++)
    {
        _DbgSendMessage(DBG_DISASM_AT, (void *)addr, &instr);
        // display address
        crossline_color_set(COLOR_ADDRESS);
        printf(HEX_FORMAT " ", addr);

        // dislpay hex memory
        crossline_color_set(COLOR_HEX);
        int size = min(instr.instr_size, INSTR_BUF_SIZE);
        _DbgMemRead(addr, buf, size, 0);
        for (int j = 0; j < INSTR_BUF_SIZE + 1; j++)
        {
            if (j < size)
            {
                printf("%02X", buf[j]);
            }
            else
            {
                printf("  ");
            }
        }

        // display instr only
        crossline_color_e color = CROSSLINE_FGCOLOR_DEFAULT;
        switch (instr.type)
        {
        case instr_normal:
            color = COLOR_INSTR_NORMAL;
            break;

        case instr_branch:
            color = COLOR_INSTR_BRANCH;
            break;

        case instr_stack:
            color = COLOR_INSTR_STACK;
            break;
        }
        crossline_color_set(color);
        char *instrp = strchr(instr.instruction, ' ');
        if (instrp)
        {
            *instrp = '\x00';
        }
        printf("%s ", instr.instruction);
        instrp++;

        // display args
        for (int j = 0; j < instr.argcount; j++)
        {
            DISASM_ARG *arg = &instr.arg[j];
            char *      p;
            strtol(arg->mnemonic, &p, 16);
            if (*p == '\x00')
            {
                color = COLOR_ARG_DIGITAL;
            }
            else
            {
                color = arg->type == arg_normal ? COLOR_ARG_NORMAL : COLOR_ARG_MEMORY;
            }
            crossline_color_set(color);
            p = strchr(instrp, ',');
            if (p)
            {
                *p = '\x00';
            }
            printf(instrp);
            if (p)
            {
                instrp = p + 1;
            }
            crossline_color_set(CROSSLINE_FGCOLOR_DEFAULT);
            if (j + 1 < instr.argcount)
            {
                printf(",");
            }
        }
        printf("\n");

        addr += instr.instr_size;
    }

    return;
}

void Bridge::_PrintStack(duint addr, int count)
{
    count = count > 0 ? count : 1;
    std::lock_guard <std::mutex> lock(_printMutex);
    duint *buf = new duint[count];
    char text[MAX_COMMENT_SIZE];
    _DbgMemRead(addr, buf, sizeof(duint) * count, 0);
    for (int i = 0; i < count; i++)
    {
        if (!_DbgGetCommentAt(buf[i], text))
        {
            *text = '\x00';
        }
        crossline_color_set(COLOR_ADDRESS);
        printf(HEX_FORMAT " ", addr);
        crossline_color_set(COLOR_REG_VALUE);
        printf(HEX_FORMAT " ", buf[i]);
        crossline_color_set(COLOR_COMMENT);
        printf("%s\n", text);
        addr += sizeof(duint);
    }
    delete []buf;
}

void Bridge::_PrintMemory(duint addr, int line)
{
    line = line > 0 ? line : 1;

    std::lock_guard <std::mutex> lock(_printMutex);
    unsigned char *buf       = new unsigned char[line * 0x10];
    unsigned char *p         = buf;
    char           ascii[17] = { 0 };

    addr >>= 4;
    addr <<= 4;

    _DbgMemRead(addr, buf, line * 0x10, 0);
    crossline_color_set(COLOR_HEADER);
#ifdef _WIN64
    printf("%-17s%-54s%-16s\n", "Address", "Hex", "ASCII");
#else
    printf("%-9s%-54s%-16s\n", "Address", "Hex", "ASCII");
#endif
    for (int i = 0; i < line; i++)
    {
        crossline_color_set(COLOR_ADDRESS);
        printf(HEX_FORMAT " ", addr);
        crossline_color_set(COLOR_ARG_NORMAL);
        for (int j = 0; j < 0x10; j++)
        {
            printf("%02X ", *p);
            if ((j + 1) % 4 == 0)
            {
                printf(" ");
            }
            if (j == 7)
            {
                printf(" ");
            }
            ascii[j] = (isprint(*p) ? *p : '.');
            p++;
        }
        crossline_color_set(COLOR_COMMENT);
        printf(" %s\n", ascii);
        addr += 0x10;
    }
}

#define PRINTF_REG(NAME, REG)                       \
    crossline_color_set(COLOR_REG_NAME);            \
    printf("%-10s", NAME);                          \
    crossline_color_set(COLOR_REG_VALUE);           \
    printf(HEX_FORMAT "   ", REG);                  \
    crossline_color_set(COLOR_COMMENT); \
    if (!_DbgGetCommentAt(REG, text))               \
    {                                               \
        *text = '\x00';                             \
    }                                               \
    printf("%s\n", text);


#define PRINTF_FLAG(NAME, FLAG)           \
    crossline_color_set(COLOR_REG_NAME);  \
    printf("%-3s", NAME);                 \
    crossline_color_set(COLOR_REG_VALUE); \
    printf("%d ", FLAG);

void Bridge::_PrintRegisters()
{
    REGDUMP          reg;
    REGISTERCONTEXT *context = &reg.regcontext;
    ULONG_PTR *      flags   = &reg.regcontext.eflags;
    char             text[MAX_COMMENT_SIZE];
    if (_DbgGetRegDumpEx(&reg, sizeof(REGDUMP)))
    {
#ifdef _WIN64
        PRINTF_REG("RAX", context->cax);
        PRINTF_REG("RBX", context->cbx);
        PRINTF_REG("RCX", context->ccx);
        PRINTF_REG("RDX", context->cdx);
        PRINTF_REG("RBP", context->cbp);
        PRINTF_REG("RSP", context->csp);
        PRINTF_REG("RSI", context->csi);
        PRINTF_REG("RDI", context->cdi);
        printf("\n");
        PRINTF_REG("R8", context->r8);
        PRINTF_REG("R9", context->r9);
        PRINTF_REG("R10", context->r10);
        PRINTF_REG("R11", context->r11);
        PRINTF_REG("R12", context->r12);
        PRINTF_REG("R13", context->r13);
        PRINTF_REG("R14", context->r14);
        PRINTF_REG("R15", context->r15);
        printf("\n");
        PRINTF_REG("RIP", context->cip);
        printf("\n");
        PRINTF_REG("RFLAGS", context->eflags);
#else
        PRINTF_REG("EAX", context->cax);
        PRINTF_REG("EBX", context->cbx);
        PRINTF_REG("ECX", context->ccx);
        PRINTF_REG("EDX", context->cdx);
        PRINTF_REG("EBP", context->cbp);
        PRINTF_REG("ESP", context->csp);
        PRINTF_REG("ESI", context->csi);
        PRINTF_REG("EDI", context->cdi);
        printf("\n");
        PRINTF_REG("EIP", context->cip);
        printf("\n");
        PRINTF_REG("EFLAGS", context->eflags);
#endif
        printf("  ");
        PRINTF_FLAG("ZF", bool(*flags & 0x40));
        PRINTF_FLAG("PF", bool(*flags & 4));
        PRINTF_FLAG("AF", bool(*flags & 0x10));
        printf("\n  ");
        PRINTF_FLAG("OF", bool(*flags & 0x800));
        PRINTF_FLAG("SF", bool(*flags & 0x80));
        PRINTF_FLAG("DF", bool(*flags & 0x400));
        printf("\n  ");
        PRINTF_FLAG("CF", bool(*flags & 1));
        PRINTF_FLAG("TF", bool(*flags & 0x100));
        PRINTF_FLAG("IF", bool(*flags & 0x200));
        printf("\n");
    }
}
