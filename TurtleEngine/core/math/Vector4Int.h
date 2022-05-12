#pragma once
#include "../API.h"

namespace TurtleCore
{
	class API_EXPORT Vector4Int
	{
	public:
		int X;
		int Y;
		int Z;
		int W;

		Vector4Int();
		Vector4Int(int x, int y, int z, int w);
		Vector4Int(const Vector4Int& other);

		Vector4Int& operator+(const Vector4Int& other);
		Vector4Int& operator-(const Vector4Int& other);
		Vector4Int& operator*(const Vector4Int& other);
		Vector4Int& operator/(const Vector4Int& other);

		void operator+=(const Vector4Int& other);
		void operator-=(const Vector4Int& other);
		void operator*=(const Vector4Int& other);
		void operator/=(const Vector4Int& other);

		void Set(const Vector4Int& other);
		void Set(int value);
	};
}