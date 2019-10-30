#ifndef GAME_MAIN_H
#define GAME_MAIN_H
#include "Brick.h"
class Game
{
private:
    bool map[10][20];
    int score;
    Brick CurrentBrick, NextBrick;
public:
    Game();
};
#endif