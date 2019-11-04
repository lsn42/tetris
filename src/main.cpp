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
    Game game = *(new Game());
    DisplayFramework();
    GameInitiate();
    while(true)
    {
        int listen = Listen();
        if(listen == 1)
        {
            int rate = 1;
            int speed = 300;
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
                if(game.BrickDescend())
                    printf("position : %d %d", game.GetCurrentBrick()->GetPosition()[0], game.GetCurrentBrick()->GetPosition()[1]);
                else
                {
                    game.PlaceCurrentBrick();
                    game.Next();
                }
                Sleep(speed);
            }
        }
        else if(listen == -1)
            break;
    }
    end:;
}