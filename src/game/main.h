#ifndef GAME_MAIN_H
#define GAME_MAIN_H
#include "Brick.h"
const int RotateCode[7][4][4] =
{
    2,0,1,0, 0,2,0,1, 1,0,2,0, 0,1,0,2,
    2,0,0,1, 1,2,0,0, 0,1,2,0, 0,0,1,2,
    2,1,0,0, 0,2,1,0, 0,0,2,1, 1,0,0,2,
    1,0,1,1, 1,1,0,1, 1,1,1,0, 0,1,1,1,
    1,1,1,0, 0,1,1,1, 1,0,1,1, 1,1,0,1,
    1,1,0,1, 1,1,1,0, 0,1,1,1, 1,0,1,1,
    1,0,0,1, 1,0,0,1, 1,0,0,1, 1,0,0,1
};
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
    void Next();
    int isAnyClearableRow();
    void ClearRow(int row);
    bool isValid(Brick& brick);
    bool BrickDescend();
    void BrickFastDescend();
    bool BrickHorizontalMove(bool diretion);
    bool BrickRotate();
    void Update();
    void PlaceCurrentBrick();
};
#endif