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
    puts(msg);
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
    return true;
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

void Bridge::HookAllGui()
{
    SET_HOOKER(bridgeModule, GuiTranslateText);
    SET_HOOKER(bridgeModule, GuiDisasmAt);
    SET_HOOKER(bridgeModule, GuiSetDebugState);
    SET_HOOKER(bridgeModule, GuiSetDebugStateFast);
    SET_HOOKER(bridgeModule, GuiAddLogMessage);
    SET_HOOKER(bridgeModule, GuiAddLogMessageHtml);
    SET_HOOKER(bridgeModule, GuiLogClear);
    SET_HOOKER(bridgeModule, GuiUpdateAllViews);
    SET_HOOKER(bridgeModule, GuiUpdateRegisterView);
    SET_HOOKER(bridgeModule, GuiUpdateDisassemblyView);
    SET_HOOKER(bridgeModule, GuiUpdateBreakpointsView);
    SET_HOOKER(bridgeModule, GuiUpdateWindowTitle);
    SET_HOOKER(bridgeModule, GuiGetWindowHandle);
    SET_HOOKER(bridgeModule, GuiDumpAt);
    SET_HOOKER(bridgeModule, GuiScriptAdd);
    SET_HOOKER(bridgeModule, GuiScriptClear);
    SET_HOOKER(bridgeModule, GuiScriptSetIp);
    SET_HOOKER(bridgeModule, GuiScriptError);
    SET_HOOKER(bridgeModule, GuiScriptSetTitle);
    SET_HOOKER(bridgeModule, GuiScriptSetInfoLine);
    SET_HOOKER(bridgeModule, GuiScriptMessage);
    SET_HOOKER(bridgeModule, GuiScriptMsgyn);
    SET_HOOKER(bridgeModule, GuiScriptEnableHighlighting);
    SET_HOOKER(bridgeModule, GuiSymbolLogAdd);
    SET_HOOKER(bridgeModule, GuiSymbolLogClear);
    SET_HOOKER(bridgeModule, GuiSymbolSetProgress);
    SET_HOOKER(bridgeModule, GuiSymbolUpdateModuleList);
    SET_HOOKER(bridgeModule, GuiSymbolRefreshCurrent);
    SET_HOOKER(bridgeModule, GuiReferenceAddColumn);
    SET_HOOKER(bridgeModule, GuiReferenceSetRowCount);
    SET_HOOKER(bridgeModule, GuiReferenceGetRowCount);
    SET_HOOKER(bridgeModule, GuiReferenceSearchGetRowCount);
    SET_HOOKER(bridgeModule, GuiReferenceDeleteAllColumns);
    SET_HOOKER(bridgeModule, GuiReferenceInitialize);
    SET_HOOKER(bridgeModule, GuiReferenceSetCellContent);
    SET_HOOKER(bridgeModule, GuiReferenceGetCellContent);
    SET_HOOKER(bridgeModule, GuiReferenceSearchGetCellContent);
    SET_HOOKER(bridgeModule, GuiReferenceReloadData);
    SET_HOOKER(bridgeModule, GuiReferenceSetSingleSelection);
    SET_HOOKER(bridgeModule, GuiReferenceSetProgress);
    SET_HOOKER(bridgeModule, GuiReferenceSetCurrentTaskProgress);
    SET_HOOKER(bridgeModule, GuiReferenceSetSearchStartCol);
    SET_HOOKER(bridgeModule, GuiStackDumpAt);
    SET_HOOKER(bridgeModule, GuiUpdateDumpView);
    SET_HOOKER(bridgeModule, GuiUpdateWatchView);
    SET_HOOKER(bridgeModule, GuiUpdateThreadView);
    SET_HOOKER(bridgeModule, GuiUpdateMemoryView);
    SET_HOOKER(bridgeModule, GuiAddRecentFile);
    SET_HOOKER(bridgeModule, GuiSetLastException);
    SET_HOOKER(bridgeModule, GuiGetDisassembly);
    SET_HOOKER(bridgeModule, GuiMenuAdd);
    SET_HOOKER(bridgeModule, GuiMenuAddEntry);
    SET_HOOKER(bridgeModule, GuiMenuAddSeparator);
    SET_HOOKER(bridgeModule, GuiMenuClear);
    SET_HOOKER(bridgeModule, GuiMenuRemove);
    SET_HOOKER(bridgeModule, GuiSelectionGet);
    SET_HOOKER(bridgeModule, GuiSelectionSet);
    SET_HOOKER(bridgeModule, GuiGetLineWindow);
    SET_HOOKER(bridgeModule, GuiAutoCompleteAddCmd);
    SET_HOOKER(bridgeModule, GuiAutoCompleteDelCmd);
    SET_HOOKER(bridgeModule, GuiAutoCompleteClearAll);
    SET_HOOKER(bridgeModule, GuiAddStatusBarMessage);
    SET_HOOKER(bridgeModule, GuiUpdateSideBar);
    SET_HOOKER(bridgeModule, GuiRepaintTableView);
    SET_HOOKER(bridgeModule, GuiUpdatePatches);
    SET_HOOKER(bridgeModule, GuiUpdateCallStack);
    SET_HOOKER(bridgeModule, GuiUpdateSEHChain);
    SET_HOOKER(bridgeModule, GuiLoadSourceFileEx);
    SET_HOOKER(bridgeModule, GuiMenuSetIcon);
    SET_HOOKER(bridgeModule, GuiMenuSetEntryIcon);
    SET_HOOKER(bridgeModule, GuiMenuSetEntryChecked);
    SET_HOOKER(bridgeModule, GuiMenuSetVisible);
    SET_HOOKER(bridgeModule, GuiMenuSetEntryVisible);
    SET_HOOKER(bridgeModule, GuiMenuSetName);
    SET_HOOKER(bridgeModule, GuiMenuSetEntryName);
    SET_HOOKER(bridgeModule, GuiMenuSetEntryHotkey);
    SET_HOOKER(bridgeModule, GuiShowCpu);
    SET_HOOKER(bridgeModule, GuiAddQWidgetTab);
    SET_HOOKER(bridgeModule, GuiShowQWidgetTab);
    SET_HOOKER(bridgeModule, GuiCloseQWidgetTab);
    SET_HOOKER(bridgeModule, GuiExecuteOnGuiThread);
    SET_HOOKER(bridgeModule, GuiUpdateTimeWastedCounter);
    SET_HOOKER(bridgeModule, GuiSetGlobalNotes);
    SET_HOOKER(bridgeModule, GuiGetGlobalNotes);
    SET_HOOKER(bridgeModule, GuiSetDebuggeeNotes);
    SET_HOOKER(bridgeModule, GuiGetDebuggeeNotes);
    SET_HOOKER(bridgeModule, GuiDumpAtN);
    SET_HOOKER(bridgeModule, GuiDisplayWarning);
    SET_HOOKER(bridgeModule, GuiRegisterScriptLanguage);
    SET_HOOKER(bridgeModule, GuiUnregisterScriptLanguage);
    SET_HOOKER(bridgeModule, GuiUpdateArgumentWidget);
    SET_HOOKER(bridgeModule, GuiFocusView);
    SET_HOOKER(bridgeModule, GuiIsUpdateDisabled);
    SET_HOOKER(bridgeModule, GuiUpdateEnable);
    SET_HOOKER(bridgeModule, GuiUpdateDisable);
    SET_HOOKER(bridgeModule, GuiLoadGraph);
    SET_HOOKER(bridgeModule, GuiGraphAt);
    SET_HOOKER(bridgeModule, GuiUpdateGraphView);
    SET_HOOKER(bridgeModule, GuiDisableLog);
    SET_HOOKER(bridgeModule, GuiEnableLog);
    SET_HOOKER(bridgeModule, GuiAddFavouriteTool);
    SET_HOOKER(bridgeModule, GuiAddFavouriteCommand);
    SET_HOOKER(bridgeModule, GuiSetFavouriteToolShortcut);
    SET_HOOKER(bridgeModule, GuiFoldDisassembly);
    SET_HOOKER(bridgeModule, GuiSelectInMemoryMap);
    SET_HOOKER(bridgeModule, GuiGetActiveView);
    SET_HOOKER(bridgeModule, GuiAddInfoLine);
    SET_HOOKER(bridgeModule, GuiProcessEvents);
    SET_HOOKER(bridgeModule, GuiTypeAddNode);
    SET_HOOKER(bridgeModule, GuiTypeClear);
    SET_HOOKER(bridgeModule, GuiUpdateTypeWidget);
    SET_HOOKER(bridgeModule, GuiCloseApplication);
    SET_HOOKER(bridgeModule, GuiFlushLog);
    SET_HOOKER(bridgeModule, GuiReferenceAddCommand);
    SET_HOOKER(bridgeModule, GuiUpdateTraceBrowser);
    SET_HOOKER(bridgeModule, GuiOpenTraceFile);
    SET_HOOKER(bridgeModule, GuiInvalidateSymbolSource);
    SET_HOOKER(bridgeModule, GuiExecuteOnGuiThreadEx);
    SET_HOOKER(bridgeModule, GuiGetCurrentGraph);
    SET_HOOKER(bridgeModule, GuiShowReferences);
    SET_HOOKER(bridgeModule, GuiSelectInSymbolsTab);
    SET_HOOKER(bridgeModule, GuiGotoTrace);
    SET_HOOKER(bridgeModule, GuiShowTrace);
    SET_HOOKER(bridgeModule, GuiGetMainThreadId);
}

#define GET_ADDRESS(MODULE, NAME) \
    *((FARPROC*)&NAME) = GetProcAddress(MODULE, #NAME); \
    if (!NAME) \
    { \
        puts("Export " #NAME " could not be found!"); \
        return; \
    }

Bridge::Bridge() : inited(false)
{
    bridgeModule = LoadLibraryA(BRIDGE_LIB_NAME);
    if (!bridgeModule)
    {
        puts("Error loading library " BRIDGE_LIB_NAME);
        return;
    }
    GET_ADDRESS(bridgeModule, BridgeInit);
    GET_ADDRESS(bridgeModule, DbgInit);
    GET_ADDRESS(bridgeModule, DbgCmdExec);
    GET_ADDRESS(bridgeModule, DbgExit);

    dbgModule = LoadLibraryA(DBG_LIB_NAME);
    if (!dbgModule)
    {
        puts("Error loading library " DBG_LIB_NAME);
        return;
    }
    GET_ADDRESS(dbgModule, _dbg_sendmessage);

    HookAllGui();
    BridgeInit();
    _dbg_sendmessage(DBG_INITIALIZE_LOCKS, nullptr, nullptr);
    DbgInit();

    autoCompleteConfigFp = open_memstream();
    inited = true;
}

Bridge::~Bridge()
{
    DbgExit();
    _dbg_sendmessage(DBG_DEINITIALIZE_LOCKS, nullptr, nullptr);
    FreeLibrary(bridgeModule);
    FreeLibrary(dbgModule);
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