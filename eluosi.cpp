#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

const int HEIGHT = 24, LENGTH = 40, SIDE = 22;      //标准尺寸
//*****x方向是竖直  y方向是水平**********//
int Emap[HEIGHT][SIDE];     //图
char I_map[HEIGHT + 1][LENGTH + 1];     //初始的图
/*************宏定义**************/
#define ME(a) memset(a, 0, sizeof(a))   
#define Judge(block, ok)                                \
    for (i = 0; i < 5; i++)                             \
        if (block[i].x && Emap[block[i].x][block[i].y]) \
    ok = 0
//*************该类存放二元组************//
struct Node
{
    int x;
    int y;
};
Node bl[5];
Node block[5];
const int TIME_DWELL = 1000;
int state = 0;

HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE input = GetStdHandle(STD_INPUT_HANDLE);
//**********设置光标位置**********//
void SetCur(int x, int y)
{
    COORD CO = {x, y};
    SetConsoleCursorPosition(output, CO);
}
//***********初始化图**************//
void Initmap()
{
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < SIDE; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == SIDE - 1)
                Emap[i][j] = 1;
            else
                Emap[i][j] = 0;
        }
}
//**********下一个要出现的方块*********//
void Former_block(int n)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        bl[i].x = 0;
        bl[i].y = 0;
    }
    if (n == 0)
    {
        bl[0].x = 3, bl[0].y = 28;
        bl[1].x = 3, bl[1].y = 30;
        bl[2].x = 4, bl[2].y = 30;
        bl[3].x = 4, bl[3].y = 32;
    }
    if (n == 1)
    {
        bl[0].x = 3, bl[0].y = 32;
        bl[1].x = 3, bl[1].y = 30;
        bl[2].x = 4, bl[2].y = 30;
        bl[3].x = 4, bl[3].y = 28;
    }
    if (n == 2)
    {
        bl[0].x = 3, bl[0].y = 30;
        bl[1].x = 4, bl[1].y = 28;
        bl[2].x = 4, bl[2].y = 30;
        bl[3].x = 4, bl[3].y = 32;
    }
    if (n == 3)
    {
        bl[0].x = 3, bl[0].y = 27;
        bl[1].x = 3, bl[1].y = 29;
        bl[2].x = 3, bl[2].y = 31;
        bl[3].x = 3, bl[3].y = 33;
    }
    if (n == 4)
    {
        bl[0].x = 3, bl[0].y = 29;
        bl[1].x = 3, bl[1].y = 31;
        bl[2].x = 4, bl[2].y = 29;
        bl[3].x = 4, bl[3].y = 31;
    }
    if (n == 5)
    {
        bl[0].x = 3, bl[0].y = 28;
        bl[1].x = 4, bl[1].y = 28;
        bl[2].x = 4, bl[2].y = 30;
        bl[3].x = 4, bl[3].y = 32;
    }
    if (n == 6)
    {
        bl[0].x = 3, bl[0].y = 32;
        bl[1].x = 4, bl[1].y = 28;
        bl[2].x = 4, bl[2].y = 30;
        bl[3].x = 4, bl[3].y = 32;
    }
    for (i = 0; i < 5; i++)
    {
        SetCur(bl[i].y, bl[i].x);
        printf("*");
    }
}
//***********获得不一样的方块***********//
void print_block(int n)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        block[i].x = block[i].y = 0;
    }
    if (n == 0)
    {
        block[0].x = 1, block[0].y = 7;
        block[1].x = 1, block[1].y = 9;
        block[2].x = 2, block[2].y = 9;
        block[3].x = 2, block[3].y = 11;
    }
    if (n == 1)
    {
        block[0].x = 1, block[0].y = 11;
        block[1].x = 1, block[1].y = 9;
        block[2].x = 2, block[2].y = 9;
        block[3].x = 2, block[3].y = 7;
    }
    if (n == 2)
    {
        block[0].x = 1, block[0].y = 9;
        block[1].x = 2, block[1].y = 7;
        block[2].x = 2, block[2].y = 9;
        block[3].x = 2, block[3].y = 11;
    }
    if (n == 3)
    {
        block[0].x = 1, block[0].y = 7;
        block[1].x = 1, block[1].y = 9;
        block[2].x = 1, block[2].y = 11;
        block[3].x = 1, block[3].y = 13;
    }
    if (n == 4)
    {
        block[0].x = 1, block[0].y = 9;
        block[1].x = 1, block[1].y = 11;
        block[2].x = 2, block[2].y = 9;
        block[3].x = 2, block[3].y = 11;
    }
    if (n == 5)
    {
        block[0].x = 1, block[0].y = 7;
        block[1].x = 2, block[1].y = 7;
        block[2].x = 2, block[2].y = 9;
        block[3].x = 2, block[3].y = 11;
    }
    if (n == 6)
    {
        block[0].x = 1, block[0].y = 11;
        block[1].x = 2, block[1].y = 7;
        block[2].x = 2, block[2].y = 9;
        block[3].x = 2, block[3].y = 11;
    }
    for (i = 0; i < 5; i++)
    {
        SetCur(block[i].y, block[i].x);
        printf("*");
    }
}
//***********变***********//
void Exchange(int m)
{
    int i, ok = 1;
    Node blo[5];
    for (i = 0; i < 5; i++)
        blo[i] = block[i];
    if (m == 0)
    {
        if (state == 0)
        {
            blo[0].x += 1;
            blo[0].y += 2;
            blo[2].x -= 1;
            blo[2].y += 2;
            blo[3].x -= 2;
            Judge(blo, ok);
            if (Emap[blo[0].x][blo[0].y - 2])
                ok = 0;
            if (ok)
            {
                for (i = 0; i < 5; i++)
                    block[i] = blo[i];
                state = 1;
            }
        }
        else
        {
            blo[0].x -= 1;
            blo[0].y -= 2;
            blo[2].x += 1;
            blo[2].y -= 2;
            blo[3].x += 2;
            Judge(blo, ok);
            if (Emap[blo[1].x - 1][blo[1].y])
                ok = 0;
            if (ok)
            {
                for (i = 0; i < 5; i++)
                    block[i] = blo[i];
                state = 0;
            }
        }
    }
    else if (m == 1)
    {
        if (state == 0)
        {
            blo[0].x -= 1;
            blo[0].y -= 2;
            blo[2].x -= 1;
            blo[2].y += 2;
            blo[3].y += 4;
            Judge(blo, ok);
            if (Emap[blo[1].x][blo[1].y - 2])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 1;
                }
        }
        else
        {
            blo[0].x += 1;
            blo[0].y += 2;
            blo[2].x += 1;
            blo[2].y -= 2;
            blo[3].y -= 4;
            Judge(blo, ok);
            if (Emap[blo[0].x - 1][blo[0].y])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 0;
                }
        }
    }
    else if (m == 2)
    {
        if (state == 0)
        {
            blo[0].x += 1;
            blo[0].y -= 2;
            blo[1].x += 1;
            blo[1].y += 2;
            blo[3].x -= 1;
            blo[3].y -= 2;
            Judge(blo, ok);
            if (Emap[blo[0].x + 1][blo[0].y] || Emap[blo[0].x - 1][block[0].y] || Emap[blo[3].x][blo[3].y + 2])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 1;
                }
        }
        else if (state == 1)
        {
            blo[0].x += 1;
            blo[0].y += 2;
            blo[1].x -= 1;
            blo[1].y += 2;
            blo[3].x += 1;
            blo[3].y -= 2;
            Judge(blo, ok);
            if (Emap[blo[0].x][blo[0].y + 2] || Emap[blo[0].x][blo[0].y - 2] || Emap[blo[3].x - 1][blo[3].y])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 2;
                }
        }
        else if (state == 2)
        {
            blo[0].x -= 1;
            blo[0].y += 2;
            blo[1].x -= 1;
            blo[1].y -= 2;
            blo[3].x += 1;
            blo[3].y += 2;
            Judge(blo, ok);
            if (Emap[blo[0].x + 1][blo[0].y] || Emap[blo[0].x - 1][blo[0].y] || Emap[blo[3].x][blo[3].y - 2])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 3;
                }
        }
        else
        {
            blo[0].x -= 1;
            blo[0].y -= 2;
            blo[1].x += 1;
            blo[1].y -= 2;
            blo[3].x -= 1;
            blo[3].y += 2;
            Judge(blo, ok);
            if (Emap[blo[0].x][blo[0].y + 2] || Emap[blo[0].x][blo[0].y - 2] || Emap[blo[3].x + 1][blo[1].y])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 0;
                }
        }
    }
    else if (m == 3)
    {
        if (state == 0)
        {
            blo[0].x += 1;
            blo[0].y += 2;
            blo[2].x -= 1;
            blo[2].y -= 2;
            blo[3].x -= 2;
            blo[3].y -= 4;
            Judge(blo, ok);
            if (Emap[blo[0].x][blo[0].y - 2] || Emap[blo[2].x][blo[2].y + 2])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 1;
                }
        }
        else
        {
            blo[0].x -= 1;
            blo[0].y -= 2;
            blo[2].x += 1;
            blo[2].y += 2;
            blo[3].x += 2;
            blo[3].y += 4;
            Judge(blo, ok);
            if (Emap[blo[0].x + 1][blo[0].y] || Emap[blo[2].x - 1][blo[2].y])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 0;
                }
        }
    }
    else if (m == 5)
    {
        if (state == 0)
        {
            blo[0].x += 2;
            blo[1].x += 1;
            blo[1].y += 2;
            blo[3].x -= 1;
            blo[3].y -= 2;
            Judge(blo, ok);
            if (Emap[blo[3].x][blo[3].y + 2])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 1;
                }
        }
        else if (state == 1)
        {
            blo[0].y += 4;
            blo[1].x -= 1;
            blo[1].y += 2;
            blo[3].x += 1;
            blo[3].y -= 2;
            Judge(blo, ok);
            if (Emap[blo[3].x - 1][blo[3].y])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 2;
                }
        }
        else if (state == 2)
        {
            blo[0].x -= 2;
            blo[1].x -= 1;
            blo[1].y -= 2;
            blo[3].x += 1;
            blo[3].y += 2;
            Judge(blo, ok);
            if (Emap[blo[3].x][blo[3].y - 2])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 3;
                }
        }
        else
        {
            blo[0].y -= 4;
            blo[1].x += 1;
            blo[1].y -= 2;
            blo[3].x -= 1;
            blo[3].y += 2;
            Judge(blo, ok);
            if (Emap[blo[3].x + 1][blo[3].y])
                ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                {
                    block[i] = blo[i];
                    state = 0;
                }
        }
    }
    else if (m == 6)
    {
        if (state == 0)
        {
            blo[0].y -= 4;
            blo[1].x += 1;
            blo[1].y += 2;
            blo[3].x -= 1;
            blo[3].y -= 2;
            Judge(blo, ok);
            if (Emap[blo[1].x][blo[1].y - 2])
                ok = 0;
            if (ok)
            {
                for (i = 0; i < 5; i++)
                    block[i] = blo[i];
                state = 1;
            }
        }
        else if (state == 1)
        {
            blo[0].x += 2;
            blo[1].x -= 1;
            blo[1].y += 2;
            blo[3].x += 1;
            blo[3].y -= 2;
            Judge(blo, ok);
            if (Emap[blo[1].x + 1][blo[1].y])
                ok = 0;
            if (ok)
            {
                for (i = 0; i < 5; i++)
                    block[i] = blo[i];
                state = 2;
            }
        }
        else if (state == 2)
        {
            blo[0].y += 4;
            blo[1].x -= 1;
            blo[1].y -= 2;
            blo[3].x += 1;
            blo[3].y += 2;
            Judge(blo, ok);
            if (Emap[blo[1].x][blo[1].y + 2])
                ok = 0;
            if (ok)
            {
                for (i = 0; i < 5; i++)
                    block[i] = blo[i];
                state = 3;
            }
        }
        else
        {
            blo[0].x -= 2;
            blo[1].x += 1;
            blo[1].y -= 2;
            blo[3].x -= 1;
            blo[3].y += 2;
            Judge(blo, ok);
            if (Emap[blo[1].x - 1][blo[1].y])
                ok = 0;
            if (ok)
            {
                for (i = 0; i < 5; i++)
                    block[i] = blo[i];
                state = 0;
            }
        }
    }
}
//***********判断是否可以消除***********//
//****Emap里如果是1 代表可以放下方块 否则消除********//
int is_can_cut()
{
    int i, j;
    int cut = 1;
    for (i = HEIGHT - 2; i > 1; i--)
    {
        bool ok = true;
        for (j = 1; j < SIDE - 1; j += 2)
            if (Emap[i][j] == 0)
            {
                ok = 0;
                break;
            }
        if (ok)
        {
            for (j = i; j > 1; j--)
                for (int k = 1; k < SIDE - 1; k += 2)
                    Emap[j][k] = Emap[j - 1][k];
            cut++;
            i++;
        }
    }
    for (i = HEIGHT - 2; i > 1; i--)
        for (int j = 1; j < SIDE - 1; j += 2)
        {
            SetCur(j, i);
            if (Emap[i][j])
                printf("*");
            else
                printf("  ");
        }
    return cut;
}
/**********清除当前方块**************/
//*****用SetCur定位 根据传入的block的坐标来消除******//
void Clear_Cube(Node *bblock)
{
    for (int i = 0; i < 5; i++)
    {
        if (bblock[i].x)
        {
            SetCur(bblock[i].y, bblock[i].x);
            cout << "  ";
        }
    }
}
//**********打印方块**********//
//*****用SetCur定位 根据传入的block的坐标来打印******//
void print_cube(Node *bblock)
{
    for (int i = 0; i < 5; i++)
    {
        if (bblock[i].x)
        {
            SetCur(bblock[i].y, bblock[i].x);
            cout << "*";
        }
    }
}
//**********移动**********//
//******监视键盘事件 根据事件不同给出不同操作的key*********//
void move(int m, int n)
{
    int i;
    if (n == 0)
    { //左
        for (i = 0; i < 5 && block[i].x; i++)
            if (block[i].y)
                block[i].y -= 2;
    }
    if (n == 1)
    { //右
        for (i = 0; i < 5 && block[i].x; i++)
            if (block[i].y)
                block[i].y += 2;
    }
    if (n == 2) //上
    {
        Exchange(m);
    }
    if (n == 3) //下
    {
        int ok = 1;
        while (ok)
        {
            for (i = 0; i < 5; i++)
                if (block[i].x)
                    if (Emap[block[i].x + 1][block[i].y])
                        ok = 0;
            if (ok)
                for (i = 0; i < 5; i++)
                    if (block[i].x)
                        block[i].x += 1;
        }
    }
}
//**********判断是否可以左移*********//
bool Leftable(Node *bblock)
{
    bool isable = true;
    int i;
    int min = 22;
    for (i = 0; i < 5 && bblock[i].x; i++)
        if (bblock[i].y < min)
            min = bblock[i].y;
    if (min - 2 < 1)
        isable = false;
    for (i = 0; i < 5 && bblock[i].x; i++)
        if (bblock[i].x)
            if (Emap[bblock[i].x][block[i].y - 2])
                isable = false;
    return isable;
}

bool Rightable(Node *bblock)
{
    bool isable = true;
    int i;
    int max = 0;
    for (i = 0; i < 5 && bblock[i].x; i++)
        if (bblock[i].y > max)
            max = bblock[i].y;
    if (max + 2 > 19)
        isable = false;
    for (i = 0; i < 5 && bblock[i].x; i++)
        if (bblock[i].x)
            if (Emap[bblock[i].x][block[i].y + 2])
                isable = false;
    return isable;
}
//**********下降一格*************//
void DropCube(Node *bblock)
{
    int i;
    for (i = 0; i < 5; i++)
        if (bblock[i].x)
            bblock[i].x += 1;
}
//*****判断是否到达底部*****//
bool isBottom(Node *bblock)
{
    for (int i = 0; i < 5; i++)
        if (bblock[i].x && Emap[bblock[i].x + 1][bblock[i].y])
            return true;
    return false;
}
//******到达底部 Emap的值赋为1*********//
void PrintMap(Node *bblock)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (bblock[i].x)
        {
            Emap[bblock[i].x][bblock[i].y] = 1;
            SetCur(bblock[i].y, bblock[i].x);
            cout << "*";
        }
    }
}
//*******打印游戏界面********//
void Print_Full_Map()
{
    int i, j;
    ME(I_map);
    for (i = 0; i < HEIGHT; i++)
    {
        if (i == 0 || i == 23)
        {
            for (j = 0; j < LENGTH; j++)
                printf("%c", I_map[i][j] = '-');
        }
        else
        {
            printf("%c", I_map[i][0] = '|');
            for (j = 1; j < SIDE - 1; j++)
                printf("%c", I_map[i][j] = ' ');
            printf("%c%c", I_map[i][j++] = '|', I_map[i][j++] = '|');
            for (; j < LENGTH - 1; j++)
                printf("%c", I_map[i][j] = ' ');
            printf("%c", I_map[i][j] = '|');
        }
        cout << endl;
    }
    SetCur(SIDE + 1, 10);
    printf("================");
    SetCur(SIDE + 1, 11);
    printf("Speed");
    SetCur(SIDE + 1, 13);
    printf("================");
    SetCur(SIDE + 1, 14);
    printf("Score");
    SetCur(SIDE + 1, 16);
    printf("================");
}
//*********是否游戏结束**********//
bool is_game_over(int num)
{
    int i, j;
    bool ok = true;
    print_block(num);
    //*******如果还有空间 不死 ok赋值false********//
    for (i = 0; i < 5; i++)
        if (block[i].x && Emap[block[i].x][block[i].y])
            ok = false;
    if (!ok)
    {
        char sl[20] = {"Game Over!!!"};
        for (i = 9; i < 12; i++)
        {
            if (i == 10)
            {
                int t = 0;
                for (j = 4; j < 18; j++)
                {
                    SetCur(j, i);
                    if (j >= 5 && j < 17)
                        printf("%c", sl[t++]);
                    else
                        printf(" ");
                }
            }
            else
            {
                for (j = 4; j < 18; j++)
                {
                    SetCur(j, i);
                    printf(" ");
                }
            }
        }
        SetCur(1, 12);
        printf(" Enter To Continue. ");
        SetCur(1, 13);
        printf("    Esc To Escape.  ");
        SetCur(1, 14);
        printf("                    ");
    }
    return ok;
}

main()
{
    srand(time(NULL));
    Print_Full_Map();
    Initmap();
    bool isover = true;
    bool ok = true;
    while (isover)
    {
        int Score = 0;
        int Speed = 0;
        int Num = (rand() % 7) * (rand() % 7) % 7;
        while (ok)
        {
            SetCur(SIDE + 4 + Speed, 12);
            cout << "    ";
            SetCur(SIDE + 4, 15);
            cout << "    ";
            SetCur(SIDE + 4 + Speed, 12);
            cout << "*";
            SetCur(SIDE + 4, 15);
            cout << Score;
            //Sleep(200);
            int num = Num;
            Num = (rand() % 7) * (rand() % 7) % 7;
            Clear_Cube(bl);
            Former_block(Num);
            print_block(num);
            state = 0;
            bool isbottom = true;
            while (isbottom)
            {
                Clear_Cube(block);
                if (GetAsyncKeyState(VK_LEFT) && Leftable(block))
                    move(num, 0);
                else if (GetAsyncKeyState(VK_RIGHT) && Rightable(block))
                    move(num, 1);
                else if (GetAsyncKeyState(VK_UP))
                    move(num, 2);
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    move(num, 3);
                    isbottom = false;
                }
                if (!isBottom(block))
                    DropCube(block);
                else
                    isbottom = false;
                print_cube(block);
                if (!isbottom)
                    PrintMap(block);
                Sleep(100 * (4 - Score / 80));
            }
            int cut = is_can_cut();
            if (cut)
            {
                Score += cut * 10;
                Speed = Score / 80;
            }
            ok = is_game_over(Num);
        }
        if (GetAsyncKeyState(VK_ESCAPE))
            isover = false;
        else if (GetAsyncKeyState(VK_RETURN))
        {
            system("cls");
            ok = true;
        }
    }
    return 0;
}