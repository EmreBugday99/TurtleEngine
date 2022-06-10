#pragma once

#pragma once
#include "../API.h"

namespace TurtleCore
{
	class API_EXPORT Vector3Int
	{
	public:
		int X;
		int Y;
		int Z;

		Vector3Int();
		Vector3Int(int x, int y, int z);
		Vector3Int(const Vector3Int& other);

		Vector3Int& operator+(const Vector3Int& other);
		Vector3Int& operator-(const Vector3Int& other);
		Vector3Int& operator*(const Vector3Int& other);
		Vector3Int& operator/(const Vector3Int& other);
		
		void operator+=(const Vector3Int& other);
		void operator-=(const Vector3Int& other);
		void operator*=(const Vector3Int& other);
		void operator/=(const Vector3Int& other);

		void operator+=(const int& value);
		void operator-=(const int& value);
		void operator*=(const int& value);
		void operator/=(const int& value);

		void Set(const Vector3Int& other);
		void Set(int value);
	};
}