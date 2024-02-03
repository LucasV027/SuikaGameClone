#pragma once

#include "../Utils/Vec2Float.h"

enum class FruitType
{
    None,
    Red,
    Purple,
    Orange,
    Yellow,
};

class Fruit
{
public:
    // Constructors
    Fruit(int x, int y, float rad);
    Fruit(int x, int y, int num);
    Fruit(int x, int y, FruitType fT);

    // Getters
    Vec2Float getPosition() const;
    float getRadius() const;
    FruitType getType() const;

    // Physics logic
    void setPosition(Vec2Float newPosition);
    void changeType(FruitType newType);
    void updatePosition(float dt);
    void accelerate(Vec2Float addedAcceleration);
    void resetVelocity();

private:
    FruitType fruit;

    Vec2Float currentPosition;
    Vec2Float lastPosition;
    Vec2Float acceleration;
    unsigned int weight;
    float radius;
};
