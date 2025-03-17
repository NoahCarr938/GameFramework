#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class WanderComponent : public Component
{
public:
	WanderComponent() {};
	WanderComponent(Actor* owner);
	~WanderComponent();
	virtual void Update(float deltaTime);
	// Move will be used to set the position, and calculate velocity and steering behavior.
	void Move(MathLibrary::Vector2 target, float deltaTime);
	// Update will be used to update the wander position and wanderComponentCircle

private:
	int m_timeWandering;
	int m_wanderDistance;
	bool m_wandering;
	
	MathLibrary::Vector2 m_wanderingPosition;
	MathLibrary::Vector2 m_wanderComponentCircle;
};