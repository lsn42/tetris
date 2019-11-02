#ifndef GAME_MAIN_H
#define GAME_MAIN_H
#include "Brick.h"
class Game
{
private:
    bool Map[20][10];
    int Score;
    int Difficulty;
    Brick *CurrentBrick, *NextBrick;
public:
    Game();
    bool GetMapValue(int row, int column);
    int GetScore();
    int GetDifficulty();
    Brick* GetCurrentBrick();
    Brick* GetNextBrick();
};
#endif