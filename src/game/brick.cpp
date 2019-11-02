#include <cstdlib>
#include <cstring>
#include "Brick.h"
Brick::Brick()
{
    this->Type = rand() % 7;
    memcpy(this->Shape, this->ShapeLibrary[this->Type], 25);
}
int Brick::GetType()
{
    return this->Type;
}
int* Brick::GetPosition()
{
    return this->Position;
}
int Brick::GetDirection()
{
    return this->Diretion;
}
bool Brick::GetShapeValue(int row, int column)
{
    return this->Shape[row][column];
}
void Brick::Rotate(bool clockwise)
{
    bool NextShape[5][5];
    if(clockwise)
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                NextShape[j][4-i] = Shape[i][j];
    else
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                NextShape[j-4][i] = Shape[i][j];
    memcpy(this->Shape, NextShape, sizeof(this->Shape));
}