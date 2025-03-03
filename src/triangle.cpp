#include "triangle.h"
#include <raylib.h>
#include <cmath>

Triangle::Triangle(int x, int y, int speedX, int speedY, int size)
        : x(x)
        , y(y)
        , speedX(speedX)
        , speedY(speedY)
        , size(size)
{
}

void Triangle::Update()
{
    x += speedX;
    y += speedY;


    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if ((x + size/2 >= screenWidth) || (x <= 0 + size/2)) {
        speedX *= -1;
    }


    if ((y + size/2 >= screenHeight) || (y <= 200 + size/2)) {
        speedY *= -1;
    }
}

void Triangle::Draw() const
{
    Vector2 v1 = GetVertex(0);
    Vector2 v2 = GetVertex(1);
    Vector2 v3 = GetVertex(2);

    DrawTriangle(v1, v2, v3, WHITE);
}

Vector2 Triangle::GetPosition() const
{
    return Vector2{ (float)x, (float)y };
}

float Triangle::GetSize() const
{
    return (float)size;
}

Vector2 Triangle::GetVertex(int index) const
{
    switch (index)
    {
        case 0: return Vector2{ (float)x, (float)(y - size / 2) };
        case 1: return Vector2{ (float)(x - size / 2), (float)(y + size / 2) };
        case 2: return Vector2{ (float)(x + size / 2), (float)(y + size / 2) };
        default: return Vector2{0, 0};
    }
}


bool Triangle::CheckCollision(const Rectangle& playerHitbox) const
{
    Vector2 v1 = GetVertex(0);
    Vector2 v2 = GetVertex(1);
    Vector2 v3 = GetVertex(2);

    Rectangle bounds = {
            (float)(x - size / 2),
            (float)(y - size / 2),
            (float)size,
            (float)size
    };

    return CheckCollisionRecs(bounds, playerHitbox);
}
