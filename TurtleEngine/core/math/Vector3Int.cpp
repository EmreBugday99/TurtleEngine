#include "Vector3Int.h"

TurtleCore::Vector3Int::Vector3Int()
	: X(0), Y(0), Z(0) {}
TurtleCore::Vector3Int::Vector3Int(int x, int y, int z)
	: X(x), Y(y), Z(z) {}
TurtleCore::Vector3Int::Vector3Int(const Vector3Int& other) 
	: X(other.X), Y(other.Y), Z(other.Z) {}

TurtleCore::Vector3Int& TurtleCore::Vector3Int::operator+(const Vector3Int& other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;

	return *this;
}

TurtleCore::Vector3Int& TurtleCore::Vector3Int::operator-(const Vector3Int& other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;

	return *this;
}

TurtleCore::Vector3Int& TurtleCore::Vector3Int::operator*(const Vector3Int& other)
{
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;

	return *this;
}

TurtleCore::Vector3Int& TurtleCore::Vector3Int::operator/(const Vector3Int& other)
{
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;

	return *this;
}

void TurtleCore::Vector3Int::operator+=(const Vector3Int& other)
{
	(*this) + other;
}

void TurtleCore::Vector3Int::operator-=(const Vector3Int& other)
{
	(*this) - other;
}

void TurtleCore::Vector3Int::operator*=(const Vector3Int& other)
{
	(*this)* other;
}

void TurtleCore::Vector3Int::operator/=(const Vector3Int& other)
{
	(*this) / other;
}

void TurtleCore::Vector3Int::operator+=(const int& value)
{
	(*this).X += value;
	(*this).Y += value;
	(*this).Z += value;
}

void TurtleCore::Vector3Int::operator-=(const int& value)
{
	(*this).X -= value;
	(*this).Y -= value;
	(*this).Z -= value;
}

void TurtleCore::Vector3Int::operator*=(const int& value)
{
	(*this).X *= value;
	(*this).Y *= value;
	(*this).Z *= value;
}

void TurtleCore::Vector3Int::operator/=(const int& value)
{
	(*this).X /= value;
	(*this).Y /= value;
	(*this).Z /= value;
}

void TurtleCore::Vector3Int::Set(const Vector3Int& other)
{
	X = other.X;
	Y = other.Y;
}

void TurtleCore::Vector3Int::Set(int value)
{
	X = value;
	Y = value;
}