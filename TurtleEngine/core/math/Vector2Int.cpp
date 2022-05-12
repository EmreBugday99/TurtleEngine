#include "Vector2Int.h"

TurtleCore::Vector2Int::Vector2Int() : X(0), Y(0) {}
TurtleCore::Vector2Int::Vector2Int(const int x, const int y) : X(x), Y(y) {}
TurtleCore::Vector2Int::Vector2Int(const Vector2Int& other) : X(other.X), Y(other.Y) {}

TurtleCore::Vector2Int& TurtleCore::Vector2Int::operator+(const Vector2Int& other)
{
	X += other.X;
	Y += other.Y;

	return *this;
}

TurtleCore::Vector2Int& TurtleCore::Vector2Int::operator-(const Vector2Int& other)
{
	X -= other.X;
	Y -= other.Y;

	return *this;
}

TurtleCore::Vector2Int& TurtleCore::Vector2Int::operator*(const Vector2Int& other)
{
	X *= other.X;
	Y *= other.Y;

	return *this;
}

TurtleCore::Vector2Int& TurtleCore::Vector2Int::operator/(const Vector2Int& other)
{
	X /= other.X;
	Y /= other.Y;

	return *this;
}

void TurtleCore::Vector2Int::operator+=(const Vector2Int& other)
{
	(*this) + other;
}

void TurtleCore::Vector2Int::operator-=(const Vector2Int& other)
{
	(*this) - other;
}

void TurtleCore::Vector2Int::operator*=(const Vector2Int& other)
{
	(*this)* other;
}

void TurtleCore::Vector2Int::operator/=(const Vector2Int& other)
{
	(*this) / other;
}

void TurtleCore::Vector2Int::Set(const Vector2Int& other)
{
	X = other.X;
	Y = other.Y;
}

void TurtleCore::Vector2Int::Set(int value)
{
	X = value;
	Y = value;
}