#pragma once

extern void SetHooker(void* targetFunction, void* hookedFunction);
extern void SetHooker(HMODULE module, const char* name, void* hookedFunction);

#define SET_HOOKER(MODULE, NAME) SetHooker(MODULE, #NAME, NAME);