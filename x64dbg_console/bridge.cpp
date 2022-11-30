#include <stdio.h>
#include "bridge.h"
#include "hooker.h"
#include "gui.h"

#define LOAD_LIBRARY(MODULE, NAME)                      \
    MODULE = LoadLibraryA(NAME);                        \
    if (!MODULE)                                        \
    {                                                   \
        Printf("[ERROR] failed to load library " NAME); \
        return false;                                   \
    }

#define GET_ADDRESS(MODULE, NAME)                             \
    *((FARPROC *)&_ ## NAME) = GetProcAddress(MODULE, #NAME); \
    if (!_ ## NAME)                                           \
    {                                                         \
        Printf("[ERROR] failed to find export " #NAME);       \
        return false;                                         \
    }

bool Bridge::Init()
{
    _lastLogTime = GetTickCount();

    LOAD_LIBRARY(_bridgeModule, BRIDGE_LIB_NAME);
    LOAD_LIBRARY(_dbgModule, DBG_LIB_NAME);
    LOAD_LIBRARY(_guiModule, GUI_LIB_NAME);

    GET_ADDRESS(_bridgeModule, BridgeInit);
    GET_ADDRESS(_bridgeModule, BridgeStart);
    GET_ADDRESS(_bridgeModule, DbgInit);
    GET_ADDRESS(_bridgeModule, DbgCmdExec);
    GET_ADDRESS(_bridgeModule, DbgGetRegDumpEx);
    GET_ADDRESS(_bridgeModule, DbgGetCommentAt);

    GET_ADDRESS(_dbgModule, _dbg_sendmessage);
    GET_ADDRESS(_dbgModule, _dbg_memread);

    SET_HOOKER(_guiModule, _gui_translate_text);
    SET_HOOKER(_guiModule, _gui_sendmessage);
    SET_HOOKER(_guiModule, _gui_guiinit);

    const wchar_t *errormsg = _BridgeInit();
    if (errormsg)
    {
        Printf(L"[ERROR] %s", errormsg);
        return false;
    }

    errormsg = _BridgeStart();
    if (errormsg)
    {
        Printf(L"[ERROR] %s", errormsg);
        return false;
    }

    return true;
}

void Bridge::_AutoCompleteAdd(const char *command)
{
    size_t      pos = 0;
    std::string s(command);

    while ((pos = s.find(",")) != std::string::npos)
    {
        std::string token = s.substr(0, pos);
        _commands.push_back(token);
        s.erase(0, pos + 1);
    }
    _commands.push_back(s);
}

Bridge::~Bridge()
{
    FreeLibrary(_bridgeModule);
    FreeLibrary(_dbgModule);
    FreeLibrary(_guiModule);
}

Bridge *Bridge::instance = nullptr;
Bridge * Bridge::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Bridge();
    }
    return instance;
}

void Bridge::FreeInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

const char * Bridge::GuiTranslateText(const char *Source)
{
    //LogFunctionName;
    return Source;
}

void Bridge::GuiDisasmAt(duint addr, duint cip)
{
    LogFunctionName;
    Log("addr: " HEX_FORMAT ", cip: " HEX_FORMAT, addr, cip);

    if (_dbgState != running && _dbgState != stopped)
    {
        _PrintDisasm(addr, 10);
    }
    return;
}

void Bridge::GuiSetDebugState(DBGSTATE state)
{
    LogFunctionName;
    _dbgState = state;
    return;
}

void Bridge::GuiSetDebugStateFast(DBGSTATE state)
{
    LogFunctionName;
    _dbgState = state;
    return;
}

void Bridge::GuiAddLogMessage(const char *msg)
{
    //LogFunctionName;
    Printf(msg);
    _lastLogTime = GetTickCount();
    return;
}

void Bridge::GuiAddLogMessageHtml(const char *msg)
{
    LogFunctionName;
    return;
}

void Bridge::GuiLogClear()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateAllViews()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateRegisterView()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateDisassemblyView()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateBreakpointsView()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateWindowTitle(const char *filename)
{
    LogFunctionName;
    Log("title: %s", filename);
    SetConsoleTitleA(filename);
    return;
}

HWND Bridge::GuiGetWindowHandle()
{
    LogFunctionName;
    return GetConsoleWindow();
}

void Bridge::GuiDumpAt(duint va)
{
    LogFunctionName;
    if (_dbgState != running && _dbgState != stopped)
    {
        _PrintMemory(va, 10);
    }
    return;
}

void Bridge::GuiScriptAdd(int count, const char **lines)
{
    LogFunctionName;
    return;
}

void Bridge::GuiScriptClear()
{
    LogFunctionName;
    return;
}

void Bridge::GuiScriptSetIp(int line)
{
    LogFunctionName;
    return;
}

void Bridge::GuiScriptError(int line, const char *message)
{
    LogFunctionName;
    return;
}

void Bridge::GuiScriptSetTitle(const char *title)
{
    LogFunctionName;
    return;
}

void Bridge::GuiScriptSetInfoLine(int line, const char *info)
{
    LogFunctionName;
    return;
}

void Bridge::GuiScriptMessage(const char *message)
{
    LogFunctionName;
    return;
}

int Bridge::GuiScriptMsgyn(const char *message)
{
    LogFunctionName;
    return 0;
}

void Bridge::GuiScriptEnableHighlighting(bool enable)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSymbolLogAdd(const char *message)
{
    //LogFunctionName;
    Printf("[SYMBOL] %s", (char *)message);
    _lastLogTime = GetTickCount();
    return;
}

void Bridge::GuiSymbolLogClear()
{
    LogFunctionName;
    return;
}

void Bridge::GuiSymbolSetProgress(int percent)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSymbolUpdateModuleList(int count, SYMBOLMODULEINFO *modules)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSymbolRefreshCurrent()
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceAddColumn(int width, const char *title)
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceSetRowCount(int count)
{
    LogFunctionName;
    return;
}

int Bridge::GuiReferenceGetRowCount()
{
    LogFunctionName;
    return 0;
}

int Bridge::GuiReferenceSearchGetRowCount()
{
    LogFunctionName;
    return 0;
}

void Bridge::GuiReferenceDeleteAllColumns()
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceInitialize(const char *name)
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceSetCellContent(int row, int col, const char *str)
{
    LogFunctionName;
    return;
}

char * Bridge::GuiReferenceGetCellContent(int row, int col)
{
    LogFunctionName;
    return NULL;
}

char * Bridge::GuiReferenceSearchGetCellContent(int row, int col)
{
    LogFunctionName;
    return NULL;
}

void Bridge::GuiReferenceReloadData()
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceSetSingleSelection(int index, bool scroll)
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceSetProgress(int progress)
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceSetCurrentTaskProgress(int progress, const char *taskTitle)
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceSetSearchStartCol(int col)
{
    LogFunctionName;
    return;
}

void Bridge::GuiStackDumpAt(duint addr, duint csp)
{
    LogFunctionName;
    if (_dbgState != running && _dbgState != stopped)
    {
        _PrintStack(addr, 10);
    }
    return;
}

void Bridge::GuiUpdateDumpView()
{
    //LogFunctionName;
    return;
}

void Bridge::GuiUpdateWatchView()
{
    //LogFunctionName;
    return;
}

void Bridge::GuiUpdateThreadView()
{
    //LogFunctionName;
    return;
}

void Bridge::GuiUpdateMemoryView()
{
    //LogFunctionName;
    return;
}

void Bridge::GuiAddRecentFile(const char *file)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSetLastException(unsigned int exception)
{
    LogFunctionName;
    return;
}

bool Bridge::GuiGetDisassembly(duint addr, char *text)
{
    LogFunctionName;
    return true;
}

int Bridge::GuiMenuAdd(int hMenu, const char *title)
{
    LogFunctionName;
    return hMenu;
}

int Bridge::GuiMenuAddEntry(int hMenu, const char *title)
{
    LogFunctionName;
    return hMenu;
}

void Bridge::GuiMenuAddSeparator(int hMenu)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuClear(int hMenu)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuRemove(int hEntryMenu)
{
    LogFunctionName;
    return;
}

bool Bridge::GuiSelectionGet(GUISELECTIONTYPE hWindow, SELECTIONDATA *selection)
{
    LogFunctionName;
    return true;
}

bool Bridge::GuiSelectionSet(GUISELECTIONTYPE hWindow, const SELECTIONDATA *selection)
{
    LogFunctionName;
    return true;
}

bool Bridge::GuiGetLineWindow(const char *title, char *text)
{
    LogFunctionName;
    return true;
}

void Bridge::GuiAutoCompleteAddCmd(const char *cmd)
{
    LogFunctionName;
    _AutoCompleteAdd(cmd);
    return;
}

void Bridge::GuiAutoCompleteDelCmd(const char *cmd)
{
    LogFunctionName;
    return;
}

void Bridge::GuiAutoCompleteClearAll()
{
    LogFunctionName;
    return;
}

void Bridge::GuiAddStatusBarMessage(const char *msg)
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateSideBar()
{
    LogFunctionName;
    return;
}

void Bridge::GuiRepaintTableView()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdatePatches()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateCallStack()
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateSEHChain()
{
    LogFunctionName;
    return;
}

void Bridge::GuiLoadSourceFileEx(const char *path, duint addr)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetIcon(int hMenu, const ICONDATA *icon)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetEntryIcon(int hEntry, const ICONDATA *icon)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetEntryChecked(int hEntry, bool checked)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetVisible(int hMenu, bool visible)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetEntryVisible(int hEntry, bool visible)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetName(int hMenu, const char *name)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetEntryName(int hEntry, const char *name)
{
    LogFunctionName;
    return;
}

void Bridge::GuiMenuSetEntryHotkey(int hEntry, const char *hack)
{
    LogFunctionName;
    return;
}

void Bridge::GuiShowCpu()
{
    LogFunctionName;
    return;
}

void Bridge::GuiAddQWidgetTab(void *qWidget)
{
    LogFunctionName;
    return;
}

void Bridge::GuiShowQWidgetTab(void *qWidget)
{
    LogFunctionName;
    return;
}

void Bridge::GuiCloseQWidgetTab(void *qWidget)
{
    LogFunctionName;
    return;
}

void Bridge::GuiExecuteOnGuiThread(GUICALLBACK cbGuiThread)
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateTimeWastedCounter()
{
    //LogFunctionName;
    return;
}

void Bridge::GuiSetGlobalNotes(const char *text)
{
    LogFunctionName;
    return;
}

void Bridge::GuiGetGlobalNotes(char **text)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSetDebuggeeNotes(const char *text)
{
    LogFunctionName;
    return;
}

void Bridge::GuiGetDebuggeeNotes(char **text)
{
    LogFunctionName;
    return;
}

void Bridge::GuiDumpAtN(duint va, int index)
{
    LogFunctionName;
    return;
}

void Bridge::GuiDisplayWarning(const char *title, const char *text)
{
    LogFunctionName;
    return;
}

void Bridge::GuiRegisterScriptLanguage(SCRIPTTYPEINFO *info)
{
    LogFunctionName;
    return;
}

void Bridge::GuiUnregisterScriptLanguage(int id)
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateArgumentWidget()
{
    LogFunctionName;
    return;
}

void Bridge::GuiFocusView(int hWindow)
{
    LogFunctionName;
    return;
}

bool Bridge::GuiIsUpdateDisabled()
{
    LogFunctionName;
    return false;
}

void Bridge::GuiUpdateEnable(bool updateNow)
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateDisable()
{
    LogFunctionName;
    return;
}

bool Bridge::GuiLoadGraph(BridgeCFGraphList *graph, duint addr)
{
    LogFunctionName;
    return true;
}

duint Bridge::GuiGraphAt(duint addr)
{
    LogFunctionName;
    return addr;
}

void Bridge::GuiUpdateGraphView()
{
    LogFunctionName;
    return;
}

void Bridge::GuiDisableLog()
{
    LogFunctionName;
    return;
}

void Bridge::GuiEnableLog()
{
    LogFunctionName;
    return;
}

void Bridge::GuiAddFavouriteTool(const char *name, const char *description)
{
    LogFunctionName;
    return;
}

void Bridge::GuiAddFavouriteCommand(const char *name, const char *shortcut)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSetFavouriteToolShortcut(const char *name, const char *shortcut)
{
    LogFunctionName;
    return;
}

void Bridge::GuiFoldDisassembly(duint startAddress, duint length)
{
    LogFunctionName;
    return;
}

void Bridge::GuiSelectInMemoryMap(duint addr)
{
    LogFunctionName;
    return;
}

void Bridge::GuiGetActiveView(ACTIVEVIEW *activeView)
{
    LogFunctionName;
    return;
}

void Bridge::GuiAddInfoLine(const char *infoLine)
{
    LogFunctionName;
    return;
}

void Bridge::GuiProcessEvents()
{
    LogFunctionName;
    return;
}

void * Bridge::GuiTypeAddNode(void *parent, const TYPEDESCRIPTOR *type)
{
    LogFunctionName;
    return NULL;
}

bool Bridge::GuiTypeClear()
{
    LogFunctionName;
    return true;
}

void Bridge::GuiUpdateTypeWidget()
{
    LogFunctionName;
    return;
}

void Bridge::GuiCloseApplication()
{
    LogFunctionName;
    return;
}

void Bridge::GuiFlushLog()
{
    LogFunctionName;
    return;
}

void Bridge::GuiReferenceAddCommand(const char *title, const char *command)
{
    LogFunctionName;
    return;
}

void Bridge::GuiUpdateTraceBrowser()
{
    LogFunctionName;
    return;
}

void Bridge::GuiOpenTraceFile(const char *fileName)
{
    LogFunctionName;
    return;
}

void Bridge::GuiInvalidateSymbolSource(duint base)
{
    LogFunctionName;
    return;
}

void Bridge::GuiExecuteOnGuiThreadEx(GUICALLBACKEX cbGuiThread, void *userdata)
{
    LogFunctionName;
    return;
}

void Bridge::GuiGetCurrentGraph(BridgeCFGraphList *graphList)
{
    LogFunctionName;
    return;
}

void Bridge::GuiShowReferences()
{
    LogFunctionName;
    return;
}

void Bridge::GuiSelectInSymbolsTab(duint addr)
{
    LogFunctionName;
    return;
}

void Bridge::GuiGotoTrace(duint index)
{
    LogFunctionName;
    return;
}

void Bridge::GuiShowTrace()
{
    LogFunctionName;
    return;
}

DWORD Bridge::GuiGetMainThreadId()
{
    LogFunctionName;
    return GetCurrentThreadId();
}

void completion_hook(char const *buf, crossline_completions_t *pCompletion)
{
    size_t size = strlen(buf);

    for (auto s : Bridge::GetInstance()->GetCommands())
    {
        if (_strnicmp(buf, s.c_str(), size) == 0)
        {
            crossline_completion_add(pCompletion, s.c_str(), NULL);
        }
    }
}

int Bridge::MainLoop(int argc, char *argv[])
{
    _DbgInit();
    _AutoCompleteAdd("quit,exit,registers");

    _WaitOutput();

    crossline_history_load(HISTORY_FILE);
    crossline_completion_register(completion_hook);
    crossline_prompt_color_set(crossline_color_e(CROSSLINE_FGCOLOR_BRIGHT | CROSSLINE_FGCOLOR_GREEN));

    char cmd[128];
    while (crossline_readline(PROMPT, cmd, 128))
    {
        if (_strcmpi(cmd, "quit") == 0 || _strcmpi(cmd, "exit") == 0)
        {
            break;
        }
        else if (_strcmpi(cmd, "registers") == 0)
        {
            _PrintRegisters();
        }
        else
        {
            _DbgExecCmd(cmd);
        }

        Sleep(200);

        _WaitOutput();
    }

    crossline_history_save(HISTORY_FILE);

    return 0;
}
