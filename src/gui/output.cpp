#include <windows.h>
#include <cstdio>
#include "src/game/main.h"
HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE input = GetStdHandle(STD_INPUT_HANDLE);
void DisplayFramwork()
{
    printf("----------------------  ---------------\n");
    printf("|                    |  | Next:       |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  ---------------\n");
    printf("|                    |                 \n");
    printf("|                    |  ---------------\n");
    printf("|                    |  | Difficulty: |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  ---------------\n");
    printf("|                    |                 \n");
    printf("|                    |  ---------------\n");
    printf("|                    |  | Score:      |\n");
    printf("|                    |  |             |\n");
    printf("|                    |  ---------------\n");
    printf("|                    |                 \n");
    printf("|                    |                 \n");
    printf("----------------------                 \n");
}
void DisplayColorfulTitle()
{
    COORD coord = {0};
    coord.X = 26;
    coord.Y = 20;
    SetConsoleCursorPosition(output, coord);
    SetConsoleTextAttribute(output, 0x0c);
    printf("T ");
    SetConsoleTextAttribute(output, 0x0e);
    printf("E ");
    SetConsoleTextAttribute(output, 0x0c);
    printf("T ");
    SetConsoleTextAttribute(output, 0x0a);
    printf("R ");
    SetConsoleTextAttribute(output, 0x09);
    printf("I ");
    SetConsoleTextAttribute(output, 0x0d);
    printf("S");
    SetConsoleTextAttribute(output, 0x0f);
}
void DisplayCurrentMap(Game game)
{
    COORD coord = {0};
    for(int i = 0; i < 20; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            int value = game.GetMapValue(i, j);
            coord.X = 1 + j * 2;
            coord.Y = 1 + i;
            SetConsoleCursorPosition(output, coord);
            if(value)
            {
                if(value == 1)
                    SetConsoleTextAttribute(output, 0x0c);//red
                else if(value == 2)
                    SetConsoleTextAttribute(output, 0x0e);//yellow
                else if(value == 3)
                    SetConsoleTextAttribute(output, 0x0a);//green
                else if(value == 4)
                    SetConsoleTextAttribute(output, 0x09);//blue
                else if(value == 5)
                    SetConsoleTextAttribute(output, 0x0d);//purple
                printf("#");
            }
            SetConsoleTextAttribute(output, 0x0f);
        }
    }
}
void DisplayCurrentBrick(Game game)
{
    COORD coord = {0};
    int type = game.GetNextBrick()->GetType();
    if(type == 0)
        SetConsoleTextAttribute(output, 0x0c);
    else if(type == 1 || type == 2)
        SetConsoleTextAttribute(output, 0x0e);
    else if(type == 3 || type == 4)
        SetConsoleTextAttribute(output, 0x0a);
    else if(type == 5)
        SetConsoleTextAttribute(output, 0x09);
    else if(type == 6)
        SetConsoleTextAttribute(output, 0x0d);
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            coord.X = 1 + j * 2;
            coord.Y = 1 + i;
            SetConsoleCursorPosition(output, coord);
            if(game.GetNextBrick()->GetShapeValue(i, j))
                printf("#");
        }
    }
    SetConsoleTextAttribute(output, 0x0f);
}
void DisplayNextBrick(Game game)
{
    COORD coord = {0};
    int type = game.GetNextBrick()->GetType();
    if(type == 0)
        SetConsoleTextAttribute(output, 0x0c);
    else if(type == 1 || type == 2)
        SetConsoleTextAttribute(output, 0x0e);
    else if(type == 3 || type == 4)
        SetConsoleTextAttribute(output, 0x0a);
    else if(type == 5)
        SetConsoleTextAttribute(output, 0x09);
    else if(type == 6)
        SetConsoleTextAttribute(output, 0x0d);
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            coord.X = 26 + j * 2;
            coord.Y = 3 + i;
            SetConsoleCursorPosition(output, coord);
            if(game.GetNextBrick()->GetShapeValue(i, j))
                printf("#");
        }
    }
    SetConsoleTextAttribute(output, 0x0f);
}
void DisplayInfo(Game game)
{
    COORD coord = {0};
    coord.X = 26;
    coord.Y = 12;
    SetConsoleCursorPosition(output, coord);
    printf("%11d", game.GetDifficulty());
    coord.X = 26;
    coord.Y = 17;
    SetConsoleCursorPosition(output, coord);
    printf("%11d", game.GetScore());
}