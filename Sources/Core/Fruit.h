#pragma once

#include "../Utils/Vec2Float.h"

enum class FruitType
{
    Cherry,
    Strawberry,

};

class Fruit
{
public:
    // Constructors
    Fruit(int x, int y);

    // Getters
    Vec2Float getPosition() const;

    // Physics logic
    void setPosition(Vec2Float newPosition);
    void updatePosition(float dt);
    void accelerate(Vec2Float addedAcceleration);

private:
    FruitType fruit;

    Vec2Float currentPosition;
    Vec2Float lastPosition;
    Vec2Float acceleration;
    unsigned int weight;
    float radius;
};
