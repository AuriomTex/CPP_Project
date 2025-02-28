#pragma once

class Player
{
public:
    Player();
    ~Player();

    void Draw() const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    Texture2D playerDown;
};