#include <Windows.h>
#include <stdio.h>
#include "hooker.h"

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

