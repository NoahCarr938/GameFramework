#pragma once
#include "raymath.h"
#include "Selector.h"
#include "Sequence.h"
#include "Agent.h"
#include "Transform2D.h"
#include "EvadeComponent.h"
#include "SeekComponent.h"
#include "ArriveComponent.h"

class MouseCloseCondition : public BehaviorTree
{
public:
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		MathLibrary::Vector2 mouse = { GetMousePosition().x,GetMousePosition().y };
		// distance = magnitude of (mouse - position)
		float distance = (mouse - agent->getTransform()->getWorldPosition()).getMagnitude();
		if (distance <= 25)
			return BH_SUCCESS;

		ArriveComponent* arrive = agent->getComponent<ArriveComponent>();
		arrive->setDisabled();
		return BH_FAILURE;

	}
};

class StopAttackAction : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		return BH_SUCCESS;
	}
};

class SeekAction : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		SeekComponent* seek = agent->getComponent<SeekComponent>();
		seek->setEnabled();
		return BH_SUCCESS;
	}
};

class ArriveAction : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		SeekComponent* seek = agent->getComponent<SeekComponent>();
		seek->setDisabled();
		ArriveComponent* arrive = agent->getComponent<ArriveComponent>();
		arrive->setEnabled();

		return BH_SUCCESS;
	}
};

class EvadeTarget : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		SeekComponent* seek = agent->getComponent<SeekComponent>();
		seek->setDisabled();
		EvadeComponent* evade = agent->getComponent<EvadeComponent>();
		evade->setEnabled();

		return BH_SUCCESS;
	}
};

class TargetIsNotNear : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		float distance = (agent->getTarget()->getTransform()->getLocalPosition() - agent->getTransform()->getLocalPosition()).getMagnitude();
		if (distance > 300)
			return BH_SUCCESS;


		SeekComponent* seek = agent->getComponent<SeekComponent>();
		seek->setDisabled();
		return BH_FAILURE;
	}
};
class TargetIsNear : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		float distance = (agent->getTarget()->getTransform()->getWorldPosition() - agent->getTransform()->getWorldPosition()).getMagnitude();
		if (distance < 100)
			return BH_SUCCESS;

		EvadeComponent* evade = agent->getComponent<EvadeComponent>();
		evade->setDisabled();
		return BH_FAILURE;
	}
};

