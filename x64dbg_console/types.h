#pragma once

#ifdef _WIN64
typedef unsigned long long   duint;
typedef signed long long     dsint;
#else
typedef unsigned long        duint;
typedef signed long          dsint;
#endif //_WIN64

typedef enum
{
    initialized,
    paused,
    running,
    stopped
} DBGSTATE;

typedef enum
{
    GUI_DISASSEMBLY,
    GUI_DUMP,
    GUI_STACK,
    GUI_GRAPH,
    GUI_MEMMAP,
    GUI_SYMMOD,
} GUISELECTIONTYPE;

typedef struct
{
    duint start;
    duint end;
} SELECTIONDATA;

#define MAX_MODULE_SIZE    256
typedef struct
{
    duint base;
    char  name[MAX_MODULE_SIZE];
} SYMBOLMODULEINFO;

typedef struct
{
    const void* data;
    duint       size;
} ICONDATA;

typedef void (*GUICALLBACK)();
typedef void (*GUICALLBACKEX)(void*);
typedef bool (*GUISCRIPTEXECUTE)(const char* text);
typedef void (*GUISCRIPTCOMPLETER)(const char* text, char** entries, int* entryCount);
typedef bool (*TYPETOSTRING)(const struct _TYPEDESCRIPTOR* type, char* dest, size_t* destCount); //don't change destCount for final failure

typedef struct
{
    char               name[64];
    int                id;
    GUISCRIPTEXECUTE   execute;
    GUISCRIPTCOMPLETER completeCommand;
} SCRIPTTYPEINFO;

typedef struct
{
    int    count; //Number of element in the list.
    size_t size;  //Size of list in bytes (used for type checking).
    void* data;  //Pointer to the list contents. Must be deleted by the caller using BridgeFree (or BridgeList::Free).
} ListInfo;

typedef struct
{
    duint    entryPoint; //graph entry point
    void* userdata;   //user data
    ListInfo nodes;      //graph nodes (BridgeCFNodeList)
} BridgeCFGraphList;

#define MAX_STRING_SIZE    512

typedef struct
{
    void* titleHwnd;
    void* classHwnd;
    char  title[MAX_STRING_SIZE];
    char  className[MAX_STRING_SIZE];
} ACTIVEVIEW;

typedef struct _TYPEDESCRIPTOR
{
    bool         expanded; //is the type node expanded?
    bool         reverse;  //big endian?
    const char* name;     //type name (int b)
    duint        addr;     //virtual address
    duint        offset;   //offset to addr for the actual location
    int          id;       //type id
    int          size;     //sizeof(type)
    TYPETOSTRING callback; //convert to string
    void* userdata; //user data
} TYPEDESCRIPTOR;

typedef enum
{
    DBG_SCRIPT_LOAD,                // param1=const char* filename,      param2=unused
    DBG_SCRIPT_UNLOAD,              // param1=unused,                    param2=unused
    DBG_SCRIPT_RUN,                 // param1=int destline,              param2=unused
    DBG_SCRIPT_STEP,                // param1=unused,                    param2=unused
    DBG_SCRIPT_BPTOGGLE,            // param1=int line,                  param2=unused
    DBG_SCRIPT_BPGET,               // param1=int line,                  param2=unused
    DBG_SCRIPT_CMDEXEC,             // param1=const char* command,       param2=unused
    DBG_SCRIPT_ABORT,               // param1=unused,                    param2=unused
    DBG_SCRIPT_GETLINETYPE,         // param1=int line,                  param2=unused
    DBG_SCRIPT_SETIP,               // param1=int line,                  param2=unused
    DBG_SCRIPT_GETBRANCHINFO,       // param1=int line,                  param2=SCRIPTBRANCH* info
    DBG_SYMBOL_ENUM,                // param1=SYMBOLCBINFO* cbInfo,      param2=unused
    DBG_ASSEMBLE_AT,                // param1=duint addr,                param2=const char* instruction
    DBG_MODBASE_FROM_NAME,          // param1=const char* modname,       param2=unused
    DBG_DISASM_AT,                  // param1=duint addr,                 param2=DISASM_INSTR* instr
    DBG_STACK_COMMENT_GET,          // param1=duint addr,                param2=STACK_COMMENT* comment
    DBG_GET_THREAD_LIST,            // param1=THREADALLINFO* list,       param2=unused
    DBG_SETTINGS_UPDATED,           // param1=unused,                    param2=unused
    DBG_DISASM_FAST_AT,             // param1=duint addr,                param2=BASIC_INSTRUCTION_INFO* basicinfo
    DBG_MENU_ENTRY_CLICKED,         // param1=int hEntry,                param2=unused
    DBG_FUNCTION_GET,               // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_FUNCTION_OVERLAPS,          // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_FUNCTION_ADD,               // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_FUNCTION_DEL,               // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_LOOP_GET,                   // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_LOOP_OVERLAPS,              // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_LOOP_ADD,                   // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_LOOP_DEL,                   // param1=FUNCTION_LOOP_INFO* info,  param2=unused
    DBG_IS_RUN_LOCKED,              // param1=unused,                    param2=unused
    DBG_IS_BP_DISABLED,             // param1=duint addr,                param2=unused
    DBG_SET_AUTO_COMMENT_AT,        // param1=duint addr,                param2=const char* text
    DBG_DELETE_AUTO_COMMENT_RANGE,  // param1=duint start,               param2=duint end
    DBG_SET_AUTO_LABEL_AT,          // param1=duint addr,                param2=const char* text
    DBG_DELETE_AUTO_LABEL_RANGE,    // param1=duint start,               param2=duint end
    DBG_SET_AUTO_BOOKMARK_AT,       // param1=duint addr,                param2=const char* text
    DBG_DELETE_AUTO_BOOKMARK_RANGE, // param1=duint start,               param2=duint end
    DBG_SET_AUTO_FUNCTION_AT,       // param1=duint addr,                param2=const char* text
    DBG_DELETE_AUTO_FUNCTION_RANGE, // param1=duint start,               param2=duint end
    DBG_GET_STRING_AT,              // param1=duint addr,                param2=unused
    DBG_GET_FUNCTIONS,              // param1=unused,                    param2=unused
    DBG_WIN_EVENT,                  // param1=MSG* message,              param2=long* result
    DBG_WIN_EVENT_GLOBAL,           // param1=MSG* message,              param2=unused
    DBG_INITIALIZE_LOCKS,           // param1=unused,                    param2=unused
    DBG_DEINITIALIZE_LOCKS,         // param1=unused,                    param2=unused
    DBG_GET_TIME_WASTED_COUNTER,    // param1=unused,                    param2=unused
    DBG_SYMBOL_ENUM_FROMCACHE,      // param1=SYMBOLCBINFO* cbInfo,      param2=unused
    DBG_DELETE_COMMENT_RANGE,       // param1=duint start,               param2=duint end
    DBG_DELETE_LABEL_RANGE,         // param1=duint start,               param2=duint end
    DBG_DELETE_BOOKMARK_RANGE,      // param1=duint start,               param2=duint end
    DBG_GET_XREF_COUNT_AT,          // param1=duint addr,                param2=unused
    DBG_GET_XREF_TYPE_AT,           // param1=duint addr,                param2=unused
    DBG_XREF_ADD,                   // param1=duint addr,                param2=duint from
    DBG_XREF_DEL_ALL,               // param1=duint addr,                param2=unused
    DBG_XREF_GET,                   // param1=duint addr,                param2=XREF_INFO* info
    DBG_GET_ENCODE_TYPE_BUFFER,     // param1=duint addr,                param2=unused
    DBG_ENCODE_TYPE_GET,            // param1=duint addr,                param2=duint size
    DBG_DELETE_ENCODE_TYPE_RANGE,   // param1=duint start,               param2=duint end
    DBG_ENCODE_SIZE_GET,            // param1=duint addr,                param2=duint codesize
    DBG_DELETE_ENCODE_TYPE_SEG,     // param1=duint addr,                param2=unused
    DBG_RELEASE_ENCODE_TYPE_BUFFER, // param1=void* buffer,              param2=unused
    DBG_ARGUMENT_GET,               // param1=FUNCTION* info,            param2=unused
    DBG_ARGUMENT_OVERLAPS,          // param1=FUNCTION* info,            param2=unused
    DBG_ARGUMENT_ADD,               // param1=FUNCTION* info,            param2=unused
    DBG_ARGUMENT_DEL,               // param1=FUNCTION* info,            param2=unused
    DBG_GET_WATCH_LIST,             // param1=ListOf(WATCHINFO),         param2=unused
    DBG_SELCHANGED,                 // param1=hWindow,                   param2=VA
    DBG_GET_PROCESS_HANDLE,         // param1=unused,                    param2=unused
    DBG_GET_THREAD_HANDLE,          // param1=unused,                    param2=unused
    DBG_GET_PROCESS_ID,             // param1=unused,                    param2=unused
    DBG_GET_THREAD_ID,              // param1=unused,                    param2=unused
    DBG_GET_PEB_ADDRESS,            // param1=DWORD ProcessId,           param2=unused
    DBG_GET_TEB_ADDRESS,            // param1=DWORD ThreadId,            param2=unused
    DBG_ANALYZE_FUNCTION,           // param1=BridgeCFGraphList* graph,  param2=duint entry
    DBG_MENU_PREPARE,               // param1=int hMenu,                 param2=unused
    DBG_GET_SYMBOL_INFO,            // param1=void* symbol,              param2=SYMBOLINFO* info
    DBG_GET_DEBUG_ENGINE,           // param1=unused,                    param2-unused
} DBGMSG;

typedef struct
{
    int         row;
    int         col;
    const char* str;
} CELLINFO;

//Gui enums
typedef enum
{
    GUI_DISASSEMBLE_AT,              // param1=(duint)va,            param2=(duint)cip
    GUI_SET_DEBUG_STATE,             // param1=(DBGSTATE)state,      param2=unused
    GUI_ADD_MSG_TO_LOG,              // param1=(const char*)msg,     param2=unused
    GUI_CLEAR_LOG,                   // param1=unused,               param2=unused
    GUI_UPDATE_REGISTER_VIEW,        // param1=unused,               param2=unused
    GUI_UPDATE_DISASSEMBLY_VIEW,     // param1=unused,               param2=unused
    GUI_UPDATE_BREAKPOINTS_VIEW,     // param1=unused,               param2=unused
    GUI_UPDATE_WINDOW_TITLE,         // param1=(const char*)file,    param2=unused
    GUI_GET_WINDOW_HANDLE,           // param1=unused,               param2=unused
    GUI_DUMP_AT,                     // param1=(duint)va             param2=unused
    GUI_SCRIPT_ADD,                  // param1=int count,            param2=const char** lines
    GUI_SCRIPT_CLEAR,                // param1=unused,               param2=unused
    GUI_SCRIPT_SETIP,                // param1=int line,             param2=unused
    GUI_SCRIPT_ERROR,                // param1=int line,             param2=const char* message
    GUI_SCRIPT_SETTITLE,             // param1=const char* title,    param2=unused
    GUI_SCRIPT_SETINFOLINE,          // param1=int line,             param2=const char* info
    GUI_SCRIPT_MESSAGE,              // param1=const char* message,  param2=unused
    GUI_SCRIPT_MSGYN,                // param1=const char* message,  param2=unused
    GUI_SYMBOL_LOG_ADD,              // param1(const char*)msg,      param2=unused
    GUI_SYMBOL_LOG_CLEAR,            // param1=unused,               param2=unused
    GUI_SYMBOL_SET_PROGRESS,         // param1=int percent           param2=unused
    GUI_SYMBOL_UPDATE_MODULE_LIST,   // param1=int count,            param2=SYMBOLMODULEINFO* modules
    GUI_REF_ADDCOLUMN,               // param1=int width,            param2=(const char*)title
    GUI_REF_SETROWCOUNT,             // param1=int rows,             param2=unused
    GUI_REF_GETROWCOUNT,             // param1=unused,               param2=unused
    GUI_REF_DELETEALLCOLUMNS,        // param1=unused,               param2=unused
    GUI_REF_SETCELLCONTENT,          // param1=(CELLINFO*)info,      param2=unused
    GUI_REF_GETCELLCONTENT,          // param1=int row,              param2=int col
    GUI_REF_RELOADDATA,              // param1=unused,               param2=unused
    GUI_REF_SETSINGLESELECTION,      // param1=int index,            param2=bool scroll
    GUI_REF_SETPROGRESS,             // param1=int progress,         param2=unused
    GUI_REF_SETCURRENTTASKPROGRESS,  // param1=int progress,         param2=const char* taskTitle
    GUI_REF_SETSEARCHSTARTCOL,       // param1=int col               param2=unused
    GUI_STACK_DUMP_AT,               // param1=duint addr,           param2=duint csp
    GUI_UPDATE_DUMP_VIEW,            // param1=unused,               param2=unused
    GUI_UPDATE_THREAD_VIEW,          // param1=unused,               param2=unused
    GUI_ADD_RECENT_FILE,             // param1=(const char*)file,    param2=unused
    GUI_SET_LAST_EXCEPTION,          // param1=unsigned int code,    param2=unused
    GUI_GET_DISASSEMBLY,             // param1=duint addr,           param2=char* text
    GUI_MENU_ADD,                    // param1=int hMenu,            param2=const char* title
    GUI_MENU_ADD_ENTRY,              // param1=int hMenu,            param2=const char* title
    GUI_MENU_ADD_SEPARATOR,          // param1=int hMenu,            param2=unused
    GUI_MENU_CLEAR,                  // param1=int hMenu,            param2=unused
    GUI_SELECTION_GET,               // param1=GUISELECTIONTYPE,     param2=SELECTIONDATA* selection
    GUI_SELECTION_SET,               // param1=GUISELECTIONTYPE,     param2=const SELECTIONDATA* selection
    GUI_GETLINE_WINDOW,              // param1=const char* title,    param2=char* text
    GUI_AUTOCOMPLETE_ADDCMD,         // param1=const char* cmd,      param2=ununsed
    GUI_AUTOCOMPLETE_DELCMD,         // param1=const char* cmd,      param2=ununsed
    GUI_AUTOCOMPLETE_CLEARALL,       // param1=unused,               param2=unused
    GUI_SCRIPT_ENABLEHIGHLIGHTING,   // param1=bool enable,          param2=unused
    GUI_ADD_MSG_TO_STATUSBAR,        // param1=const char* msg,      param2=unused
    GUI_UPDATE_SIDEBAR,              // param1=unused,               param2=unused
    GUI_REPAINT_TABLE_VIEW,          // param1=unused,               param2=unused
    GUI_UPDATE_PATCHES,              // param1=unused,               param2=unused
    GUI_UPDATE_CALLSTACK,            // param1=unused,               param2=unused
    GUI_UPDATE_SEHCHAIN,             // param1=unused,               param2=unused
    GUI_SYMBOL_REFRESH_CURRENT,      // param1=unused,               param2=unused
    GUI_UPDATE_MEMORY_VIEW,          // param1=unused,               param2=unused
    GUI_REF_INITIALIZE,              // param1=const char* name,     param2=unused
    GUI_LOAD_SOURCE_FILE,            // param1=const char* path,     param2=duint addr
    GUI_MENU_SET_ICON,               // param1=int hMenu,            param2=ICONINFO*
    GUI_MENU_SET_ENTRY_ICON,         // param1=int hEntry,           param2=ICONINFO*
    GUI_SHOW_CPU,                    // param1=unused,               param2=unused
    GUI_ADD_QWIDGET_TAB,             // param1=QWidget*,             param2=unused
    GUI_SHOW_QWIDGET_TAB,            // param1=QWidget*,             param2=unused
    GUI_CLOSE_QWIDGET_TAB,           // param1=QWidget*,             param2=unused
    GUI_EXECUTE_ON_GUI_THREAD,       // param1=GUICALLBACKEX cb,     param2=void* userdata
    GUI_UPDATE_TIME_WASTED_COUNTER,  // param1=unused,               param2=unused
    GUI_SET_GLOBAL_NOTES,            // param1=const char* text,     param2=unused
    GUI_GET_GLOBAL_NOTES,            // param1=char** text,          param2=unused
    GUI_SET_DEBUGGEE_NOTES,          // param1=const char* text,     param2=unused
    GUI_GET_DEBUGGEE_NOTES,          // param1=char** text,          param2=unused
    GUI_DUMP_AT_N,                   // param1=int index,            param2=duint va
    GUI_DISPLAY_WARNING,             // param1=const char *text,     param2=unused
    GUI_REGISTER_SCRIPT_LANG,        // param1=SCRIPTTYPEINFO* info, param2=unused
    GUI_UNREGISTER_SCRIPT_LANG,      // param1=int id,               param2=unused
    GUI_UPDATE_ARGUMENT_VIEW,        // param1=unused,               param2=unused
    GUI_FOCUS_VIEW,                  // param1=int hWindow,          param2=unused
    GUI_UPDATE_WATCH_VIEW,           // param1=unused,               param2=unused
    GUI_LOAD_GRAPH,                  // param1=BridgeCFGraphList*    param2=unused
    GUI_GRAPH_AT,                    // param1=duint addr            param2=unused
    GUI_UPDATE_GRAPH_VIEW,           // param1=unused,               param2=unused
    GUI_SET_LOG_ENABLED,             // param1=bool isEnabled        param2=unused
    GUI_ADD_FAVOURITE_TOOL,          // param1=const char* name      param2=const char* description
    GUI_ADD_FAVOURITE_COMMAND,       // param1=const char* command   param2=const char* shortcut
    GUI_SET_FAVOURITE_TOOL_SHORTCUT, // param1=const char* name      param2=const char* shortcut
    GUI_FOLD_DISASSEMBLY,            // param1=duint startAddress    param2=duint length
    GUI_SELECT_IN_MEMORY_MAP,        // param1=duint addr,           param2=unused
    GUI_GET_ACTIVE_VIEW,             // param1=ACTIVEVIEW*,          param2=unused
    GUI_MENU_SET_ENTRY_CHECKED,      // param1=int hEntry,           param2=bool checked
    GUI_ADD_INFO_LINE,               // param1=const char* infoline, param2=unused
    GUI_PROCESS_EVENTS,              // param1=unused,               param2=unused
    GUI_TYPE_ADDNODE,                // param1=void* parent,         param2=TYPEDESCRIPTOR* type
    GUI_TYPE_CLEAR,                  // param1=unused,               param2=unused
    GUI_UPDATE_TYPE_WIDGET,          // param1=unused,               param2=unused
    GUI_CLOSE_APPLICATION,           // param1=unused,               param2=unused
    GUI_MENU_SET_VISIBLE,            // param1=int hMenu,            param2=bool visible
    GUI_MENU_SET_ENTRY_VISIBLE,      // param1=int hEntry,           param2=bool visible
    GUI_MENU_SET_NAME,               // param1=int hMenu,            param2=const char* name
    GUI_MENU_SET_ENTRY_NAME,         // param1=int hEntry,           param2=const char* name
    GUI_FLUSH_LOG,                   // param1=unused,               param2=unused
    GUI_MENU_SET_ENTRY_HOTKEY,       // param1=int hEntry,           param2=const char* hack
    GUI_REF_SEARCH_GETROWCOUNT,      // param1=unused,               param2=unused
    GUI_REF_SEARCH_GETCELLCONTENT,   // param1=int row,              param2=int col
    GUI_MENU_REMOVE,                 // param1=int hEntryMenu,       param2=unused
    GUI_REF_ADDCOMMAND,              // param1=const char* title,    param2=const char* command
    GUI_OPEN_TRACE_FILE,             // param1=const char* file name,param2=unused
    GUI_UPDATE_TRACE_BROWSER,        // param1=unused,               param2=unused
    GUI_INVALIDATE_SYMBOL_SOURCE,    // param1=duint base,           param2=unused
    GUI_GET_CURRENT_GRAPH,           // param1=BridgeCFGraphList*,   param2=unused
    GUI_SHOW_REF,                    // param1=unused,               param2=unused
    GUI_SELECT_IN_SYMBOLS_TAB,       // param1=duint addr,           param2=unused
    GUI_GOTO_TRACE,                  // param1=duint index,          param2=unused
    GUI_SHOW_TRACE,                  // param1=unused,               param2=unused
    GUI_GET_MAIN_THREAD_ID,          // param1=unused,               param2=unused
    GUI_ADD_MSG_TO_LOG_HTML,         // param1=(const char*)msg,     param2=unused
} GUIMSG;

// BRIDGE typedefs
typedef const wchar_t* (*BRIDGEINIT)();
typedef const wchar_t* (*BRIDGESTART)();
typedef bool (*DBGDBGCMDEXEC)(const char* command);
typedef const char(*DBGINIT)();

// DBG typedefs
typedef duint(*DBGSENDMESSAGE)(DBGMSG type, void* param1, void* param2);


#ifdef _DEBUG
#define Log(fmt, ...)    Printf("[LOG] " fmt, __VA_ARGS__);
#define LogFunctionName    Log("*** " __FUNCTION__ " ***\n");
#else
#define LogFunctionName
#define Log(fmt, ...)
#endif // ifdef _DEBUG