#pragma once

#include <math.h>
#include <string>

class Vec2Float
{
private:
    float x;
    float y;

public:
    // Constructors
    Vec2Float();
    Vec2Float(float z);
    Vec2Float(float x, float y);

    // Getters
    float getX() const;
    float getY() const;

    // Operators
    Vec2Float operator+(Vec2Float other) const;
    Vec2Float operator-(Vec2Float other) const;
    Vec2Float operator*(float lambda) const;
    Vec2Float operator/(float lambda) const;
    Vec2Float &operator=(float n);
    Vec2Float &operator=(const Vec2Float &other);

    // Logic
    float length() const;

    // Display
    std::string toString() const;
};
