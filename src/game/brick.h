#ifndef GAME_BRICK_H
#define GAME_BRICK_H
class Brick
{
private:
    int Type;
    //0~6, represent brick type
    int Position[2];
    //central point of the shape to the position of map
    int Diretion;
    //0~3, represent four diretion
    bool Shape[5][5];
    //the brick shape
    bool ShapeLibrary[7][5][5]= 
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
public:
    Brick();
    int GetType();
    int* GetPosition();
    int GetDirection();
    bool GetShapeValue(int row, int column);
    void Rotate(bool clockwise);
};
#endif