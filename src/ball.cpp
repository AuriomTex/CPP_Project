#include "ball.h"
#include "player.h"
#include <raylib.h>
#include <iostream>

Ball::Ball(int x, int y, int speedX, int speedY, int radius)
    : x(x)
    , y(y)
    , speedX(speedX)
    , speedY(speedY)
    , radius(radius)
{
}

void Ball::Update(int px, int py)
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

Vector2 Ball::GetPosition() const
{
    return Vector2{ (float)x, (float)y };
}

float Ball::GetRadius() const
{
    return (float)radius;
}

