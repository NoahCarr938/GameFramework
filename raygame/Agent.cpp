#include "Agent.h"
#include "Transform2D.h"

Agent::Agent()
{
}

Agent::Agent(float x, float y, const char* name)
{
	//Initialze default values
	m_transform = new Transform2D(this);
	m_transform->setLocalPosition({ x,y });
	m_name = name;
}

Agent::~Agent()
{
}

void Agent::Update(float deltaTime)
{
	/*if (m_currentBehavior)
		m_currentBehavior->Update(this, deltaTime);
	m_Agent->update(deltaTime);*/
}

MathLibrary::Vector2 Agent::getPosition()
{
	return position;
}

MathLibrary::Vector2 Agent::setPosition(Vector2 position)
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Agent::getVelocity()
{
	return velocity;
}

MathLibrary::Vector2 Agent::setVelocity(Vector2 velocity)
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Agent::getForce()
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Agent::setForce()
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Agent::getTarget()
{
	return MathLibrary::Vector2();
}

MathLibrary::Vector2 Agent::setTarget(Agent* target)
{
	return MathLibrary::Vector2();
}

