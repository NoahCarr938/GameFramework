#include "Agent.h"
#include "Transform2D.h"
#include "Component.h"
#include "Collider.h"
#include <string.h>


Agent::Agent() : Actor()
{
	Actor::m_transform = new Transform2D(this);
}

Agent::Agent(float x, float y, const char* name = "Agent")
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
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == behavior)
			this->m_components[i]->setEnabled();
	}
}

void Agent::disableBehavior(int behavior)
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == behavior)
			this->m_components[i]->setDisabled();
	}
}

void Agent::enableAll()
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		this->m_components[i]->setEnabled();
	}
}

void Agent::disableAll()
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		this->m_components[i]->setDisabled();
	}
}

void Agent::enableGame()
{
	for (int i = 0; i <= m_components.Length(); i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == m_components.Length() - 1)
			this->m_components[i]->setEnabled();
	}
}

void Agent::disableGame()
{
	for (int i = 0; i <= m_components.Length(); i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == m_components.Length() - 1)
			this->m_components[i]->setDisabled();
	}
}

bool Agent::getBehavior(int behavior)
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == behavior)
			this->m_components[i]->getEnabled();
	}
	return false;
}
