#include "Solver.h"

Solver::Solver() : fruits(nullptr) {}

void Solver::linkVector(std::vector<Fruit> *ptr) { fruits = ptr; }

void Solver::update(float dt)
{
    applyGravity();
    //  checkCollisions(dt / 8.f);
    applyConstraint();
    // updatePositions(dt);
}

void Solver::applyGravity()
{
    for (Fruit &fruit : *fruits)
    {
        Vec2Float fruitPosition = fruit.getPosition();
        fruit.setPosition(fruitPosition + GRAVITY);

        // fruit.accelerate(GRAVITY);
    }
}

void Solver::applyConstraint()
{
    for (Fruit &fruit : *fruits)
    {
        Vec2Float fruitPosition = fruit.getPosition();

        if (fruitPosition.getY() >= 400)
        {
            fruit.setPosition(Vec2Float(fruitPosition.getX(), 400));
        }
    }
}

void Solver::updatePositions(float dt)
{
    for (Fruit &fruit : *fruits)
    {
        fruit.updatePosition(dt);
    }
}
