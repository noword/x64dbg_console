#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <mutex>
#include "crossline.h"
#include "types.h"

#ifdef _DEBUG
#define Log(fmt, ...)    Printf("[LOG] " fmt "\n", __VA_ARGS__);
#define LogFunctionName    Log("*** " __FUNCTION__ " ***");
#else
#define LogFunctionName
#define Log(fmt, ...)
#endif // ifdef _DEBUG

#ifdef _WIN64
    #define DBG_LIB_NAME       "x64dbg.dll"
    #define BRIDGE_LIB_NAME    "x64bridge.dll"
    #define GUI_LIB_NAME       "x64gui.dll"
    #define PROMPT             "(x64dbg) "
    #define HEX_FORMAT         "%016llx"
#else
    #define DBG_LIB_NAME       "x32dbg.dll"
    #define BRIDGE_LIB_NAME    "x32bridge.dll"
    #define GUI_LIB_NAME       "x32gui.dll"
    #define PROMPT             "(x32dbg) "
    #define HEX_FORMAT         "%08x"
#endif // ifdef _WIN64

#define HISTORY_FILE           ".history.txt"

struct ColorPicker
{
    std::string       prefix;
    crossline_color_e color;
};

class Bridge
{
public:
    static Bridge *GetInstance();
    void FreeInstance();

    bool Init();
    int MainLoop(int argc, char *argv[]);
    int Printf(const char *format, ...);
    int Printf(const wchar_t *format, ...);

    const std::vector <std::string>& GetCommands() { return _commands; };

    const char * GuiTranslateText(const char *Source);
    void GuiDisasmAt(duint addr, duint cip);
    void GuiSetDebugState(DBGSTATE state);
    void GuiSetDebugStateFast(DBGSTATE state);
    void GuiAddLogMessage(const char *msg);
    void GuiAddLogMessageHtml(const char *msg);
    void GuiLogClear();
    void GuiUpdateAllViews();
    void GuiUpdateRegisterView();
    void GuiUpdateDisassemblyView();
    void GuiUpdateBreakpointsView();
    void GuiUpdateWindowTitle(const char *filename);
    HWND GuiGetWindowHandle();
    void GuiDumpAt(duint va);
    void GuiScriptAdd(int count, const char **lines);
    void GuiScriptClear();
    void GuiScriptSetIp(int line);
    void GuiScriptError(int line, const char *message);
    void GuiScriptSetTitle(const char *title);
    void GuiScriptSetInfoLine(int line, const char *info);
    void GuiScriptMessage(const char *message);
    int GuiScriptMsgyn(const char *message);
    void GuiScriptEnableHighlighting(bool enable);
    void GuiSymbolLogAdd(const char *message);
    void GuiSymbolLogClear();
    void GuiSymbolSetProgress(int percent);
    void GuiSymbolUpdateModuleList(int count, SYMBOLMODULEINFO *modules);
    void GuiSymbolRefreshCurrent();
    void GuiReferenceAddColumn(int width, const char *title);
    void GuiReferenceSetRowCount(int count);
    int GuiReferenceGetRowCount();
    int GuiReferenceSearchGetRowCount();
    void GuiReferenceDeleteAllColumns();
    void GuiReferenceInitialize(const char *name);
    void GuiReferenceSetCellContent(int row, int col, const char *str);
    char *GuiReferenceGetCellContent(int row, int col);
    char *GuiReferenceSearchGetCellContent(int row, int col);
    void GuiReferenceReloadData();
    void GuiReferenceSetSingleSelection(int index, bool scroll);
    void GuiReferenceSetProgress(int progress);
    void GuiReferenceSetCurrentTaskProgress(int progress, const char *taskTitle);
    void GuiReferenceSetSearchStartCol(int col);
    void GuiStackDumpAt(duint addr, duint csp);
    void GuiUpdateDumpView();
    void GuiUpdateWatchView();
    void GuiUpdateThreadView();
    void GuiUpdateMemoryView();
    void GuiAddRecentFile(const char *file);
    void GuiSetLastException(unsigned int exception);
    bool GuiGetDisassembly(duint addr, char *text);
    int GuiMenuAdd(int hMenu, const char *title);
    int GuiMenuAddEntry(int hMenu, const char *title);
    void GuiMenuAddSeparator(int hMenu);
    void GuiMenuClear(int hMenu);
    void GuiMenuRemove(int hEntryMenu);
    bool GuiSelectionGet(GUISELECTIONTYPE hWindow, SELECTIONDATA *selection);
    bool GuiSelectionSet(GUISELECTIONTYPE hWindow, const SELECTIONDATA *selection);
    bool GuiGetLineWindow(const char *title, char *text);
    void GuiAutoCompleteAddCmd(const char *cmd);
    void GuiAutoCompleteDelCmd(const char *cmd);
    void GuiAutoCompleteClearAll();
    void GuiAddStatusBarMessage(const char *msg);
    void GuiUpdateSideBar();
    void GuiRepaintTableView();
    void GuiUpdatePatches();
    void GuiUpdateCallStack();
    void GuiUpdateSEHChain();
    void GuiLoadSourceFileEx(const char *path, duint addr);
    void GuiMenuSetIcon(int hMenu, const ICONDATA *icon);
    void GuiMenuSetEntryIcon(int hEntry, const ICONDATA *icon);
    void GuiMenuSetEntryChecked(int hEntry, bool checked);
    void GuiMenuSetVisible(int hMenu, bool visible);
    void GuiMenuSetEntryVisible(int hEntry, bool visible);
    void GuiMenuSetName(int hMenu, const char *name);
    void GuiMenuSetEntryName(int hEntry, const char *name);
    void GuiMenuSetEntryHotkey(int hEntry, const char *hack);
    void GuiShowCpu();
    void GuiAddQWidgetTab(void *qWidget);
    void GuiShowQWidgetTab(void *qWidget);
    void GuiCloseQWidgetTab(void *qWidget);
    void GuiExecuteOnGuiThread(GUICALLBACK cbGuiThread);
    void GuiUpdateTimeWastedCounter();
    void GuiSetGlobalNotes(const char *text);
    void GuiGetGlobalNotes(char **text);
    void GuiSetDebuggeeNotes(const char *text);
    void GuiGetDebuggeeNotes(char **text);
    void GuiDumpAtN(duint va, int index);
    void GuiDisplayWarning(const char *title, const char *text);
    void GuiRegisterScriptLanguage(SCRIPTTYPEINFO *info);
    void GuiUnregisterScriptLanguage(int id);
    void GuiUpdateArgumentWidget();
    void GuiFocusView(int hWindow);
    bool GuiIsUpdateDisabled();
    void GuiUpdateEnable(bool updateNow);
    void GuiUpdateDisable();
    bool GuiLoadGraph(BridgeCFGraphList *graph, duint addr);
    duint GuiGraphAt(duint addr);
    void GuiUpdateGraphView();
    void GuiDisableLog();
    void GuiEnableLog();
    void GuiAddFavouriteTool(const char *name, const char *description);
    void GuiAddFavouriteCommand(const char *name, const char *shortcut);
    void GuiSetFavouriteToolShortcut(const char *name, const char *shortcut);
    void GuiFoldDisassembly(duint startAddress, duint length);
    void GuiSelectInMemoryMap(duint addr);
    void GuiGetActiveView(ACTIVEVIEW *activeView);
    void GuiAddInfoLine(const char *infoLine);
    void GuiProcessEvents();
    void *GuiTypeAddNode(void *parent, const TYPEDESCRIPTOR *type);
    bool GuiTypeClear();
    void GuiUpdateTypeWidget();
    void GuiCloseApplication();
    void GuiFlushLog();
    void GuiReferenceAddCommand(const char *title, const char *command);
    void GuiUpdateTraceBrowser();
    void GuiOpenTraceFile(const char *fileName);
    void GuiInvalidateSymbolSource(duint base);
    void GuiExecuteOnGuiThreadEx(GUICALLBACKEX cbGuiThread, void *userdata);
    void GuiGetCurrentGraph(BridgeCFGraphList *graphList);
    void GuiShowReferences();
    void GuiSelectInSymbolsTab(duint addr);
    void GuiGotoTrace(duint index);
    void GuiShowTrace();
    DWORD GuiGetMainThreadId();

private:
    // Singleton
    Bridge() : _dbgState(stopped) {};
    virtual ~Bridge();
    Bridge(Bridge& other) {};
    Bridge& operator=(Bridge& other) {};
    static Bridge *instance;

    void _WaitOutput();

    bool _DbgExecCmd(const char *command) { return _DbgCmdExec(command); };
    DBGSTATE _GetDbgState() { return _dbgState; };
    void _AutoCompleteAdd(const char *command);

    duint _DbgSendMessage(DBGMSG type, void *param1, void *param2) { return __dbg_sendmessage(type, param1, param2); };
    bool _DbgMemRead(duint addr, void *dest, duint size, duint *read) { return __dbg_memread(addr, dest, size, read); };
    int _PrintDisasm(duint addr, int count = 1);

    std::vector <std::string> _commands;
    static std::vector <ColorPicker> _colors;
    std::mutex _printMutex;

    // dlls
    HMODULE _bridgeModule;
    HMODULE _dbgModule;
    HMODULE _guiModule;

    // bridge lib functions
    BRIDGEINIT _BridgeInit;
    BRIDGESTART _BridgeStart;
    DBGINIT _DbgInit;
    DBGDBGCMDEXEC _DbgCmdExec;

    // dbg lib functions
    DBGSENDMESSAGE __dbg_sendmessage;
    DBGMEMREAD __dbg_memread;

    DBGSTATE _dbgState;
    DWORD _lastLogTime;
};
