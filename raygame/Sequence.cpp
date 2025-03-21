#include "Sequence.h"
#include "BehaviorTreeAgent.h"

Sequence::~Sequence()
{
	clear();
}

void Sequence::onInitialize()
{
	m_current = m_children.begin();
}

Status Sequence::update(BehaviorTreeAgent* owner, float deltaTime)
{
	// Keep going until a child says that it is running
	while (true)
	{
		Status s = (*m_current)->tick(owner, deltaTime);

		// If the child fails or keeps running, do the same
		if (s != BH_SUCCESS)
			return s;

		// Hits the end of the array, the task is complete
		if (++m_current == m_children.end())
			return BH_SUCCESS;
	}
}
