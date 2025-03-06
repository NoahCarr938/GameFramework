#include "Agent.h"
#include "Transform2D.h"
#include "Component.h"
#include "Collider.h"
#include <string.h>


Agent::Agent()
{
}

Agent::Agent(float x, float y, const char* name)
{
	m_transform = new Transform2D(this);
	m_name = name;
	m_transform->setLocalPosition({x, y});
}

Agent::~Agent()
{
	delete m_transform;
}

void Agent::enableBehavior(int behavior)
{
	for (int i = 0; i <= 6; i++)
	{
		if (i >= m_components.Length())
			break;
		else if (i == behavior)
			this->m_components[i]->setEnabled();
	}
}

void Agent::disableBehavior(int behavior)
{
	for (int i = 0; i <= 6; i++)
	{
		if (i >= m_components.Length())
			break;
		else if (i == behavior)
			this->m_components[i]->setDisabled();
	}
}

bool Agent::getBehavior(int behavior)
{
	for (int i = 0; i <= 6; i++)
	{
		if (i >= m_components.Length())
			break;
		else if (i == behavior)
			this->m_components[i]->getEnabled();
	}
	return false;
}
