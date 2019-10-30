#include <cstdlib>
class Brick
{
private:
    int type;
    int position[2];
    int diretion;
    bool shape[4][4];
public:
    Brick()
    {
        this->type = rand() % 7;
        switch(this->type)
        {
        }
    }
};