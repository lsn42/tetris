#ifndef GAME_BRICK_H
#define GAME_BRICK_H
const bool ShapeLibrary[7][5][5]= 
{
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
    //long stick
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    //L
    0,0,1,0,0,
    0,0,1,0,0,
    0,1,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    //another L
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,1,1,0,
    0,0,0,1,0,
    0,0,0,0,0,
    //one of the shapes
    0,0,0,0,0,
    0,0,1,0,0,
    0,1,1,0,0,
    0,1,0,0,0,
    0,0,0,0,0,
    //one of the shapes
    0,0,0,0,0,
    0,0,1,0,0,
    0,1,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    //one of the shapes
    0,0,0,0,0,
    0,0,1,1,0,
    0,0,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    //square
};
class Brick
{
private:
    int Type;
    //0~6, represent brick type
    int Position[2];
    //shape to the position of map
    int Diretion;
    //0~3, represent four diretion
    bool Shape[5][5];
    //the brick shape
public:
    Brick();
    int GetType();
    int* GetPosition();
    int GetDirection();
    void Move(int x, int y);
    bool GetShapeValue(int row, int column);
    void Rotate(bool clockwise);
};
#endif