#include <raylib.h>
#include <vector>
#include <chrono>
#include "ball.h"
#include "player.h"
#include "square.h"
#include "triangle.h"

void ResetGame(Player& player, std::vector<Ball>& balls, std::vector<Square>& squares, std::vector<Triangle>& triangles, int& score)
{
    player.SetAlive();
    balls.clear();
    squares.clear();
    triangles.clear();
    score = 0;
}

int main()
{
    const Color darkBlue = {0, 0, 139, 255};
    const Color lightBlue = {173, 216, 230, 255};
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Geometry Dodge");
    SetTargetFPS(60);

    Player player;
    player.Init();

    std::vector<Ball> balls;
    std::vector<Square> squares;
    std::vector<Triangle> triangles;

    auto lastBallSpawnTime = std::chrono::steady_clock::now();
    auto lastSquareSpawnTime = std::chrono::steady_clock::now();
    auto lastTriangleSpawnTime = std::chrono::steady_clock::now();

    constexpr std::chrono::seconds spawnBallInterval(2);
    constexpr std::chrono::seconds spawnSquareInterval(5);
    constexpr std::chrono::seconds spawnTriangleInterval(9);

    int score = 0;
    int fontSize = 40;

    while (!WindowShouldClose())
    {
        if (!player.GetAlive()) // Spieler tot -> Game Over Screen + Restart-Option
        {
            BeginDrawing();
            ClearBackground(darkBlue);
            DrawRectangle(0, 0, screenWidth, 200, lightBlue);

            DrawText("GAME OVER", screenWidth / 2 - 150, 300, 50, RED);
            DrawText("Press [R] to Restart", screenWidth / 2 - 200, 400, 40, WHITE);
            DrawText(TextFormat("Final Score: %d", score), screenWidth / 2 - 150, 500, 40, WHITE);

            EndDrawing();

            if (IsKeyPressed(KEY_R))
            {
                ResetGame(player, balls, squares, triangles, score);
                lastBallSpawnTime = std::chrono::steady_clock::now();
                lastSquareSpawnTime = std::chrono::steady_clock::now();
                lastTriangleSpawnTime = std::chrono::steady_clock::now();
            }
            continue;
        }

        // --- Spiellogik ---
        auto currentTime = std::chrono::steady_clock::now();

        if (currentTime - lastBallSpawnTime >= spawnBallInterval)
        {
            balls.emplace_back(GetRandomValue(16, screenWidth - 16),
                               GetRandomValue(216, 350),
                               GetRandomValue(-2, 2),
                               GetRandomValue(-2, 2),
                               GetRandomValue(5, 15));
            lastBallSpawnTime = currentTime;
        }

        if (currentTime - lastSquareSpawnTime >= spawnSquareInterval)
        {
            int randomSize = GetRandomValue(50, 100);
            squares.emplace_back(GetRandomValue(randomSize + 1, screenWidth - randomSize - 1),
                                 GetRandomValue(200 + randomSize + 1, 350 - randomSize - 1),
                                 GetRandomValue(-2, 2),
                                 GetRandomValue(-2, 2),
                                 randomSize);
            lastSquareSpawnTime = currentTime;
        }

        if (currentTime - lastTriangleSpawnTime >= spawnTriangleInterval)
        {
            int randomSize = GetRandomValue(20, 50);
            triangles.emplace_back(GetRandomValue(randomSize / 2 + 1, screenWidth - randomSize / 2 - 1),
                                   GetRandomValue(200 + randomSize / 2 + 1, 350 - randomSize / 2 - 1),
                                   GetRandomValue(-7, 7),
                                   GetRandomValue(-7, 7),
                                   randomSize);
            lastTriangleSpawnTime = currentTime;
        }

        // Objekte updaten
        for (auto& ball : balls) ball.Update();
        for (auto& square : squares) square.Update();
        for (auto& triangle : triangles) triangle.Update();
        player.Update();

        // Kollisionen prüfen
        for (const auto& ball : balls)
        {
            if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), player.GetHitbox()))
            {
                player.PlayerGotHit();
                break;
            }
        }

        for (const auto& square : squares)
        {
            if (CheckCollisionRecs(square.GetHitbox(), player.GetHitbox()))
            {
                player.PlayerGotHit();
                break;
            }
        }

        for (const auto& triangle : triangles)
        {
            if (triangle.CheckCollision(player.GetHitbox()))
            {
                player.PlayerGotHit();
                break;
            }
        }

        if (player.GetAlive())
            score++;

        // --- Zeichnen ---
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawRectangle(0, 0, screenWidth, 200, lightBlue);

        DrawTextEx(GetFontDefault(), TextFormat("Score: %d", score), (Vector2){20, 10}, fontSize, 2, darkBlue);

        player.Draw();

        for (const auto& ball : balls) ball.Draw();
        for (const auto& square : squares) square.Draw();
        for (const auto& triangle : triangles) triangle.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
