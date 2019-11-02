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
    memset(this->Map, 0, sizeof(this->Map));
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
void Game::CleanRow(int row)
{

}