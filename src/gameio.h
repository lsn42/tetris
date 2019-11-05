#ifndef IO_H
#define IO_H
#include "game/main.h"
int Listen();
void HideCursor();
void DisplayFramework();
void DisplayColorfulTitle(int x, int y);
void DisplayCurrentMap(Game game);
void DisplayCurrentBrick(Game game);
void DisplayNextBrick(Game game);
void DisplayInfo(Game game);
void ClearMap();
void ClearNextBrick();
void GameStart();
void GamePause();
void GameOver(int score);
#endif