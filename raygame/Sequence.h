#pragma once
#include "Composite.h"

class Sequence : public Composite
{
protected:
	virtual ~Sequence();
	virtual void onInitialize();
	virtual Status update(BehaviorTreeAgent* owner, float deltaTime);

	Behaviors::iterator m_current;
};