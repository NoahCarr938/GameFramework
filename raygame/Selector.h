#pragma once
#include "Composite.h"
#include "BehaviorTreeAgent.h"

class Selector : public Composite
{
protected:
	virtual ~Selector();
	virtual void onInitialize();
	virtual Status update(BehaviorTreeAgent* owner, float deltaTime);

	
	Behaviors::iterator m_current;
};