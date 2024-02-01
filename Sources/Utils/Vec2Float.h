#pragma once

#include <string>

class Vec2Float
{
private:
    int x;
    int y;

public:
    // Constructors
    Vec2Float();
    Vec2Float(int z);
    Vec2Float(int x, int y);

    // Getters
    float getX() const;
    float getY() const;

    // Operators
    Vec2Float operator+(Vec2Float other) const;
    Vec2Float operator-(Vec2Float other) const;
    Vec2Float operator*(float lambda) const;

    // Display
    std::string toString() const;
};
