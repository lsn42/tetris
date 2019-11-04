#include <cstdlib>
#include <cstring>
#include "Brick.h"
Brick::Brick()
{
    this->Type = rand() % 7;
    //choose a random type
    this->Position[0] = 4;
    if(this->Type < 3)
        this->Position[1] = 2;
    else
        this->Position[1] = 1;
    //place brick in different position for different type
    this->Diretion = 0;
    //initial diretion is 0
    memcpy(this->Shape, ShapeLibrary[this->Type], 25);
    //get shape form library
}
int Brick::GetType()
{
    return this->Type;
}
int* Brick::GetPosition()
{
    int *_return = new int[2];
    memcpy(_return, this->Position, sizeof(int) * 2);
    return _return;
}
int Brick::GetDirection()
{
    return this->Diretion;
}
void Brick::Move(int x, int y)
{
    this->Position[0] += x;
    this->Position[1] += y;
}
bool Brick::GetShapeValue(int row, int column)
{
    return this->Shape[row][column];
}
void Brick::Rotate(bool clockwise)
{
    if(this->Type != 6)
    {
        bool NextShape[5][5];
        if(clockwise)//clockwise
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j)
                    NextShape[j][4-i] = Shape[i][j];
        else//anticlockwise
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j)
                    NextShape[4-j][i] = Shape[i][j];
        memcpy(this->Shape, NextShape, sizeof(this->Shape));
        this->Diretion = (this->Diretion + (clockwise?-1:1) + 4) % 4;
        //change diretion after rotate
    }
}