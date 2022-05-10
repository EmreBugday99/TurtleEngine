#pragma once
#include "../API.h"


namespace TurtleCore
{
	class TurtleObject;
	class TypeInformation
	{
	private:
		const char* TypeId;
		unsigned short Size;
		void* Pointer;
		bool Initialized;

	public:
		API_EXPORT TypeInformation();
		API_EXPORT void Initialize(TurtleObject* object);
		API_EXPORT const char* GetTypeId() const;
		API_EXPORT unsigned short GetSize() const;
		API_EXPORT void* GetPointer() const;
		API_EXPORT bool IsInitialized() const;
	};
}