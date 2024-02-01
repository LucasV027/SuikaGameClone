#include "Vec2Float.h"

Vec2Float::Vec2Float() : x(0), y(0) {}

Vec2Float::Vec2Float(int _z) : x(_z), y(_z) {}

Vec2Float::Vec2Float(int _x, int _y) : x(_x), y(_y) {}

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

std::string Vec2Float::toString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }
