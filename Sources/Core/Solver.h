#pragma once

#include <vector>
#include "Fruit.h"
#include <iostream>

#include "../Utils/Vec2Float.h"

const Vec2Float GRAVITY(0.f, 1000.f);

class Solver
{
public:
    Solver();
    void linkVector(std::vector<Fruit> *ptr);
    void update(float dt);

private:
    void applyGravity();
    void checkCollisionsUpgradeFruit();
    void checkCollisions(float dt);
    void applyConstraint();
    void updatePositions(float dt);

private:
    std::vector<Fruit> *fruits;
};
