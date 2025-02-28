#include "player.h"
#include <iostream>  // Für einfache Fehlermeldungen

Player::Player()
        : x(500)
        , y(900)
        , speedX(5)
        , speedY(5)
        , texture{}
        , alive(true)
{
}

Player::~Player()
{
    UnloadTexture(texture);
}

void Player::Init()
{
    texture = LoadTexture("../assets/Sprite/SpritesC++/PlayerDown.png");
    if (texture.id == 0) {
        std::cerr << "Fehler: player.png konnte nicht geladen werden!" << std::endl;
    }
}

void Player::Update()
{
    bool movingHorizontal = false;
    bool movingVertical = false;
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();


    if (IsKeyDown(KEY_RIGHT)) {
        x += speedX;
        movingHorizontal = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
        x -= speedX;
        movingHorizontal = true;
    }
    if (IsKeyDown(KEY_DOWN)) {
        y += speedY;
        movingVertical = true;
    }
    if (IsKeyDown(KEY_UP)) {
        y -= speedY;
        movingVertical = true;
    }

    if (movingHorizontal && movingVertical) {
        x = (IsKeyDown(KEY_RIGHT) ? x - speedX * 0.5f : x + speedX * 0.5f);
        y = (IsKeyDown(KEY_DOWN) ? y - speedY * 0.5f : y + speedY * 0.5f);
    }

    if ((x >= screenWidth) || (x <= 0)) {
        x = (x >= screenWidth) ? 0 : screenWidth;
    }

    if ((y >= screenHeight) || (y <= 200)) {
        y = (y >= screenHeight) ? 200 : screenHeight;
    }

}

void Player::Draw() const
{
    if (texture.id != 0) {
        DrawTextureEx(texture, { (float)x, (float)y }, 0.0f, 2.5f, WHITE);
    } else {
        DrawRectangle(x, y, 50, 50, RED);
    }
}

int Player::GetX() const
{
    return x;
}

int Player::GetY() const
{
    return y;
}

bool Player::GetAlive() const
{
    return alive;
}

void Player::PlayerGotHit()
{
    alive = false;
}

Rectangle Player::GetHitbox() const
{
    float width = texture.width * 2.5f;
    float height = texture.height * 2.5f;
    return Rectangle{ (float)x, (float)y, width, height };
}