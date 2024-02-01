#include "Fruit.h"

Fruit::Fruit(int x, int y) : fruit(FruitType::Cherry),
                             radius(1.0),
                             currentPosition(Vec2Float(x, y)),
                             lastPosition(Vec2Float(x, y)),
                             acceleration(Vec2Float(0, 0)),
                             weight(1.0) {}

Vec2Float Fruit::getPosition() const
{
    return currentPosition;
}

void Fruit::setPosition(Vec2Float newPosition)
{
    currentPosition = newPosition;
}

void Fruit::updatePosition(float dt)
{
    const Vec2Float velocity = currentPosition - lastPosition;
    lastPosition = currentPosition;
    currentPosition = currentPosition + velocity + acceleration * dt * dt;
    acceleration = 0;
}

void Fruit::accelerate(Vec2Float addedAcceleration)
{
    acceleration = acceleration + addedAcceleration;
}