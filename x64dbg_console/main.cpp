#include "bridge.h"

int main(int argc, char **argv)
{
    Bridge* bridge = Bridge::GetInstance();
    bridge->Init();
    bridge->FreeInstance();
    return 0;
}
