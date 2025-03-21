#pragma once
#include "math.h"
#include "raymath.h"
#include "Selector.h"
#include "Sequence.h"
#include "Agent.h"

class MouseCloseCondition : public BehaviorTree
{
public:
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		Vector2 mouse = GetMousePosition();
		// distance = magnitude of (mouse - position)
		float distance = Vector2Length(Vector2Subtract(mouse, agent->m_position));
		if (distance <= 50)
			return BH_SUCCESS;

		return BH_FAILURE;
	}
};

class AttackAction : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		agent->SetAttack(true);
		return BH_SUCCESS;
	}
};

class StopAttackAction : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		agent->SetAttack(false);
		return BH_SUCCESS;
	}
};

class SeekAction : public BehaviorTree
{
	virtual Status update(BehaviorTreeAgent* agent, float deltaTime)
	{
		Vector2 mouse = GetMousePosition();
		Vector2 direction = Vector2Subtract(mouse, agent->m_position);

		// acceleration = direction normal * max speed * dt
		agent->m_acceleration = Vector2Scale(Vector2Normalize(direction), agent->m_maxSpeed * deltaTime);

		return BH_SUCCESS;
	}
};