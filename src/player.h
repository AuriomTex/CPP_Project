#pragma once

class Player
{
public:
    Player();
    void Draw() const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
};