#include "player.h"
#include <iostream>

Player::Player()
        : x(500), y(900), speedX(5), speedY(5),
          alive(true), currentDirection(Direction::Down),
          currentFrame(0), frameTime(0.1f), frameTimer(0.0f)
{
}

Player::~Player()
{
    for (int i = 0; i < frameCount; i++) {
        UnloadTexture(walkDownFrames[i]);
        UnloadTexture(walkUpFrames[i]);
        UnloadTexture(walkLeftFrames[i]);
        UnloadTexture(walkRightFrames[i]);
    }
}

void Player::Init()
{
    walkDownFrames[0] = LoadTexture("../assets/PlayerDown1.png");
    walkDownFrames[1] = LoadTexture("../assets/PlayerDown2.png");
    walkDownFrames[2] = LoadTexture("../assets/PlayerDown3.png");
    walkDownFrames[3] = LoadTexture("../assets/PlayerDown4.png");

    walkUpFrames[0] = LoadTexture("../assets/PlayerUp1.png");
    walkUpFrames[1] = LoadTexture("../assets/PlayerUp2.png");
    walkUpFrames[2] = LoadTexture("../assets/PlayerUp3.png");
    walkUpFrames[3] = LoadTexture("../assets/PlayerUp4.png");

    walkLeftFrames[0] = LoadTexture("../assets/PlayerLeft1.png");
    walkLeftFrames[1] = LoadTexture("../assets/PlayerLeft2.png");
    walkLeftFrames[2] = LoadTexture("../assets/PlayerLeft3.png");
    walkLeftFrames[3] = LoadTexture("../assets/PlayerLeft4.png");

    walkRightFrames[0] = LoadTexture("../assets/PlayerRight1.png");
    walkRightFrames[1] = LoadTexture("../assets/PlayerRight2.png");
    walkRightFrames[2] = LoadTexture("../assets/PlayerRight3.png");
    walkRightFrames[3] = LoadTexture("../assets/PlayerRight4.png");
}

void Player::Update()
{
    bool movingHorizontal = false;
    bool movingVertical = false;

    int moveX = 0;
    int moveY = 0;

    if (IsKeyDown(KEY_RIGHT)) {
        moveX += speedX;
        currentDirection = Direction::Right;
        movingHorizontal = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
        moveX -= speedX;
        currentDirection = Direction::Left;
        movingHorizontal = true;
    }
    if (IsKeyDown(KEY_DOWN)) {
        moveY += speedY;
        currentDirection = Direction::Down;
        movingVertical = true;
    }
    if (IsKeyDown(KEY_UP)) {
        moveY -= speedY;
        currentDirection = Direction::Up;
        movingVertical = true;
    }

    if (movingHorizontal && movingVertical) {
        moveX /= 1.5f;
        moveY /= 1.5f;
    }

    x += moveX;
    y += moveY;
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if (x >= screenWidth - 40) x = screenWidth - 40;
    if (x <= 0) x = 0;
    if (y >= screenHeight - 40) y = screenHeight - 40;
    if (y <= 200) y = 200;

    if (movingHorizontal || movingVertical) {
        frameTimer += GetFrameTime();
        if (frameTimer >= frameTime) {
            frameTimer = 0.0f;
            currentFrame = (currentFrame + 1) % frameCount;
        }
    } else {
        currentFrame = 0;
    }
}

void Player::Draw() const
{
    const Texture2D* currentTexture = nullptr;

    switch (currentDirection) {
        case Direction::Down:
            currentTexture = &walkDownFrames[currentFrame];
            break;
        case Direction::Up:
            currentTexture = &walkUpFrames[currentFrame];
            break;
        case Direction::Left:
            currentTexture = &walkLeftFrames[currentFrame];
            break;
        case Direction::Right:
            currentTexture = &walkRightFrames[currentFrame];
            break;
    }

    if (currentTexture && currentTexture->id != 0) {
        DrawTextureEx(*currentTexture, { (float)x, (float)y }, 0.0f, 2.5f, WHITE);
    } else {
        DrawRectangle(x, y, 50, 50, RED);
    }
}

bool Player::GetAlive() const
{
    return alive;
}

void Player::SetAlive()
{
    alive = true;
    x = 500;
    y = 900;
}

void Player::PlayerGotHit()
{
    alive = false;
}

Rectangle Player::GetHitbox() const
{
    float width = walkDownFrames[0].width * 2.5f;
    float height = walkDownFrames[0].height * 2.5f;
    return Rectangle{ (float)x, (float)y, width, height };
}
