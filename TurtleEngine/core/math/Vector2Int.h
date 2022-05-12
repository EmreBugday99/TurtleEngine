#pragma once
#include "../API.h"

namespace TurtleCore
{
	class API_EXPORT Vector2Int
	{
	public:
		int X;
		int Y;

		Vector2Int();
		Vector2Int(int x, int y);
		Vector2Int(const Vector2Int& other);

		Vector2Int& operator+(const Vector2Int& other);
		Vector2Int& operator-(const Vector2Int& other);
		Vector2Int& operator*(const Vector2Int& other);
		Vector2Int& operator/(const Vector2Int& other);

		void operator+=(const Vector2Int& other);
		void operator-=(const Vector2Int& other);
		void operator*=(const Vector2Int& other);
		void operator/=(const Vector2Int& other);

		void Set(const Vector2Int& other);
		void Set(int value);
	};
}