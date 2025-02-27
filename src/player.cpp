#include "player.h"
#include <raylib.h>

Player::Player()
    : x(900)
    , y(900)
    , speedX(5)
    , speedY(5)
{
}

void Player::Draw() const
{
    DrawTexture();
}