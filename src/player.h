#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

enum class Direction { Down, Up, Left, Right };

class Player {
public:
    Player();
    ~Player();

    void Init();
    void Update();
    void Draw() const;
    bool GetAlive() const;
    void SetAlive();
    void PlayerGotHit();
    Rectangle GetHitbox() const;

private:
    int x, y;
    int speedX, speedY;
    bool alive;
    Direction currentDirection;

    static constexpr int frameCount = 4;  // Anzahl der Frames pro Richtung
    int currentFrame;
    float frameTime;
    float frameTimer;

    Texture2D walkDownFrames[frameCount];
    Texture2D walkUpFrames[frameCount];
    Texture2D walkLeftFrames[frameCount];
    Texture2D walkRightFrames[frameCount];
};

#endif
