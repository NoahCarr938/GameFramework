#pragma once
#include "raymath.h"
#include <list>
#include "Actor.h"
#include "Behavior.h"

class BehaviorTree;
class SeekComponent;
class FleeComponent;
class EvadeComponent;
class ArriveComponent;

class BehaviorTreeAgent : public Actor
{
public:
	BehaviorTreeAgent();
	BehaviorTreeAgent(float x, float y, const char* name);
	virtual ~BehaviorTreeAgent();

	// Update the agent and its behaviors
	virtual void update(float deltaTime);

	//void SetAttack(bool state) { m_attack = state; }
	Actor* getTarget() { return m_target; }
	void setTarget(Actor* actor) { m_target = actor; }

	// bt stands for behavior tree
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

private:
	Actor* m_target;
	int m_state;
	SeekComponent* m_seek;
	FleeComponent* m_flee;
	EvadeComponent* m_evade;
	ArriveComponent* m_arrive;
};