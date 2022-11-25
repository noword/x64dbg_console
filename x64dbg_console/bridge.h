#pragma once
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <Windows.h>

#ifdef _WIN64
typedef unsigned long long duint;
typedef signed long long dsint;
#else
typedef unsigned long duint;
typedef signed long dsint;
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

#define MAX_MODULE_SIZE 256
typedef struct
{
    duint base;
    char name[MAX_MODULE_SIZE];
} SYMBOLMODULEINFO;

typedef struct
{
    const void* data;
    duint size;
} ICONDATA;

typedef void (*GUICALLBACK)();
typedef void (*GUICALLBACKEX)(void*);
typedef bool (*GUISCRIPTEXECUTE)(const char* text);
typedef void (*GUISCRIPTCOMPLETER)(const char* text, char** entries, int* entryCount);
typedef bool (*TYPETOSTRING)(const struct _TYPEDESCRIPTOR* type, char* dest, size_t* destCount); //don't change destCount for final failure

typedef struct
{
    char name[64];
    int id;
    GUISCRIPTEXECUTE execute;
    GUISCRIPTCOMPLETER completeCommand;
} SCRIPTTYPEINFO;

typedef struct
{
    int count; //Number of element in the list.
    size_t size; //Size of list in bytes (used for type checking).
    void* data; //Pointer to the list contents. Must be deleted by the caller using BridgeFree (or BridgeList::Free).
} ListInfo;

typedef struct
{
    duint entryPoint; //graph entry point
    void* userdata; //user data
    ListInfo nodes; //graph nodes (BridgeCFNodeList)
} BridgeCFGraphList;

#define MAX_STRING_SIZE 512

typedef struct
{
    void* titleHwnd;
    void* classHwnd;
    char title[MAX_STRING_SIZE];
    char className[MAX_STRING_SIZE];
} ACTIVEVIEW;

typedef struct _TYPEDESCRIPTOR
{
    bool expanded; //is the type node expanded?
    bool reverse; //big endian?
    const char* name; //type name (int b)
    duint addr; //virtual address
    duint offset; //offset to addr for the actual location
    int id; //type id
    int size; //sizeof(type)
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

#ifdef _WIN64
#define DBG_LIB_NAME "x64dbg.dll"
#define BRIDGE_LIB_NAME "x64bridge.dll"
#else
#define DBG_LIB_NAME "x32dbg.dll"
#define BRIDGE_LIB_NAME "x32bridge.dll"
#endif // ifdef _WIN64

typedef const wchar_t* (*BRIDGEINIT)();
typedef const char* (*DBGINIT)();
typedef bool (*DBGCMDEXEC)(const char* command);
typedef void (*DEBEXIT)();
typedef duint (*DBGSENDMESSAGE)(DBGMSG type, void* param1, void* param2);

class Bridge
{
public:
    static Bridge* GetInstance();
    static void FreeInstance();
    virtual ~Bridge();
    bool ExecCmd(const char* command) { return DbgCmdExec(command); };
    bool IsInited() { return inited; };
    void AutoCompleteAdd();

private:
    Bridge();
    Bridge(Bridge& other) {};
    Bridge& operator=(Bridge& other) {};
    static Bridge* instance;

    void HookAllGui();
    
    bool inited;
    FILE* autoCompleteConfigFp;
    char* autoCompleteConfig;

    HMODULE bridgeModule;
    HMODULE dbgModule;

    BRIDGEINIT BridgeInit;
    DBGINIT DbgInit;
    DBGCMDEXEC DbgCmdExec;
    DEBEXIT DbgExit;
    DBGSENDMESSAGE _dbg_sendmessage;
};