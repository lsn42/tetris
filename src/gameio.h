#ifndef GAMEIO_H
#define GAMEIO_H
#include "game/game.h"
// listen key state
int Listen();
// hide console cursor
void HideCursor();
// show the tetris game framework
void DisplayFramework();
// show the colorful text "T E T R I S" in console of position (x, y)
void DisplayColorfulTitle(int x, int y);
// print map of the game with color, value 0 won't display
void DisplayCurrentMap(Game game);
// display current operating brick according to its type, position and diretion
void DisplayCurrentBrick(Game game);
// display next brick in specific position according to its type and diretion
void DisplayNextBrick(Game game);
// display game difficulty and score in specific position
void DisplayInfo(Game game);
// clear the game map area in console
void ClearMap();
// clear the next brick area in console
void ClearNextBrick();
// show the tetris game start window
void GameStart();
// show the tetris game pause window
void GamePause();
// show the tetris game over window with score
void GameOver(int score);
#endif