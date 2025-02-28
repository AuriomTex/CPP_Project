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
    int playerX = 0;
    int playerY = 0;
    bool playerAlive = true;

    Player player;

    std::vector<Ball> balls;

    auto lastSpawnTime = std::chrono::steady_clock::now();
    constexpr std::chrono::seconds spawnInterval(1); // 1 seconds interval

    player.Init();

    while (!WindowShouldClose())
    {

        for (const auto& ball : balls)
        {
            if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), player.GetHitbox()))
            {
                player.PlayerGotHit();
                break;
            }
        }

        if (!playerAlive)
        {
            DrawText("GAME OVER", screenWidth / 2, 100, 50, RED);
            EndDrawing();
            continue;
        }

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

        playerX = player.GetX();
        playerY = player.GetY();
        playerAlive = player.GetAlive();
        if(playerAlive)score++;


        // Update and draw all balls
        for (auto& ball : balls)
        {
            ball.Update(playerX, playerY);
        }

        BeginDrawing();
        ClearBackground(darkBlue);

        DrawRectangle(0, 0, screenWidth, 200, lightBlue);

        DrawTextEx(GetFontDefault(), TextFormat("Score: %d", score), (Vector2){20, 10}, fontSize, 2, darkBlue);

        player.Draw();

        if(IsKeyDown(KEY_RIGHT)) player.Update();
        if(IsKeyDown(KEY_LEFT)) player.Update();
        if(IsKeyDown(KEY_UP)) player.Update();
        if(IsKeyDown(KEY_DOWN)) player.Update();

        for (const auto& ball : balls)
        {
            ball.Draw();
        }

        EndDrawing();
    }

    CloseWindow();
}