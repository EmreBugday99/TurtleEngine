#include "TestComponent.h"
#include <iostream>


TestComponent::TestComponent(TurtleCore::Entity* entity): Component(entity) {}

TestComponent::~TestComponent() = default;

void TestComponent::Initialize()
{
}

void TestComponent::Start()
{
	std::cout << "Howdy!" << std::endl;
}

void TestComponent::Update()
{
}

void TestComponent::Destroy()
{
}
