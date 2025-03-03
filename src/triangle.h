#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <raylib.h>

class Triangle
{
public:
    Triangle(int x, int y, int speedX, int speedY, int size);
    void Update();
    void Draw() const;
    Vector2 GetPosition() const;
    float GetSize() const;
    Vector2 GetVertex(int index) const;
    bool CheckCollision(const Rectangle& playerHitbox) const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int size;
};

#endif
