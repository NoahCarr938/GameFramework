#pragma once
#include "Component.h"

enum Status
{
	BH_INVALID,
	BH_SUCCESS,
	BH_FAILURE,
	BH_RUNNING,
	BH_ABORTED
};

class BehaviorTreeAgent;

// Base class for actions, conditions and composites
class BehaviorTree
{
public:
	BehaviorTree() : m_status(BH_INVALID) {}
	virtual ~BehaviorTree() {}
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime) = 0;
	virtual void onInitialize() {}
	virtual void onTerminate(Status status) {}

	Status tick(BehaviorTreeAgent* owner, float deltaTime);
	void reset();
	void abort();

	bool isTerminated() const;
	bool isRunning() const;

	Status getStatus() const;
private:
	Status m_status;
};