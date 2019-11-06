#ifndef GAME_BRICK_H
#define GAME_BRICK_H
// all shapes of tetris
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
    //0~6, represent brick type
    int Type;
    //shape to the position of map
    int Position[2];
    //0~3, represent four direction
    int Diretion;
    //the brick shape
    bool Shape[5][5];
public:
    Brick();
    int GetType();
    int* GetPosition();
    int GetDirection();
    bool GetShapeValue(int row, int column);
    // change brick position
    void Move(int x, int y);
    // rotate the shape, change direction
    void Rotate(bool clockwise);
};
#endif