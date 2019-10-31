#include <cstdio>
#include <iostream>
#include <string>
#include "gui/main.h"
#include "game/main.h"
main()
{
    Game* game = new Game();
    display(*game);
    getchar();
}