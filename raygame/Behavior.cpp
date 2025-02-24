#include "Behavior.h"
#include "Agent.h"

Behavior::Behavior()
{
}

Behavior::~Behavior()
{
}

MathLibrary::Vector2 Behavior::seek(Agent* agent, MathLibrary::Vector2 target, float deltaTime)
{
	MathLibrary::Vector2 desiredVelocity = target - agent->getPosition();
	desiredVelocity = desiredVelocity.normalize();
	desiredVelocity * agent->getMaxVelocity();
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();
	steeringForce / agent->getMaxVelocity();
	steeringForce * agent->getMaxForce();
	return steeringForce;
}

MathLibrary::Vector2 Behavior::flee(Agent* agent, MathLibrary::Vector2 target, float deltaTime)
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Behavior::wander(Agent* agent, MathLibrary::Vector2 target, float deltaTime)
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Behavior::pursue(Agent* agent, MathLibrary::Vector2 target, float deltaTime)
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Behavior::evade(Agent* agent, MathLibrary::Vector2 target, float deltaTime)
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Behavior::arrive(Agent* agent, MathLibrary::Vector2 target, float deltaTime)
{
	return MathLibrary::Vector2();
}
