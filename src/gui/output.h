#ifndef GUI_OUTPUT_H
#define GUI_OUTPUT_H
#include "../game/main.h"
void Init();
void DisplayFramework();
void DisplayColorfulTitle(int x, int y);
void DisplayCurrentMap(Game game);
void DisplayCurrentBrick(Game game);
void DisplayNextBrick(Game game);
void DisplayInfo(Game game);
void ClearMap();
void ClearNextBrick();
void GameInitiate();
void GamePause();
void GameOver(int score);
#endif