#include "Vector4Int.h"

TurtleCore::Vector4Int::Vector4Int()
	: X(0), Y(0), Z(0), W(0) {}
TurtleCore::Vector4Int::Vector4Int(int x, int y, int z, int w)
	: X(x), Y(y), Z(z), W(w) {}
TurtleCore::Vector4Int::Vector4Int(const Vector4Int& other)
	: X(other.X), Y(other.Y), Z(other.Z), W(other.W) {}

TurtleCore::Vector4Int& TurtleCore::Vector4Int::operator+(const Vector4Int& other)
{
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	W += other.W;

	return *this;
}

TurtleCore::Vector4Int& TurtleCore::Vector4Int::operator-(const Vector4Int& other)
{
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	W = other.W;

	return *this;
}

TurtleCore::Vector4Int& TurtleCore::Vector4Int::operator*(const Vector4Int& other)
{
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;
	W *= other.W;

	return *this;
}

TurtleCore::Vector4Int& TurtleCore::Vector4Int::operator/(const Vector4Int& other)
{
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;
	W /= other.W;

	return *this;
}

void TurtleCore::Vector4Int::operator+=(const Vector4Int& other)
{
	(*this) + other;
}

void TurtleCore::Vector4Int::operator-=(const Vector4Int& other)
{
	(*this) - other;
}

void TurtleCore::Vector4Int::operator*=(const Vector4Int& other)
{
	(*this)* other;
}

void TurtleCore::Vector4Int::operator/=(const Vector4Int& other)
{
	(*this) / other;
}

void TurtleCore::Vector4Int::Set(const Vector4Int& other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	W = other.W;
}

void TurtleCore::Vector4Int::Set(int value)
{
	X = value;
	Y = value;
	Z = value;
	W = value;
}