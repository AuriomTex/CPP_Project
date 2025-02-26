#include <raylib.h>
#include "ball.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    Ball ball(100, 100);
    Ball newBall(700, 500);

    InitWindow(screenWidth, screenHeight, "Dodging Objects");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(darkGreen);
        ball.Draw();
        newBall.Draw();
        EndDrawing();
    }

    CloseWindow();
}