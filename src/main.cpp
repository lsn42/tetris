#include <windows.h>
#include "gameio.h"
#include "game/game.h"
int main()
{
    int displayrate = 80;
    HideCursor();
    // display game interface
    DisplayFramework();
    GameStart();
    while(true)// main loop
    {
        // main menu
        main:
        int listen = Listen();
        if(listen == 1 || listen == 6)// press enter or space
        {
            // start a new game
            newgame:
            Game game = *(new Game());
            // would the brick self descend in this frame, 0 represent yes, other represent no, depend on game difficulty
            int count = 10 - game.GetDifficulty() > 0 ? 10 - game.GetDifficulty() : 0;
            DisplayFramework();
            DisplayColorfulTitle(26,20);
            while(true)// game loop
            {
                ClearMap();
                ClearNextBrick();
                DisplayCurrentMap(game);
                DisplayCurrentBrick(game);
                DisplayNextBrick(game);
                DisplayInfo(game);
                listen = Listen();// listen to operation
                if(listen == -1)// press Esc, game pause
                {
                    GamePause();
                    Sleep(500);
                    while(true)// game pause loop
                    {
                        listen = Listen();
                        if(listen == -1)// press Esc
                            // end the game
                            goto end;
                        else if(listen == 1 || listen == 6)// press enter or space
                        {
                            DisplayFramework();
                            DisplayColorfulTitle(26,20);
                            break;
                        }
                    }
                }
                else if(listen == 2)// press W or ↑, rotate
                    game.BrickRotate();
                else if(listen == 3)// press A or ←, go left
                    game.BrickHorizontalMove(false);
                else if(listen == 4)// press S or ↓, descend
                    game.BrickDescend();
                else if(listen == 5)// press D or →, go right
                    game.BrickHorizontalMove(true);
                else if(listen == 6)// press space, fast descend
                    game.BrickFastDescend();
                if(count == 0)// the brick should self descend
                {
                    // current brick self descend in this frame
                    // self descend
                    if(game.BrickDescend());// self descend successful
                    else
                    {
                        // self descend unsuccessful, fix current brick
                        game.PlaceCurrentBrick();
                        while(game.isAnyClearableRow())// check if any clearable row, if so, clear them
                        {
                            game.ClearRow(game.isAnyClearableRow());
                        }
                        // get next state
                        if(game.Next());// turn to next state successful
                        else
                        {
                            //trun to next state unsuccessful, game map is full, game over!
                            GameOver(game.GetScore());
                            while(true)// game over confirm loop
                            {
                                listen = Listen();
                                if(listen == -1)// press Esc
                                    // end the game
                                    goto end;
                                else if(listen == 1 || listen == 6)// press enter or space
                                {
                                    // restart game, display game interface and go to the main loop
                                    Sleep(500);
                                    DisplayFramework();
                                    GameStart();
                                    goto main;
                                }
                            }
                        }
                    }
                    // recalculate the count
                    count = 10 - game.GetDifficulty() > 0 ? 10 - game.GetDifficulty() : 0;
                }
                else// the brick should not self descend, decrease count
                    --count;
                Sleep(displayrate);
            }
        }
        else if(listen == -1)// press Esc
            // end the game
            break;
    }
    end:;
}