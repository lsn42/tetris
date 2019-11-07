#include <windows.h>
#include <cstdio>
#include "game/game.h"
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) 
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
const COORD START = {0, 0};
const COORD END = {22, 21};
int Listen()
{
    // listen key state
    if(KEYDOWN(VK_ESCAPE))// Esc
        return -1;
    else if(KEYDOWN(VK_RETURN))// Enter
        return 1;
    else if(KEYDOWN(0x57) || KEYDOWN(VK_UP))// W or ↑
        return 2;
    else if(KEYDOWN(0x41) || KEYDOWN(VK_LEFT))// A or ←
        return 3;
    else if(KEYDOWN(0x53) || KEYDOWN(VK_DOWN))// S or ↓
        return 4;
    else if(KEYDOWN(0x44) || KEYDOWN(VK_RIGHT))// D or →
        return 5;
    else if(KEYDOWN(VK_SPACE))// Space
        return 6;
    else// neither
        return 0;
}
void HideCursor()
{
    // hide console cursor
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
}
void DisplayFramework()
{
    // show the tetris game framework
    SetConsoleCursorPosition(hOutput, START);// move cursor to the start
    printf("---------------------  ---------------\n");
    printf("|                   |  | Next:       |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  ---------------\n");
    printf("|                   |                 \n");
    printf("|                   |  ---------------\n");
    printf("|                   |  | Difficulty: |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  ---------------\n");
    printf("|                   |                 \n");
    printf("|                   |  ---------------\n");
    printf("|                   |  | Score:      |\n");
    printf("|                   |  |             |\n");
    printf("|                   |  ---------------\n");
    printf("|                   |                 \n");
    printf("|                   |                 \n");
    printf("---------------------                 \n");
}
void DisplayColorfulTitle(int x, int y)
{
    // show the colorful text "T E T R I S" in console of position (x, y)
    COORD coord = {0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hOutput, coord);
    SetConsoleTextAttribute(hOutput, 0x0c);
    printf("T ");
    SetConsoleTextAttribute(hOutput, 0x0e);
    printf("E ");
    SetConsoleTextAttribute(hOutput, 0x0c);
    printf("T ");
    SetConsoleTextAttribute(hOutput, 0x0a);
    printf("R ");
    SetConsoleTextAttribute(hOutput, 0x09);
    printf("I ");
    SetConsoleTextAttribute(hOutput, 0x0d);
    printf("S");
    SetConsoleTextAttribute(hOutput, 0x0f);
    SetConsoleCursorPosition(hOutput, END);// move cursor to the end
}
void DisplayCurrentMap(Game game)
{
    // print map of the game with color, value 0 won't display
    COORD coord = {0};
    for(int i = 0; i < 20; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            int value = game.GetMapValue(i, j);
            coord.X = 1 + j * 2;
            coord.Y = 1 + i;
            SetConsoleCursorPosition(hOutput, coord);
            if(value)
            {
                if(value == 1)
                    SetConsoleTextAttribute(hOutput, 0x0c);//red
                else if(value == 2)
                    SetConsoleTextAttribute(hOutput, 0x0e);//yellow
                else if(value == 3)
                    SetConsoleTextAttribute(hOutput, 0x0a);//green
                else if(value == 4)
                    SetConsoleTextAttribute(hOutput, 0x09);//blue
                else if(value == 5)
                    SetConsoleTextAttribute(hOutput, 0x0d);//purple
                printf("#");
            }
        }
    }
    SetConsoleTextAttribute(hOutput, 0x0f);
    SetConsoleCursorPosition(hOutput, END);// move cursor to the end
}
void DisplayCurrentBrick(Game game)
{
    // display current operating brick according to its type, position and diretion
    COORD coord = {0};
    int type = game.GetCurrentBrick()->GetType();//get brick type for color
    if(type == 0)
        SetConsoleTextAttribute(hOutput, 0x0c);// red
    else if(type == 1 || type == 2)
        SetConsoleTextAttribute(hOutput, 0x0e);// yellow
    else if(type == 3 || type == 4)
        SetConsoleTextAttribute(hOutput, 0x0a);// green
    else if(type == 5)
        SetConsoleTextAttribute(hOutput, 0x09);// blue
    else if(type == 6)
        SetConsoleTextAttribute(hOutput, 0x0d);// purple
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            coord.X = 1 + (game.GetCurrentBrick()->GetPosition()[0] + j - 2) * 2;
            coord.Y = 1 + game.GetCurrentBrick()->GetPosition()[1] + i - 2;
            SetConsoleCursorPosition(hOutput, coord);
            // move cusor
            if(game.GetCurrentBrick()->GetShapeValue(i, j))
                printf("#");
        }
    }
    SetConsoleTextAttribute(hOutput, 0x0f);// set color to white
    SetConsoleCursorPosition(hOutput, END);// move cursor to the end
}
void DisplayNextBrick(Game game)
{
    // display next brick in specific position according to its type and diretion
    COORD coord = {0};
    int type = game.GetNextBrick()->GetType();
    if(type == 0)
        SetConsoleTextAttribute(hOutput, 0x0c);// red
    else if(type == 1 || type == 2)
        SetConsoleTextAttribute(hOutput, 0x0e);// yellow
    else if(type == 3 || type == 4)
        SetConsoleTextAttribute(hOutput, 0x0a);// green
    else if(type == 5)
        SetConsoleTextAttribute(hOutput, 0x09);// blue
    else if(type == 6)
        SetConsoleTextAttribute(hOutput, 0x0d);// purple
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            coord.X = 25 + j * 2;
            coord.Y = 3 + i;
            SetConsoleCursorPosition(hOutput, coord);
            // move cusor
            if(game.GetNextBrick()->GetShapeValue(i, j))
                printf("#");
        }
    }
    SetConsoleTextAttribute(hOutput, 0x0f);// set color to white
    SetConsoleCursorPosition(hOutput, END);// move cursor to the end
}
void DisplayInfo(Game game)
{
    // display game difficulty and score in specific position
    COORD coord = {0};
    coord.X = 25;
    coord.Y = 12;
    SetConsoleCursorPosition(hOutput, coord);
    printf("%11d", game.GetDifficulty());
    coord.X = 25;
    coord.Y = 17;
    SetConsoleCursorPosition(hOutput, coord);
    printf("%11d", game.GetScore());
    SetConsoleCursorPosition(hOutput, END);
}
void ClearMap()
{
    // clear the game map area in console
    COORD coord = {0};
    for(int i = 0; i < 20 ; ++i)
    {
        coord.X = 1;
        coord.Y = 1 + i;
        SetConsoleCursorPosition(hOutput, coord);
        printf("                   ");
    }
    SetConsoleCursorPosition(hOutput, END);// move cursor to the end
}
void ClearNextBrick()
{
    // clear the next brick area in console
    COORD coord = {0};
    for(int i = 0; i < 6 ; ++i)
    {
        coord.X = 24;
        coord.Y = 2 + i;
        SetConsoleCursorPosition(hOutput, coord);
        printf("             ");
    }
    SetConsoleCursorPosition(hOutput, END);// move cursor to the end
}
void GameStart()
{
    // show the tetris game start window
    COORD coord = {0};
    coord.X = 4;
    coord.Y = 6;
    SetConsoleCursorPosition(hOutput, coord);
    printf("--------------------------------");
    coord.Y = 7;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|                              |");
    coord.Y = 8;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|                              |");
    coord.Y = 9;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|                              |");
    coord.Y = 10;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|    Press <Enter> to start    |");
    coord.Y = 11;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|     Press <Esc> to exit      |");
    coord.Y = 12;
    SetConsoleCursorPosition(hOutput, coord);
    printf("--------------------------------");
    DisplayColorfulTitle(14, 8);
    SetConsoleCursorPosition(hOutput, END);
}
void GamePause()
{
    // show the tetris game pause window
    COORD coord = {0};
    coord.X = 4;
    coord.Y = 6;
    SetConsoleCursorPosition(hOutput, coord);
    printf("--------------------------------");
    coord.Y = 7;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|          G  a  m  e          |");
    coord.Y = 8;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|       P  a  u  s  e  d       |");
    coord.Y = 9;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|                              |");
    coord.Y = 10;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|   Press <Enter> to continue  |");
    coord.Y = 11;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|     Press <Esc> to exit      |");
    coord.Y = 12;
    SetConsoleCursorPosition(hOutput, coord);
    printf("--------------------------------");
    SetConsoleCursorPosition(hOutput, END);
}
void GameOver(int score)
{
    // show the tetris game over window with score
    COORD coord = {0};
    coord.X = 4;
    coord.Y = 6;
    SetConsoleCursorPosition(hOutput, coord);
    printf("--------------------------------");
    coord.Y = 7;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|          G  a  m  e          |");
    coord.Y = 8;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|          O  v  e  r          |");
    coord.Y = 9;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|    Your score:%11d    |", score);
    coord.Y = 10;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|                              |");
    coord.Y = 11;
    SetConsoleCursorPosition(hOutput, coord);
    printf("|   Press <Enter> to continue  |");
    coord.Y = 12;
    SetConsoleCursorPosition(hOutput, coord);
    printf("--------------------------------");
    SetConsoleCursorPosition(hOutput, END);
}