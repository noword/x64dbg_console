#include <Windows.h>
#include <winnt.h>
#include <stdio.h>
#include "bridge.h"
#include "crossline.h"

#ifdef _WIN64
#define PROMPT "(x64dbg)"
#else
#define PROMPT "(x32dbg)"
#endif

void completion_hook(char const* buf, crossline_completions_t* pCompletion)
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

void WaitOutput()
{
    while (GetTickCount() - Bridge::GetInstance()->GetLastLogTime() < 500)
    {
        Sleep(200);
    }
}

int main(int argc, char** argv)
{
    Bridge* bridge = Bridge::GetInstance();

    if (bridge->Init())
    {
        WaitOutput();
        
        crossline_completion_register(completion_hook);
        crossline_prompt_color_set(crossline_color_e(CROSSLINE_FGCOLOR_BRIGHT | CROSSLINE_FGCOLOR_GREEN));
        
        char cmd[128];
        while (crossline_readline(PROMPT, cmd, 128))
        {
            
            if (_strcmpi(cmd, "quit") == 0 || _strcmpi(cmd, "exit") == 0)
            {
                break;
            }
            bridge->DbgExecCmd(cmd);
            Sleep(200);
            WaitOutput();
        }
    }
    bridge->FreeInstance();
    return 0;
}
