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
	// Update will be used to update the wander position and wanderComponentCircle
	void update(float deltaTime);
	// Move will be used to set the position, and calculate velocity and steering behavior.
	void Move(MathLibrary::Vector2 target, float deltaTime);

private:
	// How long the agent has spent wandering
	int m_timeWandering;
	// The distance the actor can wander
	// Will be used as a scalar
	int m_wanderDistance;
	// Bool to determine if the actor was wandering or not
	bool m_wandering;
	
	MathLibrary::Vector2 m_wanderingPosition;
	MathLibrary::Vector2 m_wanderComponentCircle;
};