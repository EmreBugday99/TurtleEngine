#pragma once
#include "API.h"

namespace TurtleCore
{
	class TurtleObject
	{
	public:
		static int Count;

		API_EXPORT TurtleObject();
		API_EXPORT virtual ~TurtleObject() = 0;
		API_EXPORT virtual void Initialize() = 0;
		API_EXPORT virtual void Start() = 0;
		API_EXPORT virtual void Update() = 0;
		API_EXPORT virtual void Destroy() = 0;
	};
}