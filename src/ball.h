#pragma once

class Ball
{
public:
    Ball(int x, int y);
    void Update();
    void Draw() const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int radius;
};