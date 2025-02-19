#include "Agent.h"

Agent::Agent()
{
}

Agent::~Agent()
{
}

void Agent::Start()
{
}

void Agent::Update(float deltaTime)
{
	if (m_currentBehavior)
		m_currentBehavior->Update(this, deltaTime);
	m_Agent.update(deltaTime);
}

void Agent::End()
{
}

void Agent::goTo()
{
	
}
