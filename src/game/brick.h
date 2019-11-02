#ifndef GAME_BRICK_H
#define GAME_BRICK_H
class Brick
{
private:
    int Type;
    int Position[2];
    int Diretion;
    bool Shape[5][5];
    bool ShapeLibrary[7][5][5]= 
    {
        0,0,0,0,0,
        0,0,1,0,0,
        0,0,1,0,0,
        0,0,1,0,0,
        0,0,1,0,0,

        0,0,0,0,0,
        0,0,1,0,0,
        0,0,1,1,0,
        0,0,0,1,0,
        0,0,0,0,0,

        0,0,0,0,0,
        0,0,1,0,0,
        0,1,1,0,0,
        0,1,0,0,0,
        0,0,0,0,0,

        0,0,1,0,0,
        0,0,1,0,0,
        0,0,1,1,0,
        0,0,0,0,0,
        0,0,0,0,0,

        0,0,1,0,0,
        0,0,1,0,0,
        0,1,1,0,0,
        0,0,0,0,0,
        0,0,0,0,0,

        0,0,0,0,0,
        0,0,1,0,0,
        0,1,1,1,0,
        0,0,0,0,0,
        0,0,0,0,0,

        0,0,0,0,0,
        0,0,1,1,0,
        0,0,1,1,0,
        0,0,0,0,0,
        0,0,0,0,0,
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