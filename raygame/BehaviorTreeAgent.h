#pragma once
#include "raymath.h"
#include <list>
#include "Actor.h"
#include "Behavior.h"

class BehaviorTree;

class BehaviorTreeAgent : public Actor
{
public:
	BehaviorTreeAgent();
	BehaviorTreeAgent(float x, float y, const char* name);
	virtual ~BehaviorTreeAgent();

	// Update the agent and its behaviours
	virtual void update(float deltaTime);

	// Draw the agent
	//virtual void Draw();

	void SetAttack(bool state) { m_attack = state; }

	void btEnableBehavior(int behavior);
	void btDisableBehavior(int behavior);
	void btEnableAll();
	void btDisableAll();
	void btEnableGame();
	void btDisableGame();
	bool btGetBehavior(int behavior);

protected:
	BehaviorTree* m_behaviorTree;
	bool m_attack;

public:
	float m_maxSpeed;

	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};