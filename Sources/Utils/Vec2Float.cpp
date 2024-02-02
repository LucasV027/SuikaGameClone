#include "Vec2Float.h"

Vec2Float::Vec2Float() : x(0), y(0) {}

Vec2Float::Vec2Float(float _z) : x(_z), y(_z) {}

Vec2Float::Vec2Float(float _x, float _y) : x(_x), y(_y) {}

float Vec2Float::getX() const { return this->x; }
float Vec2Float::getY() const { return this->y; }

Vec2Float Vec2Float::operator+(Vec2Float other) const
{
    return Vec2Float(this->x + other.x, this->y + other.y);
}

Vec2Float Vec2Float::operator-(Vec2Float other) const
{
    return Vec2Float(this->x - other.x, this->y - other.y);
}

Vec2Float Vec2Float::operator*(float lambda) const
{
    return Vec2Float(this->x * lambda, this->y * lambda);
}

Vec2Float Vec2Float::operator/(float lambda) const
{
    return Vec2Float(this->x / lambda, this->y / lambda);
}

Vec2Float &Vec2Float::operator=(float n)
{
    this->x = n;
    this->y = n;
    return *this;
}

Vec2Float &Vec2Float::operator=(const Vec2Float &other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

float Vec2Float::length() const
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

std::string Vec2Float::toString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }
