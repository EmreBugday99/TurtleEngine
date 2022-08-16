#pragma once
#include "../API.h"

namespace TurtleCore
{
	class Window
	{
	protected:
		API_EXPORT Window();

	public:
		int Width;
		int Height;
		API_EXPORT virtual ~Window() = 0;

		API_EXPORT virtual void Initialize(bool& success, const char* title, int width, int height) = 0;
		API_EXPORT virtual void HandleEvents() = 0;
		API_EXPORT virtual void Render() = 0;
		API_EXPORT virtual void Clear() = 0;
		API_EXPORT virtual bool IsRunning() = 0;
		API_EXPORT virtual void Stop() = 0;
		API_EXPORT virtual void Destroy() = 0;
		API_EXPORT virtual void* GetWindow() const = 0;
		API_EXPORT virtual void* GetRenderer() = 0;
	};
}