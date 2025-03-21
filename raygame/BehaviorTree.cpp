#include "BehaviorTree.h"
#include "BehaviorTreeAgent.h"

Status BehaviorTree::tick(BehaviorTreeAgent* agent, float deltaTime)
{
	if (m_status != BH_RUNNING)
	{
		onInitialize();
	}

	m_status = update(agent, deltaTime);

	if (m_status != BH_RUNNING)
	{
		onTerminate(m_status);
	}
	return m_status;
}

void BehaviorTree::reset()
{
	m_status = BH_INVALID;
}

void BehaviorTree::abort()
{
	onTerminate(BH_ABORTED);
	m_status = BH_ABORTED;
}

bool BehaviorTree::isTerminated() const
{
	return m_status == BH_SUCCESS || m_status == BH_FAILURE;
}

bool BehaviorTree::isRunning() const
{
	return m_status == BH_RUNNING;
}

Status BehaviorTree::getStatus() const
{
	return Status();
}
