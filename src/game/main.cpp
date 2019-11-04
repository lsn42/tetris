#include <cstring>
#include <cstdio>
#include "Brick.h"
#include "main.h"
Game::Game()
{
    this->Score = 0;
    this->Difficulty = 0;
    CurrentBrick = new Brick();
    NextBrick = new Brick();
    memset(this->Map, 0, sizeof(int) * 200);
}
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
    int _map[20][10];
    memcpy(_map, this->Map, sizeof(int) * 200);
    memset(this->Map, 0, sizeof(int) * row * 10);
    memcpy(this->Map + 1, _map, sizeof(int) * row * 10);
    this->Score++;
    this->Difficulty = this->Score / 10;
}
bool Game::isValid(Brick& brick)
{
    if(
        brick.GetPosition()[1] - RotateCode[brick.GetType()][brick.GetDirection()][0] >= 0 &&
        brick.GetPosition()[0] - RotateCode[brick.GetType()][brick.GetDirection()][1] >= 0 &&
        brick.GetPosition()[1] + RotateCode[brick.GetType()][brick.GetDirection()][2] < 20 &&
        brick.GetPosition()[0] + RotateCode[brick.GetType()][brick.GetDirection()][3] < 10
    )
    {
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)                
                if(
                    brick.GetPosition()[1] - 2 + j >= 0 &&
                    brick.GetPosition()[1] - 2 + j < 20 &&
                    brick.GetPosition()[0] - 2 + i >= 0 &&
                    brick.GetPosition()[0] - 2 + i < 10 
                )
                    if(brick.GetShapeValue(i, j))
                        if(this->Map[brick.GetPosition()[1] + i - 2][brick.GetPosition()[0] + j - 2])
                            return false;
        return true;
    }
    else
        return false;
}
bool Game::BrickDescend()
{
    Brick _brick = *(this->GetCurrentBrick());
    _brick.Move(0, 1);
    if(this->isValid(_brick))
    {
        this->GetCurrentBrick()->Move(0, 1);
        return true;
    }
    else
        return false;
}
void Game::BrickFastDescend()
{
    while(Game::BrickDescend());
}
bool Game::BrickHorizontalMove(bool diretion)//left false, right true
{
    Brick _brick = *(this->GetCurrentBrick());
    _brick.Move(diretion?1:-1, 0);
    if(this->isValid(_brick))
    {
        this->GetCurrentBrick()->Move(diretion?1:-1, 0);
        return true;
    }
    else
        return false;
}
bool Game::BrickRotate()
{
    Brick _brick = *(this->GetCurrentBrick());
    _brick.Rotate(true);
    if(this->isValid(_brick))
    {
        this->GetCurrentBrick()->Rotate(true);
        return true;
    }
    else
        return false;
}
void Game::PlaceCurrentBrick()
{
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