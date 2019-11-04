#include <windows.h>
#include "input.h"
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) 
int Listen()
{
    if(KEYDOWN(VK_ESCAPE))
        return -1;
    else if(KEYDOWN(VK_RETURN))
        return 1;
    else if(KEYDOWN(0x57) || KEYDOWN(VK_UP))
        return 2;
    else if(KEYDOWN(0x41) || KEYDOWN(VK_LEFT))
        return 3;
    else if(KEYDOWN(0x53) || KEYDOWN(VK_DOWN))
        return 4;
    else if(KEYDOWN(0x44) || KEYDOWN(VK_RIGHT))
        return 5;
    else if(KEYDOWN(VK_SPACE))
        return 6;
    else
        return 0;
}