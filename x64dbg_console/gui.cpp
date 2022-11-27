#include "gui.h"

#pragma warning( disable : 4311 4302 4312 )

const char * _gui_translate_text(const char *source)
{
    return Bridge::GetInstance()->GuiTranslateText(source);
}

void * _gui_sendmessage(GUIMSG type, void *param1, void *param2)
{
    void *result = nullptr;
    Bridge* bridge = Bridge::GetInstance();

    switch (type)
    {
    case GUI_DISASSEMBLE_AT: // param1=(duint)va,            param2=(duint)cip
        bridge->GuiDisasmAt((duint)param1, (duint)param2);
        break;

    case GUI_SET_DEBUG_STATE: // param1=(DBGSTATE)state,      param2=unused
        bridge->GuiSetDebugState((DBGSTATE)(dsint)param1);
        break;

    case GUI_ADD_MSG_TO_LOG: // param1=(const char*)msg,     param2=unused
        bridge->GuiAddLogMessage((const char *)param1);
        break;

    case GUI_CLEAR_LOG: // param1=unused,               param2=unused
        bridge->GuiLogClear();
        break;

    case GUI_UPDATE_REGISTER_VIEW: // param1=unused,               param2=unused
        bridge->GuiUpdateRegisterView();
        break;

    case GUI_UPDATE_DISASSEMBLY_VIEW: // param1=unused,               param2=unused
        bridge->GuiUpdateDisassemblyView();
        break;

    case GUI_UPDATE_BREAKPOINTS_VIEW: // param1=unused,               param2=unused
        bridge->GuiUpdateBreakpointsView();
        break;

    case GUI_UPDATE_WINDOW_TITLE: // param1=(const char*)file,    param2=unused
        bridge->GuiUpdateWindowTitle((const char *)param1);
        break;

    case GUI_GET_WINDOW_HANDLE: // param1=unused,               param2=unused
        result = (void *)bridge->GuiGetWindowHandle();
        break;

    case GUI_DUMP_AT: // param1=(duint)va             param2=unused
        bridge->GuiDumpAt((duint)param1);
        break;

    case GUI_SCRIPT_ADD: // param1=int count,            param2=const char** lines
        bridge->GuiScriptAdd((int)param1, (const char **)param2);
        break;

    case GUI_SCRIPT_CLEAR: // param1=unused,               param2=unused
        bridge->GuiScriptClear();
        break;

    case GUI_SCRIPT_SETIP: // param1=int line,             param2=unused
        bridge->GuiScriptSetIp((int)param1);
        break;

    case GUI_SCRIPT_ERROR: // param1=int line,             param2=const char* message
        bridge->GuiScriptError((int)param1, (const char *)param2);
        break;

    case GUI_SCRIPT_SETTITLE: // param1=const char* title,    param2=unused
        bridge->GuiScriptSetTitle((const char *)param1);
        break;

    case GUI_SCRIPT_SETINFOLINE: // param1=int line,             param2=const char* info
        bridge->GuiScriptSetInfoLine((int)param1, (const char *)param2);
        break;

    case GUI_SCRIPT_MESSAGE: // param1=const char* message,  param2=unused
        bridge->GuiScriptMessage((const char *)param1);
        break;

    case GUI_SCRIPT_MSGYN: // param1=const char* message,  param2=unused
        result = (void *)bridge->GuiScriptMsgyn((const char *)param1);
        break;

    case GUI_SYMBOL_LOG_ADD: // param1(const char*)msg,      param2=unused
        bridge->GuiSymbolLogAdd((const char *)param1);
        break;

    case GUI_SYMBOL_LOG_CLEAR: // param1=unused,               param2=unused
        bridge->GuiSymbolLogClear();
        break;

    case GUI_SYMBOL_SET_PROGRESS: // param1=int percent           param2=unused
        bridge->GuiSymbolSetProgress((int)param1);
        break;

    case GUI_SYMBOL_UPDATE_MODULE_LIST: // param1=int count,            param2=SYMBOLMODULEINFO* modules
        bridge->GuiSymbolUpdateModuleList((int)param1, (SYMBOLMODULEINFO *)param2);
        break;

    case GUI_REF_ADDCOLUMN: // param1=int width,            param2=(const char*)title
        bridge->GuiReferenceAddColumn((int)param1, (const char *)param2);
        break;

    case GUI_REF_SETROWCOUNT: // param1=int rows,             param2=unused
        bridge->GuiReferenceSetRowCount((int)param1);
        break;

    case GUI_REF_GETROWCOUNT: // param1=unused,               param2=unused
        result = (void *)bridge->GuiReferenceGetRowCount();
        break;

    case GUI_REF_DELETEALLCOLUMNS: // param1=unused,               param2=unused
        bridge->GuiReferenceDeleteAllColumns();
        break;

    case GUI_REF_SETCELLCONTENT: // param1=(CELLINFO*)info,      param2=unused
    {
        CELLINFO *info = (CELLINFO *)param1;
        bridge->GuiReferenceSetCellContent(info->col, info->row, info->str);
        break;
    }

    case GUI_REF_GETCELLCONTENT: // param1=int row,              param2=int col
        result = bridge->GuiReferenceGetCellContent((int)param1, (int)param2);
        break;

    case GUI_REF_RELOADDATA: // param1=unused,               param2=unused
        bridge->GuiReferenceReloadData();
        break;

    case GUI_REF_SETSINGLESELECTION: // param1=int index,            param2=bool scroll
        bridge->GuiReferenceSetSingleSelection((int)param1, (bool)param2);
        break;

    case GUI_REF_SETPROGRESS: // param1=int progress,         param2=unused
        bridge->GuiReferenceSetProgress((int)param1);
        break;

    case GUI_REF_SETCURRENTTASKPROGRESS: // param1=int progress,         param2=const char* taskTitle
        bridge->GuiReferenceSetCurrentTaskProgress((int)param1, (const char *)param2);
        break;

    case GUI_REF_SETSEARCHSTARTCOL: // param1=int col               param2=unused
        bridge->GuiReferenceSetSearchStartCol((int)param1);
        break;

    case GUI_STACK_DUMP_AT: // param1=duint addr,           param2=duint csp
        bridge->GuiStackDumpAt((duint)param1, (duint)param2);
        break;

    case GUI_UPDATE_DUMP_VIEW: // param1=unused,               param2=unused
        bridge->GuiUpdateDumpView();
        break;

    case GUI_UPDATE_THREAD_VIEW: // param1=unused,               param2=unused
        bridge->GuiUpdateThreadView();
        break;

    case GUI_ADD_RECENT_FILE: // param1=(const char*)file,    param2=unused
        bridge->GuiAddRecentFile((const char *)param1);
        break;

    case GUI_SET_LAST_EXCEPTION: // param1=unsigned int code,    param2=unused
        bridge->GuiSetLastException((unsigned int)param1);
        break;

    case GUI_GET_DISASSEMBLY: // param1=duint addr,           param2=char* text
        result = (void *)bridge->GuiGetDisassembly((duint)param1, (char *)param2);
        break;

    case GUI_MENU_ADD: // param1=int hMenu,            param2=const char* title
        result = (void *)bridge->GuiMenuAdd((int)param1, (const char *)param2);
        break;

    case GUI_MENU_ADD_ENTRY: // param1=int hMenu,            param2=const char* title
        result = (void *)bridge->GuiMenuAddEntry((int)param1, (const char *)param2);
        break;

    case GUI_MENU_ADD_SEPARATOR: // param1=int hMenu,            param2=unused
        bridge->GuiMenuAddSeparator((int)param1);
        break;

    case GUI_MENU_CLEAR: // param1=int hMenu,            param2=unused
        bridge->GuiMenuClear((int)param1);
        break;

    case GUI_SELECTION_GET: // param1=GUISELECTIONTYPE,     param2=SELECTIONDATA* selection
        result = (void*)bridge->GuiSelectionGet(GUISELECTIONTYPE(duint(param1)), (SELECTIONDATA*)param2);
        break;

    case GUI_SELECTION_SET: // param1=GUISELECTIONTYPE,     param2=const SELECTIONDATA* selection
        result = (void*)bridge->GuiSelectionSet(GUISELECTIONTYPE(duint(param1)), (SELECTIONDATA*)param2);
        break;

    case GUI_GETLINE_WINDOW: // param1=const char* title,    param2=char* text
        result = (void*)bridge->GuiGetLineWindow((const char*)param1, (char*)param2);
        break;

    case GUI_AUTOCOMPLETE_ADDCMD: // param1=const char* cmd,      param2=ununsed
        bridge->GuiAutoCompleteAddCmd((const char*)param1);
        break;

    case GUI_AUTOCOMPLETE_DELCMD: // param1=const char* cmd,      param2=ununsed
        bridge->GuiAutoCompleteDelCmd((const char*)param1);
        break;

    case GUI_AUTOCOMPLETE_CLEARALL: // param1=unused,               param2=unused
        bridge->GuiAutoCompleteClearAll();
        break;

    case GUI_SCRIPT_ENABLEHIGHLIGHTING: // param1=bool enable,          param2=unused
        bridge->GuiScriptEnableHighlighting((bool)param1);
        break;

    case GUI_ADD_MSG_TO_STATUSBAR: // param1=const char* msg,      param2=unused
        bridge->GuiAddStatusBarMessage((const char*)param1);
        break;

    case GUI_UPDATE_SIDEBAR: // param1=unused,               param2=unused
        bridge->GuiUpdateSideBar();
        break;

    case GUI_REPAINT_TABLE_VIEW: // param1=unused,               param2=unused
        bridge->GuiRepaintTableView();
        break;

    case GUI_UPDATE_PATCHES: // param1=unused,               param2=unused
        bridge->GuiUpdatePatches();
        break;

    case GUI_UPDATE_CALLSTACK: // param1=unused,               param2=unused
        bridge->GuiUpdateCallStack();
        break;

    case GUI_UPDATE_SEHCHAIN: // param1=unused,               param2=unused
        bridge->GuiUpdateSEHChain();
        break;

    case GUI_SYMBOL_REFRESH_CURRENT: // param1=unused,               param2=unused
        bridge->GuiSymbolRefreshCurrent();
        break;

    case GUI_UPDATE_MEMORY_VIEW: // param1=unused,               param2=unused
        bridge->GuiUpdateMemoryView();
        break;

    case GUI_REF_INITIALIZE: // param1=const char* name,     param2=unused
        bridge->GuiReferenceInitialize((const char*)param1);
        break;

    case GUI_LOAD_SOURCE_FILE: // param1=const char* path,     param2=duint addr
        bridge->GuiLoadSourceFileEx((const char*)param1, (duint)param2);
        break;

    case GUI_MENU_SET_ICON: // param1=int hMenu,            param2=ICONINFO*
        bridge->GuiMenuSetIcon((int)param1, (const ICONDATA*)param2);
        break;

    case GUI_MENU_SET_ENTRY_ICON: // param1=int hEntry,           param2=ICONINFO*
        bridge->GuiMenuSetEntryIcon((int)param1, (const ICONDATA*)param2);
        break;

    case GUI_SHOW_CPU: // param1=unused,               param2=unused
        bridge->GuiShowCpu();
        break;

    case GUI_ADD_QWIDGET_TAB: // param1=QWidget*,             param2=unused
        bridge->GuiAddQWidgetTab(param1);
        break;

    case GUI_SHOW_QWIDGET_TAB: // param1=QWidget*,             param2=unused
        bridge->GuiShowQWidgetTab(param1);
        break;

    case GUI_CLOSE_QWIDGET_TAB: // param1=QWidget*,             param2=unused
        bridge->GuiCloseQWidgetTab(param1);
        break;

    case GUI_EXECUTE_ON_GUI_THREAD:      // param1=GUICALLBACKEX cb,     param2=void* userdata
        bridge->GuiExecuteOnGuiThreadEx((GUICALLBACKEX)param1, param2);
        break;

    case GUI_UPDATE_TIME_WASTED_COUNTER:     // param1=unused,               param2=unused
        bridge->GuiUpdateTimeWastedCounter();
        break;

    case GUI_SET_GLOBAL_NOTES:     // param1=const char* text,     param2=unused
        bridge->GuiSetGlobalNotes((const char*)param1);
        break;

    case GUI_GET_GLOBAL_NOTES:     // param1=char** text,          param2=unused
        bridge->GuiGetGlobalNotes((char**)param1);
        break;

    case GUI_SET_DEBUGGEE_NOTES:     // param1=const char* text,     param2=unused
        bridge->GuiSetDebuggeeNotes((char*)param1);
        break;

    case GUI_GET_DEBUGGEE_NOTES:     // param1=char** text,          param2=unused
        bridge->GuiGetDebuggeeNotes((char**)param1);
        break;

    case GUI_DUMP_AT_N:     // param1=int index,            param2=duint va
        bridge->GuiDumpAtN((int)param1, (int)param2);
        break;

    case GUI_DISPLAY_WARNING:     // param1=const char *text,     param2=unused
        bridge->GuiDisplayWarning((const char*)param1, (const char*)param2);
        break;

    case GUI_REGISTER_SCRIPT_LANG:     // param1=SCRIPTTYPEINFO* info, param2=unused
        bridge->GuiRegisterScriptLanguage((SCRIPTTYPEINFO*)param1);
        break;

    case GUI_UNREGISTER_SCRIPT_LANG:     // param1=int id,               param2=unused
        bridge->GuiUnregisterScriptLanguage((int)param1);
        break;

    case GUI_UPDATE_ARGUMENT_VIEW:     // param1=unused,               param2=unused
        bridge->GuiUpdateArgumentWidget();
        break;

    case GUI_FOCUS_VIEW:     // param1=int hWindow,          param2=unused
        bridge->GuiFocusView((int)param1);
        break;

    case GUI_UPDATE_WATCH_VIEW:     // param1=unused,               param2=unused
        bridge->GuiUpdateWatchView();
        break;

    case GUI_LOAD_GRAPH:     // param1=BridgeCFGraphList*    param2=unused
        result = (void*)bridge->GuiLoadGraph((BridgeCFGraphList*)param1, duint(param2));
        break;

    case GUI_GRAPH_AT:     // param1=duint addr            param2=unused
        result = (void*)bridge->GuiGraphAt(duint(param1));
        break;

    case GUI_UPDATE_GRAPH_VIEW:     // param1=unused,               param2=unused
        bridge->GuiUpdateGraphView();
        break;

    case GUI_SET_LOG_ENABLED:     // param1=bool isEnabled        param2=unused
        bridge->GuiDisableLog();
        break;

    case GUI_ADD_FAVOURITE_TOOL:     // param1=const char* name      param2=const char* description
        bridge->GuiAddFavouriteTool((const char*)param1, (const char*)param2);
        break;

    case GUI_ADD_FAVOURITE_COMMAND:     // param1=const char* command   param2=const char* shortcut
        bridge->GuiAddFavouriteCommand((const char*)param1, (const char*)param2);
        break;

    case GUI_SET_FAVOURITE_TOOL_SHORTCUT:     // param1=const char* name      param2=const char* shortcut
        bridge->GuiSetFavouriteToolShortcut((const char*)param1, (const char*)param2);
        break;

    case GUI_FOLD_DISASSEMBLY:     // param1=duint startAddress    param2=duint length
        bridge->GuiFoldDisassembly(duint(param1), duint(param2));
        break;

    case GUI_SELECT_IN_MEMORY_MAP:     // param1=duint addr,           param2=unused
        bridge->GuiSelectInMemoryMap((duint)param1);
        break;

    case GUI_GET_ACTIVE_VIEW:     // param1=ACTIVEVIEW*,          param2=unused
        bridge->GuiGetActiveView((ACTIVEVIEW*)param1);
        break;

    case GUI_MENU_SET_ENTRY_CHECKED:     // param1=int hEntry,           param2=bool checked
        bridge->GuiMenuSetEntryChecked(int(param1), bool(param2));
        break;

    case GUI_ADD_INFO_LINE:     // param1=const char* infoline, param2=unused
        bridge->GuiAddInfoLine((const char*)param1);
        break;

    case GUI_PROCESS_EVENTS:     // param1=unused,               param2=unused
        bridge->GuiProcessEvents();
        break;

    case GUI_TYPE_ADDNODE:     // param1=void* parent,         param2=TYPEDESCRIPTOR* type
        bridge->GuiTypeAddNode(param1, (TYPEDESCRIPTOR*)param2);
        break;

    case GUI_TYPE_CLEAR:     // param1=unused,               param2=unused
        bridge->GuiTypeClear();
        break;

    case GUI_UPDATE_TYPE_WIDGET:     // param1=unused,               param2=unused
        bridge->GuiUpdateTypeWidget();
        break;

    case GUI_CLOSE_APPLICATION:     // param1=unused,               param2=unused
        bridge->GuiCloseApplication();
        break;

    case GUI_MENU_SET_VISIBLE:     // param1=int hMenu,            param2=bool visible
        bridge->GuiMenuSetVisible((int)param1, (bool)param2);
        break;

    case GUI_MENU_SET_ENTRY_VISIBLE:     // param1=int hEntry,           param2=bool visible
        bridge->GuiMenuSetEntryVisible((int)param1, (bool)param2);
        break;

    case GUI_MENU_SET_NAME:     // param1=int hMenu,            param2=const char* name
        bridge->GuiMenuSetName((int)param1, (const char*)param2);
        break;

    case GUI_MENU_SET_ENTRY_NAME:     // param1=int hEntry,           param2=const char* name
        bridge->GuiMenuSetEntryName((int)param1, (const char*)param2);
        break;

    case GUI_FLUSH_LOG:     // param1=unused,               param2=unused
        bridge->GuiFlushLog();
        break;

    case GUI_MENU_SET_ENTRY_HOTKEY:     // param1=int hEntry,           param2=const char* hack
        bridge->GuiMenuSetEntryHotkey((int)param1, (const char*)param2);
        break;

    case GUI_REF_SEARCH_GETROWCOUNT:     // param1=unused,               param2=unused
        bridge->GuiReferenceSearchGetRowCount();
        break;

    case GUI_REF_SEARCH_GETCELLCONTENT:     // param1=int row,              param2=int col
        result = bridge->GuiReferenceSearchGetCellContent((int)param1, (int)param2);
        break;

    case GUI_MENU_REMOVE:     // param1=int hEntryMenu,       param2=unused
        bridge->GuiMenuRemove((int)param1);
        break;

    case GUI_REF_ADDCOMMAND:     // param1=const char* title,    param2=const char* command
        bridge->GuiReferenceAddCommand((const char*)param1, (const char*)param2);
        break;

    case GUI_OPEN_TRACE_FILE:     // param1=const char* file name,param2=unused
        bridge->GuiOpenTraceFile((const char*)param1);
        break;

    case GUI_UPDATE_TRACE_BROWSER:     // param1=unused,               param2=unused
        bridge->GuiUpdateTraceBrowser();
        break;

    case GUI_INVALIDATE_SYMBOL_SOURCE:     // param1=duint base,           param2=unused
        bridge->GuiInvalidateSymbolSource((duint)param1);
        break;

    case GUI_GET_CURRENT_GRAPH:     // param1=BridgeCFGraphList*,   param2=unused
        bridge->GuiGetCurrentGraph((BridgeCFGraphList*)param1);
        break;

    case GUI_SHOW_REF:     // param1=unused,               param2=unused
        bridge->GuiShowReferences();
        break;

    case GUI_SELECT_IN_SYMBOLS_TAB:     // param1=duint addr,           param2=unused
        bridge->GuiSelectInSymbolsTab((duint)param1);
        break;

    case GUI_GOTO_TRACE:     // param1=duint index,          param2=unused
        bridge->GuiGotoTrace((duint)param1);
        break;

    case GUI_SHOW_TRACE:     // param1=unused,               param2=unused
        bridge->GuiShowTrace();
        break;

    case GUI_GET_MAIN_THREAD_ID:     // param1=unused,               param2=unused
        result = (void*)bridge->GuiGetMainThreadId();
        break;

    case GUI_ADD_MSG_TO_LOG_HTML:     // param1=(const char*)msg,     param2=unused
        bridge->GuiAddLogMessageHtml((const char*)param1);
        break;

    default:
        break;
    }
    return(result);
}

int _gui_guiinit(int argc, char *argv[])
{
    return(0);
}

