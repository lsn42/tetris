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
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(this->CurrentBrick->GetShapeValue(i,j))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(this->NextBrick->GetShapeValue(i,j))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    printf("\n");
    memset(this->Map, 0, sizeof(this->Map));
}
bool Game::GetMapValue(int row, int column)
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