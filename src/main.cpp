#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "gui/output.h"
#include "gui/input.h"
#include "game/main.h"
main()
{
    //system("Tetris.mid");
    Init();
    DisplayFramework();
    GameInitiate();
    while(true)
    {
        int listen = Listen();
        if(listen == 1)
        {
            newgame:
            Game game = *(new Game());
            int count = 10 - game.GetDifficulty() > 0 ? 10 - game.GetDifficulty() : 0;
            int speed = 100;
            DisplayFramework();
            DisplayColorfulTitle(26,20);
            while(true)
            {
                ClearMap();
                ClearNextBrick();
                DisplayNextBrick(game);
                DisplayInfo(game);
                DisplayCurrentMap(game);
                DisplayCurrentBrick(game);
                listen = Listen();
                if(listen == -1)
                {
                    GamePause();
                    Sleep(1000);
                    while(true)
                    {
                        listen = Listen();
                        if(listen == -1)
                            goto end;
                        else if(listen == 1)
                        {
                            DisplayFramework();
                            DisplayColorfulTitle(26,20);
                            break;
                        }
                    }
                }
                else if(listen == 2)
                    game.BrickRotate();
                else if(listen == 3)
                    game.BrickHorizontalMove(false);
                else if(listen == 4)
                    game.BrickDescend();
                else if(listen == 5)
                    game.BrickHorizontalMove(true);
                else if(listen == 6)
                    game.BrickFastDescend();
                if(count == 0)
                {
                    if(game.BrickDescend())
                        printf("%d, %d, %d", game.GetCurrentBrick()->GetPosition()[0], game.GetCurrentBrick()->GetPosition()[1], game.GetCurrentBrick()->GetDirection());
                    else
                    {
                        game.PlaceCurrentBrick();
                        while(game.isAnyClearableRow())
                        {
                            game.ClearRow(game.isAnyClearableRow());
                        }
                        if(game.Next());
                        else
                        {
                            GameOver(game.GetScore());
                            while(true)
                            {
                                listen = Listen();
                                if(listen == 1)
                                {
                                    DisplayFramework();
                                    GameInitiate();
                                    Sleep(1000);
                                    goto newgame;
                                }
                            }
                        }
                    }
                    count = 10 - game.GetDifficulty() > 0 ? 10 - game.GetDifficulty() : 0;
                }
                else
                    --count;
                Sleep(speed);
            }
        }
        else if(listen == -1)
            break;
    }
    end:;
}