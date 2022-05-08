#pragma once
#include "../API.h"

namespace TurtleCore
{
	class Window
	{
	protected:
		API_EXPORT Window();

	public:
		API_EXPORT virtual ~Window() = 0;

		API_EXPORT virtual void Initialize(bool& success, const char* title, int width, int height) = 0;
		API_EXPORT virtual void HandleEvents() = 0;
		API_EXPORT virtual void Destroy() = 0;
	};
}