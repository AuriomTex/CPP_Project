#include "player.h"
#include <raylib.h>

Player::Player()
    : x(500)
    , y(900)
    , speedX(5)
    , speedY(5)
{
    playerDown = LoadTexture("../assets/Sprite/SpritesC++/PlayerDown.png");
}

Player::~Player()
{
    UnloadTexture(playerDown);  // Textur wieder freigeben beim Zerstören des Objekts
}

void Player::Draw() const
{
    DrawTexture(playerDown, x, y, WHITE);
}