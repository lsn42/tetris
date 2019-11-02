#ifndef GAME_MAIN_H
#define GAME_MAIN_H
#include "Brick.h"
class Game
{
private:
    int Map[20][10];
    //0~5, 0:empty 1:red 2:yellow 3:green 4:blue 5:purple
    int Score;
    int Difficulty;
    Brick *CurrentBrick, *NextBrick;
public:
    Game();
    int GetMapValue(int row, int column);
    int GetScore();
    int GetDifficulty();
    Brick* GetCurrentBrick();
    Brick* GetNextBrick();
    void CleanRow(int row);
};
#endif