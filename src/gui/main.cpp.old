#include <cstdio>
#include <iostream>
#include <conio.h>
#include "main.h"
#include "../game/main.h"

void display(Game game)
{
    //1
    printf("############\n");
    //2
    printf("#");
    for(int i = 0; i < 10; ++i)
    {
        if(game.GetMapValue(0, i))
            printf("@");
        else
            printf(" ");
    }
    printf("#  next:\n");
    //3
    printf("#");
    for(int i = 0; i < 10; ++i)
    {
        if(game.GetMapValue(1, i))
            printf("@");
        else
            printf(" ");
    }
    printf("#  #######\n");
    //4~8
    for(int i = 2; i < 7; ++i)
    {
        printf("#");
        for(int j = 0; j < 10; ++j)
        {
            if(game.GetMapValue(i, j))
                printf("@");
            else
                printf(" ");
        }
        printf("#  #");
        for(int j = 0; j < 5; ++j)
        {
            if(game.GetNextBrick()->GetShapeValue(i-2, j))
                printf("@");
            else
                printf(" ");
        }
        printf("#\n");
    }
    //9
    printf("#");
    for(int i = 0; i < 10; ++i)
    {
        if(game.GetMapValue(7, i))
            printf("@");
        else
            printf(" ");
    }
    printf("#  #######\n");
    //10~21
    for(int i = 7; i < 19; ++i)
    {
        printf("#");
        for(int j = 0; j < 10; ++j)
        {
            if(game.GetMapValue(i,j))
                printf("@");
            else
                printf(" ");
        }
        printf("#");
        if(i == 9)
            printf("  score:%d",game.GetScore());
        else if(i == 13)
            printf("  difficulty:%d",game.GetDifficulty());
        else if(i == 17)
            printf("  TETRIS");
        printf("\n");
    }
    //22
    printf("############\n");
}