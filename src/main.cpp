#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "gui/main.h"
#include "game/main.h"
main()
{
    Game* game = new Game();
    SetConsoleTitleA((LPCSTR)"TETRIS");
    display(*game);
    game->GetNextBrick()->Rotate(true);
    display(*game);
    getchar();
}