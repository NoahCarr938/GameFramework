#pragma once
#include "Component.h"

enum AIState
{
	STATE_WANDERING,
	STATE_SEEK,
	STATE_PURSUE,
	STATE_FLEE,
	STATE_EVADE
};

class FiniteStateMachineComponent : public Component 
{
public:
	FiniteStateMachineComponent() {};
	FiniteStateMachineComponent(Agent* owner, Actor* target);
	~FiniteStateMachineComponent();

	void HandleStates();
	void SeekBehavior();
	void PursueBehavior();
	void FleeBehavior();
	void EvadeBehavior();
	void WanderBehavior();
	void update(float deltaTime);
private:
	Agent* m_owner;
	//Agent* m_target;
	Actor* m_target;
	int m_state;
	int m_timeSeeking;
	int m_timeFleeing;
	int m_gameTimer;
	int m_switchTimer;
	bool m_gameActive;
	bool m_collided;
	bool m_isSeeking;
};