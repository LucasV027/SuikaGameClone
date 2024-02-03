#include "Solver.h"

Solver::Solver() : fruits(nullptr) {}

void Solver::linkVector(std::vector<Fruit> *ptr) { fruits = ptr; }

void Solver::update(float dt)
{
    for (int i = 0; i < 8; i++)
    {
        applyGravity();
        checkCollisionsUpgradeFruit();
        checkCollisions(dt / 8.f);
        applyConstraint();
        updatePositions(dt / 8.f);
    }
}

void Solver::applyGravity()
{
    for (Fruit &fruit : *fruits)
    {
        fruit.accelerate(GRAVITY);
    }
}

void Solver::checkCollisionsUpgradeFruit()
{
    for (Fruit &fruit1 : *fruits)
    {
        for (Fruit &fruit2 : *fruits)
        {
            // Same fruit check and different fruit types check
            if (&fruit1 == &fruit2 || fruit1.getType() != fruit2.getType())
            {
                continue;
            }

            const Vec2Float v = fruit1.getPosition() - fruit2.getPosition();
            const float dist = v.length();
            const float min_dist = fruit1.getRadius() + fruit2.getRadius();

            if ((dist * dist) < (min_dist * min_dist))
            {
                fruit2.changeType(FruitType::None);

                Vec2Float newPosition = ((fruit1.getPosition() + fruit2.getPosition()) / 2.f);
                fruit1 = Fruit(newPosition.getX(), newPosition.getY(), (int)fruit1.getType() + 1);
                //   fruit1.setPosition(newPosition);
                // fruit1.resetVelocity();
                //  fruit1.changeType(FruitType((int)fruit1.getType() + 1));
            }
        }
    }

    for (auto it = fruits->begin(); it != fruits->end();)
    {
        if (it->getType() == FruitType::None)
        {
            it = fruits->erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Solver::checkCollisions(float dt)
{
    const float response_coef = 0.75f;

    for (Fruit &fruit1 : *fruits)
    {
        for (Fruit &fruit2 : *fruits)
        {
            if (&fruit1 == &fruit2)
            {
                continue;
            }

            const Vec2Float v = fruit1.getPosition() - fruit2.getPosition();
            const float dist = v.length();
            const float min_dist = fruit1.getRadius() + fruit2.getRadius();

            if ((dist * dist) < (min_dist * min_dist))
            {
                const Vec2Float n = v / dist;
                const float delta = 0.5f * response_coef * (dist - min_dist);
                const float mass_ratio_1 = fruit1.getRadius() / (fruit1.getRadius() + fruit2.getRadius());
                const float mass_ratio_2 = fruit2.getRadius() / (fruit1.getRadius() + fruit2.getRadius());
                fruit1.setPosition(fruit1.getPosition() - (n * mass_ratio_1 * delta));
                fruit2.setPosition(fruit2.getPosition() + (n * mass_ratio_2 * delta));
            }
        }
    }
}

void Solver::applyConstraint()
{
    // Tmp
    const int bgX = 50;
    const int bgY = 50;
    const int bgWidth = 700;
    const int bgHeight = 700;
    //

    for (Fruit &fruit : *fruits)
    {
        const Vec2Float fruitPosition = fruit.getPosition();
        const float fruitRadius = fruit.getRadius();

        // Top and Bottom
        if (fruitPosition.getY() >= bgY + bgHeight - fruitRadius) // Bottom side
        {
            fruit.setPosition(Vec2Float(fruit.getPosition().getX(), bgY + bgHeight - fruitRadius));
        }
        else if (fruitPosition.getY() <= bgY + fruitRadius) // Top side
        {
            fruit.setPosition(Vec2Float(fruit.getPosition().getX(), bgY + fruitRadius));
        }

        // Right and Left
        if (fruitPosition.getX() <= bgX + fruitRadius) // Left side
        {
            fruit.setPosition(Vec2Float(bgX + fruitRadius, fruit.getPosition().getY()));
        }
        else if (fruitPosition.getX() >= bgX + bgWidth - fruitRadius) // Right side
        {
            fruit.setPosition(Vec2Float(bgX + bgWidth - fruitRadius, fruit.getPosition().getY()));
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
