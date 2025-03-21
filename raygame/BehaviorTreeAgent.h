#pragma once
#include "raymath.h"
#include <list>

class BehaviorTree;
class Actor;

class BehaviorTreeAgent
{
public:
	BehaviorTreeAgent(float x, float y);
	virtual ~BehaviorTreeAgent();

	// Update the agent and its behaviours
	virtual void update(float deltaTime);

	// Draw the agent
	virtual void Draw();

	void SetAttack(bool state) { m_attack = state; }

protected:
	BehaviorTree* m_behaviorTree;
	bool m_attack;

public:
	float m_maxSpeed;

	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};