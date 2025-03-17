#include "WanderComponent.h"

WanderComponent::WanderComponent(Actor* owner)
{
	this->setDisabled();
}

WanderComponent::~WanderComponent()
{
	setDisabled();
}

void WanderComponent::Update(float deltaTime)
{
}

void WanderComponent::Move(MathLibrary::Vector2 target, float deltaTime)
{
}
