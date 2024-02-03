#include "Fruit.h"

Fruit::Fruit(int x, int y, float rad) : fruit(FruitType::Red),
                                        radius(rad),
                                        currentPosition(Vec2Float(x, y)),
                                        lastPosition(Vec2Float(x, y)),
                                        acceleration(Vec2Float(0, 0)),
                                        weight(1.0) {}

Fruit::Fruit(int x, int y, int num) : Fruit(x, y, FruitType(num)) {}

Fruit::Fruit(int x, int y, FruitType fT) : currentPosition(Vec2Float(x, y)),
                                           lastPosition(Vec2Float(x, y)),
                                           acceleration(Vec2Float(0, 0)),
                                           fruit(fT)
{
    radius = 7.0f + std::pow((int)fT, 3);
    weight = radius * 2.0f;
}

Vec2Float Fruit::getPosition() const { return currentPosition; }
float Fruit::getRadius() const { return radius; }
FruitType Fruit::getType() const { return fruit; }

void Fruit::setPosition(Vec2Float newPosition) { currentPosition = newPosition; }

void Fruit::changeType(FruitType newType)
{
    fruit = newType;
    radius = 7.0f + std::pow((int)newType, 3);
    weight = radius * 2.0f;
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

void Fruit::resetVelocity() { lastPosition = currentPosition; }
