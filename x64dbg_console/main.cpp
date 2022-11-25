#include <Windows.h>
#include <winnt.h>
#include <stdio.h>
#include "bridge.h"

int main(int argc, char** argv)
{
    Bridge* bridge = Bridge::GetInstance();
    if (bridge->IsInited())
    {
        char cmd[128];
        while (gets_s(cmd, 128))
        {
            if (_strcmpi(cmd, "quit") == 0 || _strcmpi(cmd, "exit") == 0)
            {
                break;
            }
            bridge->ExecCmd(cmd);
        }
    }
    bridge->FreeInstance();
    return 0;
}
