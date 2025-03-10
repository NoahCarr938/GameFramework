#include "Behavior.h"
#include "Agent.h"

Behavior::Behavior(Agent* owner)
{
	m_owner = owner;
	m_behavior = 0;
	for (int i = 0; i <= 6; i++)
	{
		m_owner->disableBehavior(m_behavior);
	}
	m_owner->enableBehavior(m_behavior);
	this->setEnabled();
}

Behavior::~Behavior()
{
	setDisabled();
}

void Behavior::Update(float deltaTime)
{
	if (getEnabled() == true)
	{

	}
}
