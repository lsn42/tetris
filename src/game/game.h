#ifndef GAME_GAME_H
#define GAME_GAME_H
#include "Brick.h"
// use for judge if the brick i s out of border
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
    // 0~5, 0:empty 1:red 2:yellow 3:green 4:blue 5:purple
    int Map[20][10];
    int Score;
    // how fast the brick self descend, increase 1 for every 500 points
    // brick self descend speed won't increase if difficulty is larger than 10
    int Difficulty;
    Brick *CurrentBrick, *NextBrick;
public:
    Game();
    int GetMapValue(int row, int column);
    int GetScore();
    int GetDifficulty();
    Brick* GetCurrentBrick();
    Brick* GetNextBrick();
    // replace current brick with next brick, generate a new brick to replace the next brick
    // return false while failed to generate a new brick(the map is full)
    bool Next();
    // search clearable row from top, return the first clearable row, return 0 if there is none
    int isAnyClearableRow();
    // clear specific row, every row counts for 100 points
    void ClearRow(int row);
    // judge if the brick is availible, true is valid, false is invalid
    bool isValid(Brick& brick);
    // rotate brick anticlockwise
    bool BrickRotate();
    // brick go horizontally one block
    // false left, true right
    bool BrickHorizontalMove(bool diretion);
    // brick go down one block
    bool BrickDescend();
    // continually move down the brick, stop if the brick is not able to move down
    void BrickFastDescend();
    // fix the current brick to the map, with color
    void PlaceCurrentBrick();
};
#endif