#include <stdio.h>
#include "bridge.h"

#ifdef _DEBUG
#define LogFunctionName puts("*** " __FUNCTION__ " ***");
#else
#define LogFunctionName
#endif

const char* GuiTranslateTextHook(const char* Source)
{
    //LogFunctionName;
    return Source;
}

void GuiDisasmAtHook(duint addr, duint cip)
{
    LogFunctionName;
    return;
}

void GuiSetDebugStateHook(DBGSTATE state)
{
    LogFunctionName;
    Bridge::GetInstance()->SetDbgState(state);
    return;
}

void GuiSetDebugStateFastHook(DBGSTATE state)
{
    LogFunctionName;
    return;
}

void GuiAddLogMessageHook(const char* msg)
{
    //LogFunctionName;
    Bridge::GetInstance()->AddLogMessage(msg);
    return;
}

void GuiAddLogMessageHtmlHook(const char* msg)
{
    LogFunctionName;
    return;
}

void GuiLogClearHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateAllViewsHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateRegisterViewHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateDisassemblyViewHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateBreakpointsViewHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateWindowTitleHook(const char* filename)
{
    LogFunctionName;
    return;
}

HWND GuiGetWindowHandleHook()
{
    LogFunctionName;
    return NULL;
}

void GuiDumpAtHook(duint va)
{
    LogFunctionName;
    return;
}

void GuiScriptAddHook(int count, const char** lines)
{
    LogFunctionName;
    return;
}

void GuiScriptClearHook()
{
    LogFunctionName;
    return;
}

void GuiScriptSetIpHook(int line)
{
    LogFunctionName;
    return;
}

void GuiScriptErrorHook(int line, const char* message)
{
    LogFunctionName;
    return;
}

void GuiScriptSetTitleHook(const char* title)
{
    LogFunctionName;
    return;
}

void GuiScriptSetInfoLineHook(int line, const char* info)
{
    LogFunctionName;
    return;
}

void GuiScriptMessageHook(const char* message)
{
    LogFunctionName;
    return;
}

int GuiScriptMsgynHook(const char* message)
{
    LogFunctionName;
    return 0;
}

void GuiScriptEnableHighlightingHook(bool enable)
{
    LogFunctionName;
    return;
}

void GuiSymbolLogAddHook(const char* message)
{
    LogFunctionName;
    return;
}

void GuiSymbolLogClearHook()
{
    LogFunctionName;
    return;
}

void GuiSymbolSetProgressHook(int percent)
{
    LogFunctionName;
    return;
}

void GuiSymbolUpdateModuleListHook(int count, SYMBOLMODULEINFO* modules)
{
    LogFunctionName;
    return;
}

void GuiSymbolRefreshCurrentHook()
{
    LogFunctionName;
    return;
}

void GuiReferenceAddColumnHook(int width, const char* title)
{
    LogFunctionName;
    return;
}

void GuiReferenceSetRowCountHook(int count)
{
    LogFunctionName;
    return;
}

int GuiReferenceGetRowCountHook()
{
    LogFunctionName;
    return 0;
}

int GuiReferenceSearchGetRowCountHook()
{
    LogFunctionName;
    return 0;
}

void GuiReferenceDeleteAllColumnsHook()
{
    LogFunctionName;
    return;
}

void GuiReferenceInitializeHook(const char* name)
{
    LogFunctionName;
    return;
}

void GuiReferenceSetCellContentHook(int row, int col, const char* str)
{
    LogFunctionName;
    return;
}

char* GuiReferenceGetCellContentHook(int row, int col)
{
    LogFunctionName;
    return NULL;
}

char* GuiReferenceSearchGetCellContentHook(int row, int col)
{
    LogFunctionName;
    return NULL;
}

void GuiReferenceReloadDataHook()
{
    LogFunctionName;
    return;
}

void GuiReferenceSetSingleSelectionHook(int index, bool scroll)
{
    LogFunctionName;
    return;
}

void GuiReferenceSetProgressHook(int progress)
{
    LogFunctionName;
    return;
}

void GuiReferenceSetCurrentTaskProgressHook(int progress, const char* taskTitle)
{
    LogFunctionName;
    return;
}

void GuiReferenceSetSearchStartColHook(int col)
{
    LogFunctionName;
    return;
}

void GuiStackDumpAtHook(duint addr, duint csp)
{
    LogFunctionName;
    return;
}

void GuiUpdateDumpViewHook()
{
    //LogFunctionName;
    return;
}

void GuiUpdateWatchViewHook()
{
    //LogFunctionName;
    return;
}

void GuiUpdateThreadViewHook()
{
    //LogFunctionName;
    return;
}

void GuiUpdateMemoryViewHook()
{
    //LogFunctionName;
    return;
}

void GuiAddRecentFileHook(const char* file)
{
    LogFunctionName;
    return;
}

void GuiSetLastExceptionHook(unsigned int exception)
{
    LogFunctionName;
    return;
}

bool GuiGetDisassemblyHook(duint addr, char* text)
{
    LogFunctionName;
    return true;
}

int GuiMenuAddHook(int hMenu, const char* title)
{
    LogFunctionName;
    return hMenu;
}

int GuiMenuAddEntryHook(int hMenu, const char* title)
{
    LogFunctionName;
    return hMenu;
}

void GuiMenuAddSeparatorHook(int hMenu)
{
    LogFunctionName;
    return;
}

void GuiMenuClearHook(int hMenu)
{
    LogFunctionName;
    return;
}

void GuiMenuRemoveHook(int hEntryMenu)
{
    LogFunctionName;
    return;
}

bool GuiSelectionGetHook(GUISELECTIONTYPE hWindow, SELECTIONDATA* selection)
{
    LogFunctionName;
    return true;
}

bool GuiSelectionSetHook(GUISELECTIONTYPE hWindow, const SELECTIONDATA* selection)
{
    LogFunctionName;
    return true;
}

bool GuiGetLineWindowHook(const char* title, char* text)
{
    LogFunctionName;
    return true;
}

void GuiAutoCompleteAddCmdHook(const char* cmd)
{
    LogFunctionName;
    Bridge::GetInstance()->AutoCompleteAdd(cmd);
    return;
}

void GuiAutoCompleteDelCmdHook(const char* cmd)
{
    LogFunctionName;
    return;
}

void GuiAutoCompleteClearAllHook()
{
    LogFunctionName;
    return;
}

void GuiAddStatusBarMessageHook(const char* msg)
{
    LogFunctionName;
    return;
}

void GuiUpdateSideBarHook()
{
    LogFunctionName;
    return;
}

void GuiRepaintTableViewHook()
{
    LogFunctionName;
    return;
}

void GuiUpdatePatchesHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateCallStackHook()
{
    LogFunctionName;
    return;
}

void GuiUpdateSEHChainHook()
{
    LogFunctionName;
    return;
}

void GuiLoadSourceFileExHook(const char* path, duint addr)
{
    LogFunctionName;
    return;
}

void GuiMenuSetIconHook(int hMenu, const ICONDATA* icon)
{
    LogFunctionName;
    return;
}

void GuiMenuSetEntryIconHook(int hEntry, const ICONDATA* icon)
{
    LogFunctionName;
    return;
}

void GuiMenuSetEntryCheckedHook(int hEntry, bool checked)
{
    LogFunctionName;
    return;
}

void GuiMenuSetVisibleHook(int hMenu, bool visible)
{
    LogFunctionName;
    return;
}

void GuiMenuSetEntryVisibleHook(int hEntry, bool visible)
{
    LogFunctionName;
    return;
}

void GuiMenuSetNameHook(int hMenu, const char* name)
{
    LogFunctionName;
    return;
}

void GuiMenuSetEntryNameHook(int hEntry, const char* name)
{
    LogFunctionName;
    return;
}

void GuiMenuSetEntryHotkeyHook(int hEntry, const char* hack)
{
    LogFunctionName;
    return;
}

void GuiShowCpuHook()
{
    LogFunctionName;
    return;
}

void GuiAddQWidgetTabHook(void* qWidget)
{
    LogFunctionName;
    return;
}

void GuiShowQWidgetTabHook(void* qWidget)
{
    LogFunctionName;
    return;
}

void GuiCloseQWidgetTabHook(void* qWidget)
{
    LogFunctionName;
    return;
}

void GuiExecuteOnGuiThreadHook(GUICALLBACK cbGuiThread)
{
    LogFunctionName;
    return;
}

void GuiUpdateTimeWastedCounterHook()
{
    //LogFunctionName;
    return;
}

void GuiSetGlobalNotesHook(const char* text)
{
    LogFunctionName;
    return;
}

void GuiGetGlobalNotesHook(char** text)
{
    LogFunctionName;
    return;
}

void GuiSetDebuggeeNotesHook(const char* text)
{
    LogFunctionName;
    return;
}

void GuiGetDebuggeeNotesHook(char** text)
{
    LogFunctionName;
    return;
}

void GuiDumpAtNHook(duint va, int index)
{
    LogFunctionName;
    return;
}

void GuiDisplayWarningHook(const char* title, const char* text)
{
    LogFunctionName;
    return;
}

void GuiRegisterScriptLanguageHook(SCRIPTTYPEINFO* info)
{
    LogFunctionName;
    return;
}

void GuiUnregisterScriptLanguageHook(int id)
{
    LogFunctionName;
    return;
}

void GuiUpdateArgumentWidgetHook()
{
    LogFunctionName;
    return;
}

void GuiFocusViewHook(int hWindow)
{
    LogFunctionName;
    return;
}

bool GuiIsUpdateDisabledHook()
{
    LogFunctionName;
    return false;
}

void GuiUpdateEnableHook(bool updateNow)
{
    LogFunctionName;
    return;
}

void GuiUpdateDisableHook()
{
    LogFunctionName;
    return;
}

bool GuiLoadGraphHook(BridgeCFGraphList* graph, duint addr)
{
    LogFunctionName;
    return true;
}

duint GuiGraphAtHook(duint addr)
{
    LogFunctionName;
    return addr;
}

void GuiUpdateGraphViewHook()
{
    LogFunctionName;
    return;
}

void GuiDisableLogHook()
{
    LogFunctionName;
    return;
}

void GuiEnableLogHook()
{
    LogFunctionName;
    return;
}

void GuiAddFavouriteToolHook(const char* name, const char* description)
{
    LogFunctionName;
    return;
}

void GuiAddFavouriteCommandHook(const char* name, const char* shortcut)
{
    LogFunctionName;
    return;
}

void GuiSetFavouriteToolShortcutHook(const char* name, const char* shortcut)
{
    LogFunctionName;
    return;
}

void GuiFoldDisassemblyHook(duint startAddress, duint length)
{
    LogFunctionName;
    return;
}

void GuiSelectInMemoryMapHook(duint addr)
{
    LogFunctionName;
    return;
}

void GuiGetActiveViewHook(ACTIVEVIEW* activeView)
{
    LogFunctionName;
    return;
}

void GuiAddInfoLineHook(const char* infoLine)
{
    LogFunctionName;
    return;
}

void GuiProcessEventsHook()
{
    LogFunctionName;
    return;
}

void* GuiTypeAddNodeHook(void* parent, const TYPEDESCRIPTOR* type)
{
    LogFunctionName;
    return NULL;
}

bool GuiTypeClearHook()
{
    LogFunctionName;
    return true;
}

void GuiUpdateTypeWidgetHook()
{
    LogFunctionName;
    return;
}

void GuiCloseApplicationHook()
{
    LogFunctionName;
    return;
}

void GuiFlushLogHook()
{
    LogFunctionName;
    return;
}

void GuiReferenceAddCommandHook(const char* title, const char* command)
{
    LogFunctionName;
    return;
}

void GuiUpdateTraceBrowserHook()
{
    LogFunctionName;
    return;
}

void GuiOpenTraceFileHook(const char* fileName)
{
    LogFunctionName;
    return;
}

void GuiInvalidateSymbolSourceHook(duint base)
{
    LogFunctionName;
    return;
}

void GuiExecuteOnGuiThreadExHook(GUICALLBACKEX cbGuiThread, void* userdata)
{
    LogFunctionName;
    return;
}

void GuiGetCurrentGraphHook(BridgeCFGraphList* graphList)
{
    LogFunctionName;
    return;
}

void GuiShowReferencesHook()
{
    LogFunctionName;
    return;
}

void GuiSelectInSymbolsTabHook(duint addr)
{
    LogFunctionName;
    return;
}

void GuiGotoTraceHook(duint index)
{
    LogFunctionName;
    return;
}

void GuiShowTraceHook()
{
    LogFunctionName;
    return;
}

DWORD GuiGetMainThreadIdHook()
{
    LogFunctionName;
    return 0;
}

void SetHooker(void* targetFunction, void* hookedFunction)
{
#ifdef _WIN64
    // ff 25 00 00 00 00            jmp [rip]
    // xx xx xx xx xx xx xx xx xx   [address]
    char codes[14] = { '\xff', '\x25' };
    *(uintptr_t*)(codes + 6) = (uintptr_t)hookedFunction;
#else
    // e9 xx xx xx xx               jmp address
    char codes[5] = { '\xe9' };
    *(uintptr_t*)(codes + 1) = (uintptr_t)hookedFunction - (uintptr_t)targetFunction - 5;
#endif // ifdef _WIN64

    MEMORY_BASIC_INFORMATION mbi;
    DWORD oldProtect;
    VirtualQuery(targetFunction, &mbi, sizeof(mbi));
    VirtualProtect(mbi.BaseAddress, sizeof(codes), PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy(targetFunction, codes, sizeof(codes));
    VirtualProtect(mbi.BaseAddress, sizeof(codes), oldProtect, &oldProtect);
}

void SetHooker(HMODULE module, const char* name, void* hookedFunction)
{
    void* target = GetProcAddress(module, name);

    if (!target)
    {
        printf("Export %s could not be found", name);
    }
    else
    {
        SetHooker(target, hookedFunction);
    }
}

#define SET_HOOKER(MODULE, NAME) SetHooker(MODULE, #NAME, NAME ## Hook);

void Bridge::_HookAllGui()
{
    SET_HOOKER(_bridgeModule, GuiTranslateText);
    SET_HOOKER(_bridgeModule, GuiDisasmAt);
    SET_HOOKER(_bridgeModule, GuiSetDebugState);
    SET_HOOKER(_bridgeModule, GuiSetDebugStateFast);
    SET_HOOKER(_bridgeModule, GuiAddLogMessage);
    SET_HOOKER(_bridgeModule, GuiAddLogMessageHtml);
    SET_HOOKER(_bridgeModule, GuiLogClear);
    SET_HOOKER(_bridgeModule, GuiUpdateAllViews);
    SET_HOOKER(_bridgeModule, GuiUpdateRegisterView);
    SET_HOOKER(_bridgeModule, GuiUpdateDisassemblyView);
    SET_HOOKER(_bridgeModule, GuiUpdateBreakpointsView);
    SET_HOOKER(_bridgeModule, GuiUpdateWindowTitle);
    SET_HOOKER(_bridgeModule, GuiGetWindowHandle);
    SET_HOOKER(_bridgeModule, GuiDumpAt);
    SET_HOOKER(_bridgeModule, GuiScriptAdd);
    SET_HOOKER(_bridgeModule, GuiScriptClear);
    SET_HOOKER(_bridgeModule, GuiScriptSetIp);
    SET_HOOKER(_bridgeModule, GuiScriptError);
    SET_HOOKER(_bridgeModule, GuiScriptSetTitle);
    SET_HOOKER(_bridgeModule, GuiScriptSetInfoLine);
    SET_HOOKER(_bridgeModule, GuiScriptMessage);
    SET_HOOKER(_bridgeModule, GuiScriptMsgyn);
    SET_HOOKER(_bridgeModule, GuiScriptEnableHighlighting);
    SET_HOOKER(_bridgeModule, GuiSymbolLogAdd);
    SET_HOOKER(_bridgeModule, GuiSymbolLogClear);
    SET_HOOKER(_bridgeModule, GuiSymbolSetProgress);
    SET_HOOKER(_bridgeModule, GuiSymbolUpdateModuleList);
    SET_HOOKER(_bridgeModule, GuiSymbolRefreshCurrent);
    SET_HOOKER(_bridgeModule, GuiReferenceAddColumn);
    SET_HOOKER(_bridgeModule, GuiReferenceSetRowCount);
    SET_HOOKER(_bridgeModule, GuiReferenceGetRowCount);
    SET_HOOKER(_bridgeModule, GuiReferenceSearchGetRowCount);
    SET_HOOKER(_bridgeModule, GuiReferenceDeleteAllColumns);
    SET_HOOKER(_bridgeModule, GuiReferenceInitialize);
    SET_HOOKER(_bridgeModule, GuiReferenceSetCellContent);
    SET_HOOKER(_bridgeModule, GuiReferenceGetCellContent);
    SET_HOOKER(_bridgeModule, GuiReferenceSearchGetCellContent);
    SET_HOOKER(_bridgeModule, GuiReferenceReloadData);
    SET_HOOKER(_bridgeModule, GuiReferenceSetSingleSelection);
    SET_HOOKER(_bridgeModule, GuiReferenceSetProgress);
    SET_HOOKER(_bridgeModule, GuiReferenceSetCurrentTaskProgress);
    SET_HOOKER(_bridgeModule, GuiReferenceSetSearchStartCol);
    SET_HOOKER(_bridgeModule, GuiStackDumpAt);
    SET_HOOKER(_bridgeModule, GuiUpdateDumpView);
    SET_HOOKER(_bridgeModule, GuiUpdateWatchView);
    SET_HOOKER(_bridgeModule, GuiUpdateThreadView);
    SET_HOOKER(_bridgeModule, GuiUpdateMemoryView);
    SET_HOOKER(_bridgeModule, GuiAddRecentFile);
    SET_HOOKER(_bridgeModule, GuiSetLastException);
    SET_HOOKER(_bridgeModule, GuiGetDisassembly);
    SET_HOOKER(_bridgeModule, GuiMenuAdd);
    SET_HOOKER(_bridgeModule, GuiMenuAddEntry);
    SET_HOOKER(_bridgeModule, GuiMenuAddSeparator);
    SET_HOOKER(_bridgeModule, GuiMenuClear);
    SET_HOOKER(_bridgeModule, GuiMenuRemove);
    SET_HOOKER(_bridgeModule, GuiSelectionGet);
    SET_HOOKER(_bridgeModule, GuiSelectionSet);
    SET_HOOKER(_bridgeModule, GuiGetLineWindow);
    SET_HOOKER(_bridgeModule, GuiAutoCompleteAddCmd);
    SET_HOOKER(_bridgeModule, GuiAutoCompleteDelCmd);
    SET_HOOKER(_bridgeModule, GuiAutoCompleteClearAll);
    SET_HOOKER(_bridgeModule, GuiAddStatusBarMessage);
    SET_HOOKER(_bridgeModule, GuiUpdateSideBar);
    SET_HOOKER(_bridgeModule, GuiRepaintTableView);
    SET_HOOKER(_bridgeModule, GuiUpdatePatches);
    SET_HOOKER(_bridgeModule, GuiUpdateCallStack);
    SET_HOOKER(_bridgeModule, GuiUpdateSEHChain);
    SET_HOOKER(_bridgeModule, GuiLoadSourceFileEx);
    SET_HOOKER(_bridgeModule, GuiMenuSetIcon);
    SET_HOOKER(_bridgeModule, GuiMenuSetEntryIcon);
    SET_HOOKER(_bridgeModule, GuiMenuSetEntryChecked);
    SET_HOOKER(_bridgeModule, GuiMenuSetVisible);
    SET_HOOKER(_bridgeModule, GuiMenuSetEntryVisible);
    SET_HOOKER(_bridgeModule, GuiMenuSetName);
    SET_HOOKER(_bridgeModule, GuiMenuSetEntryName);
    SET_HOOKER(_bridgeModule, GuiMenuSetEntryHotkey);
    SET_HOOKER(_bridgeModule, GuiShowCpu);
    SET_HOOKER(_bridgeModule, GuiAddQWidgetTab);
    SET_HOOKER(_bridgeModule, GuiShowQWidgetTab);
    SET_HOOKER(_bridgeModule, GuiCloseQWidgetTab);
    SET_HOOKER(_bridgeModule, GuiExecuteOnGuiThread);
    SET_HOOKER(_bridgeModule, GuiUpdateTimeWastedCounter);
    SET_HOOKER(_bridgeModule, GuiSetGlobalNotes);
    SET_HOOKER(_bridgeModule, GuiGetGlobalNotes);
    SET_HOOKER(_bridgeModule, GuiSetDebuggeeNotes);
    SET_HOOKER(_bridgeModule, GuiGetDebuggeeNotes);
    SET_HOOKER(_bridgeModule, GuiDumpAtN);
    SET_HOOKER(_bridgeModule, GuiDisplayWarning);
    SET_HOOKER(_bridgeModule, GuiRegisterScriptLanguage);
    SET_HOOKER(_bridgeModule, GuiUnregisterScriptLanguage);
    SET_HOOKER(_bridgeModule, GuiUpdateArgumentWidget);
    SET_HOOKER(_bridgeModule, GuiFocusView);
    SET_HOOKER(_bridgeModule, GuiIsUpdateDisabled);
    SET_HOOKER(_bridgeModule, GuiUpdateEnable);
    SET_HOOKER(_bridgeModule, GuiUpdateDisable);
    SET_HOOKER(_bridgeModule, GuiLoadGraph);
    SET_HOOKER(_bridgeModule, GuiGraphAt);
    SET_HOOKER(_bridgeModule, GuiUpdateGraphView);
    SET_HOOKER(_bridgeModule, GuiDisableLog);
    SET_HOOKER(_bridgeModule, GuiEnableLog);
    SET_HOOKER(_bridgeModule, GuiAddFavouriteTool);
    SET_HOOKER(_bridgeModule, GuiAddFavouriteCommand);
    SET_HOOKER(_bridgeModule, GuiSetFavouriteToolShortcut);
    SET_HOOKER(_bridgeModule, GuiFoldDisassembly);
    SET_HOOKER(_bridgeModule, GuiSelectInMemoryMap);
    SET_HOOKER(_bridgeModule, GuiGetActiveView);
    SET_HOOKER(_bridgeModule, GuiAddInfoLine);
    SET_HOOKER(_bridgeModule, GuiProcessEvents);
    SET_HOOKER(_bridgeModule, GuiTypeAddNode);
    SET_HOOKER(_bridgeModule, GuiTypeClear);
    SET_HOOKER(_bridgeModule, GuiUpdateTypeWidget);
    SET_HOOKER(_bridgeModule, GuiCloseApplication);
    SET_HOOKER(_bridgeModule, GuiFlushLog);
    SET_HOOKER(_bridgeModule, GuiReferenceAddCommand);
    SET_HOOKER(_bridgeModule, GuiUpdateTraceBrowser);
    SET_HOOKER(_bridgeModule, GuiOpenTraceFile);
    SET_HOOKER(_bridgeModule, GuiInvalidateSymbolSource);
    SET_HOOKER(_bridgeModule, GuiExecuteOnGuiThreadEx);
    SET_HOOKER(_bridgeModule, GuiGetCurrentGraph);
    SET_HOOKER(_bridgeModule, GuiShowReferences);
    SET_HOOKER(_bridgeModule, GuiSelectInSymbolsTab);
    SET_HOOKER(_bridgeModule, GuiGotoTrace);
    SET_HOOKER(_bridgeModule, GuiShowTrace);
    SET_HOOKER(_bridgeModule, GuiGetMainThreadId);
}

#define GET_ADDRESS(MODULE, NAME) \
    *((FARPROC*)&_##NAME) = GetProcAddress(MODULE, #NAME); \
    if (!_##NAME) \
    { \
        puts("Export " #NAME " could not be found!"); \
        return false; \
    }

bool Bridge::Init()
{
    _lastLogTime = GetTickCount();
    _bridgeModule = LoadLibraryA(BRIDGE_LIB_NAME);
    if (!_bridgeModule)
    {
        puts("Error loading library " BRIDGE_LIB_NAME);
        return false;
    }
    GET_ADDRESS(_bridgeModule, BridgeInit);
    GET_ADDRESS(_bridgeModule, DbgInit);
    GET_ADDRESS(_bridgeModule, DbgCmdExec);
    GET_ADDRESS(_bridgeModule, DbgExit);

    _dbgModule = LoadLibraryA(DBG_LIB_NAME);
    if (!_dbgModule)
    {
        puts("Error loading library " DBG_LIB_NAME);
        return false;
    }
    GET_ADDRESS(_dbgModule, _dbg_sendmessage);

    _HookAllGui();
    _BridgeInit();
    __dbg_sendmessage(DBG_INITIALIZE_LOCKS, nullptr, nullptr);
    _DbgInit();

    return true;
}

void Bridge::AutoCompleteAdd(const char* command)
{
    size_t pos = 0;
    std::string s(command);
    while ((pos = s.find(",")) != std::string::npos) {
        std::string token = s.substr(0, pos);
        _commands.push_back(token);
        s.erase(0, pos + 1);
    }
}

void Bridge::AddLogMessage(const char* msg)
{
    printf(msg);
    _lastLogTime = GetTickCount();
}

Bridge::~Bridge()
{
    _DbgExit();
    __dbg_sendmessage(DBG_DEINITIALIZE_LOCKS, nullptr, nullptr);
    FreeLibrary(_bridgeModule);
    FreeLibrary(_dbgModule);
}

Bridge* Bridge::instance = nullptr;
Bridge* Bridge::GetInstance()
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
