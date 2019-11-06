#include <cstring>
#include <cstdio>
#include "Brick.h"
#include "game.h"
Game::Game()
{
    this->Score = 0;
    // clean 1 row get 100 points
    this->Difficulty = 0;
    // increase 1 every 500 points
    CurrentBrick = new Brick();
    NextBrick = new Brick();
    memset(this->Map, 0, sizeof(int) * 200);
}
// value getter
int Game::GetMapValue(int row, int column)
{
    return this->Map[row][column];
}
int Game::GetScore()
{
    return this->Score;
}
int Game::GetDifficulty()
{
    return this->Difficulty;
}
Brick* Game::GetCurrentBrick()
{
    return this->CurrentBrick;
}
Brick* Game::GetNextBrick()
{
    return this->NextBrick;
}
bool Game::Next()
{
    // replace current brick with next brick, generate a new brick to replace the next brick
    // return false while failed to generate a new brick(the map is full)
    delete this->CurrentBrick;
    this->CurrentBrick = this->NextBrick;
    if(this->isValid(*(this->GetCurrentBrick())))
    {
        this->NextBrick = new Brick();
        return true;
    }
    else
        return false;
}
int Game::isAnyClearableRow()
{
    // search clearable row from top, return the first clearable row, return 0 if there is none
    for(int i = 0; i < 20; ++i)
    {
        bool a = true;
        for(int j = 0; j < 10; ++j)
            a = a && this->Map[i][j];
        if(a)
            return i;
    }
    return 0;
}
void Game::ClearRow(int row)
{
    // clear specific row, every row counts for 100 points
    int _map[20][10];
    memcpy(_map, this->Map, sizeof(int) * 200);
    memset(this->Map, 0, sizeof(int) * row * 10);
    memcpy(this->Map + 1, _map, sizeof(int) * row * 10);
    this->Score += 100;
    this->Difficulty = this->Score / 500;
}
bool Game::isValid(Brick& brick)
{
    // judge if the brick is availible, true is valid, false is invalid
    if(
        brick.GetPosition()[1] - RotateCode[brick.GetType()][brick.GetDirection()][0] >= 0 &&
        brick.GetPosition()[0] - RotateCode[brick.GetType()][brick.GetDirection()][1] >= 0 &&
        brick.GetPosition()[1] + RotateCode[brick.GetType()][brick.GetDirection()][2] < 20 &&
        brick.GetPosition()[0] + RotateCode[brick.GetType()][brick.GetDirection()][3] < 10
    )
    // invalid if brick out of border
    {
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)                
                if(
                    brick.GetPosition()[1] - 2 + j >= 0 &&
                    brick.GetPosition()[1] - 2 + j < 20 &&
                    brick.GetPosition()[0] - 2 + i >= 0 &&
                    brick.GetPosition()[0] - 2 + i < 10 
                )
                // prevent access outside the map
                    if(brick.GetShapeValue(i, j))
                        if(this->Map[brick.GetPosition()[1] + i - 2][brick.GetPosition()[0] + j - 2])
                        // invalid if confilct with game map
                            return false;
        return true;
        // the brick is valid going through all procedure
    }
    else
        return false;
}
bool Game::BrickRotate()
{
    // rotate brick anticlockwise
    Brick _brick = *(this->GetCurrentBrick());// copy a current brick
    _brick.Rotate(true);// rotate the copy one for one block, in order to test if the operation is availible
    if(this->isValid(_brick))// judge valid
    {
        // the operation is valid, rotate the current brick and return ture
        delete &_brick;
        this->GetCurrentBrick()->Rotate(true);
        return true;
    }
    else
    {
        // invalid operation, return false
        delete &_brick;
        return false;
    }
}
bool Game::BrickHorizontalMove(bool diretion)
{
    // brick go horizontally one block
    // false left, true right
    Brick _brick = *(this->GetCurrentBrick());// copy a current brick
    _brick.Move(diretion?1:-1, 0);// move the copy one horizontally for one block, in order to test if the operation is availible
    if(this->isValid(_brick))
    {
        // the operation is valid, move the current brick horizontally and return ture
        delete &_brick;
        this->GetCurrentBrick()->Move(diretion?1:-1, 0);
        return true;
    }
    else
    {
        // invalid operation, return false
        delete &_brick;
        return false;
    }
}
bool Game::BrickDescend()
{
    // brick go down one block
    Brick _brick = *(this->GetCurrentBrick());// copy a current brick
    _brick.Move(0, 1);// move down the copy one for one block, in order to test if the operation is availible
    if(this->isValid(_brick))
    {
        // the operation is valid, move down the current brick and return ture
        delete &_brick;
        this->GetCurrentBrick()->Move(0, 1);
        return true;
    }
    else
    {
        // invalid operation, return false
        delete &_brick;
        return false;
    }
}
void Game::BrickFastDescend()
{
    // continually move down the brick, stop if the brick is not able to move down
    while(Game::BrickDescend());
}
void Game::PlaceCurrentBrick()
{
    // fix the current brick to the map, with color
    int type = this->GetCurrentBrick()->GetType(), color = 0;
    if(type == 0)
        color = 1;
    else if(type == 1 || type == 2)
        color = 2;
    else if(type == 3 || type == 4)
        color = 3;
    else if(type == 5)
        color = 4;
    else if(type == 6)
        color = 5;
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            if(this->GetCurrentBrick()->GetShapeValue(i, j))
                this->Map[(this->GetCurrentBrick()->GetPosition())[1] + i - 2][(this->GetCurrentBrick()->GetPosition())[0] + j - 2] = color;
}