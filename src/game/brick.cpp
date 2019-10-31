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