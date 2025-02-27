#include "ball.h"
#include <raylib.h>

Ball::Ball(int x, int y, int speedX, int speedY, int radius)
    : x(x)
    , y(y)
    , speedX(speedX)
    , speedY(speedY)
    , radius(radius)
{
}

void Ball::Update() 
{
    x += speedX;
    y += speedY;
    
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    
    if ((x + radius >= screenWidth) || (x - radius <= 0)) {
        speedX *= -1;
    }
    
    if ((y + radius >= screenHeight) || (y - radius <= 200)) {
        speedY *= -1;
    }
}

void Ball::Draw() const
{
    DrawCircle(x, y, radius, WHITE);
}

