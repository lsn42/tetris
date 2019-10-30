#include <Brick.h>
class Game
{
private:
    bool map[10][20] = {0};
    int score;
    Brick CurrentBrick, NextBrick;
public:
    Game()
    {
        this->score = 0;
        
    }
};