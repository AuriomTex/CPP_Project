#include "square.h"
#include <raylib.h>

Square::Square(int x, int y, int speedX, int speedY, int size)
        : x(x)
        , y(y)
        , speedX(speedX)
        , speedY(speedY)
        , size(size)
{
}

void Square::Update()
{
    x += speedX;
    y += speedY;

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if ((x + size >= screenWidth) || (x <= 0)) {
        speedX *= -1;
    }

    if ((y + size >= screenHeight) || (y <= 200)) {
        speedY *= -1;
    }
}

void Square::Draw() const
{
    DrawRectangle(x, y, size, size, WHITE);
}

Rectangle Square::GetHitbox() const
{
    return Rectangle{ (float)x, (float)y, (float)size, (float)size };
}
