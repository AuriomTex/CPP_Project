#ifndef BALL_H
#define BALL_H

#include <raylib.h>

class Ball
{
public:
    Ball(int x, int y, int speedX, int speedY, int radius);
    void Update();
    void Draw() const;
    Vector2 GetPosition() const;
    float GetRadius() const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int radius;
};

#endif