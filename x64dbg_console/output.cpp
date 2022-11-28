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
    _DbgMemRead(addr, buf, sizeof(duint) * count, 0);
    for (int i = 0; i < count; i++)
    {
        crossline_color_set(COLOR_ADDRESS);
        printf(HEX_FORMAT " ", addr);
        crossline_color_set(COLOR_ARG_NORMAL);
        printf(HEX_FORMAT "\n", buf[i]);
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
        printf(" %s\n", ascii);
        addr += 0x10;
    }
}
