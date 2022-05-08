#pragma once
#include "../API.h"

namespace TurtleCore
{
	class Window;

	class Renderer
	{
	protected:
		API_EXPORT Renderer();

	public:
		API_EXPORT virtual ~Renderer();

		API_EXPORT virtual void Render() = 0;
		API_EXPORT virtual void Destroy() = 0;
	};
}