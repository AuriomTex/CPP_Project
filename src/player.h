#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player {
public:
    Player();
    ~Player();

    void Init();
    void Update();
    void Draw() const;
    int GetX() const;
    int GetY() const;
    bool GetAlive() const;
    void PlayerGotHit();
    Rectangle GetHitbox() const;

private:
    int x, y;
    int speedX, speedY;
    bool alive;
    Texture2D texture;
};

#endif