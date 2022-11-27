#pragma once
#include "bridge.h"

extern int _gui_guiinit(int argc, char* argv[]);
extern const char* _gui_translate_text(const char* source);
extern void* _gui_sendmessage(GUIMSG type, void* param1, void* param2);