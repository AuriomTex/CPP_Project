#include <raylib.h>
#include <vector>
#include <chrono>
#include "ball.h"
#include "player.h"

int main()
{
    const Color darkBlue = {0, 0, 139, 255};
    const Color lightBlue = {173, 216, 230, 255};
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Geometry Dodge");
    SetTargetFPS(60);

    int randomX = 0;
    int randomY = 0;
    int randomSpeedX = 0;
    int randomSpeedY = 0;
    int randomRadius = 0;

    int fontSize = 40;
    int score = 0;

    Player player;

    std::vector<Ball> balls;

    auto lastSpawnTime = std::chrono::steady_clock::now();
    constexpr std::chrono::seconds spawnInterval(1); // 1 seconds interval

    while (!WindowShouldClose())
    {
        // Check if 1 second have passed
        auto currentTime = std::chrono::steady_clock::now();
        if (currentTime - lastSpawnTime >= spawnInterval)
        {
            randomX = GetRandomValue(26, screenWidth - 26);
            randomY = GetRandomValue(226, 350);
            randomSpeedX = GetRandomValue(-5, 5);
            randomSpeedY = GetRandomValue(-5, 5);
            randomRadius = GetRandomValue(5, 25);
            balls.push_back(Ball(randomX, randomY, randomSpeedX, randomSpeedY, randomRadius)); // Spawn a new ball
            lastSpawnTime = currentTime; // Update the spawn time
        }

        // Update and draw all balls
        for (auto& ball : balls)
        {
            ball.Update();
        }

        score++;

        BeginDrawing();
        ClearBackground(darkBlue);

        DrawRectangle(0, 0, screenWidth, 200, lightBlue);

        DrawTextEx(GetFontDefault(), TextFormat("Score: %d", score), (Vector2){20, 10}, fontSize, 2, darkBlue);

        player.Draw();

        for (const auto& ball : balls)
        {
            ball.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
}