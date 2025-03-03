#ifndef SQUARE_H
#define SQUARE_H

#include <raylib.h>

class Square
{
public:
    Square(int x, int y, int speedX, int speedY, int size);
    void Update();
    void Draw() const;
    Rectangle GetHitbox() const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int size;
};

#endif