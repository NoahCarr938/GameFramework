#include "WanderComponent.h"

WanderComponent::WanderComponent(Actor* owner)
{
	this->setDisabled();
	m_timeWandering = 0;
	m_wanderDistance = 300;
	m_wandering = true;
}

WanderComponent::~WanderComponent()
{
	setDisabled();
}

void WanderComponent::Update(float deltaTime)
{
	if (getEnabled() == true)
	{

	}
}

void WanderComponent::Move(MathLibrary::Vector2 target, float deltaTime)
{
	if (getEnabled() == true)
	{

	}
}
