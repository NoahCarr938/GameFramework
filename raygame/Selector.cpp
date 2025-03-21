#include "Selector.h"

Selector::~Selector()
{
	clear();
}

void Selector::onInitialize()
{
	m_current = m_children.begin();
}

Status Selector::update(BehaviorTreeAgent* owner, float deltaTime)
{
	// Keep going until a child behavior is running
	while (true)
	{
		Status s = (*m_current)->tick(owner, deltaTime);

		// If the child succeeds or keeps running, do the same
		if (s != BH_FAILURE)
			return s;

		// Hit the end of the list, it did not end well
		if (++m_current == m_children.end())
			return BH_FAILURE;
	}
}
