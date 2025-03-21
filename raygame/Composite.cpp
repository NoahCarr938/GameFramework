#include "Composite.h"
#include <algorithm>

Composite* Composite::add(BehaviorTree* child)
{
	m_children.push_back(child);
	return this;
}

void Composite::remove(BehaviorTree* child)
{
	m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
	delete child;
}

void Composite::clear()
{
	for (Behaviors::iterator it = m_children.begin(); it != m_children.end(); it++)
	{
		delete* it;
	}
	m_children.clear();
}
