#pragma once
#include "Component.h"

class Agent;

class Behavior : public Component
{
public:
	Behavior() {};
	Behavior(Agent* owner);
	~Behavior();

	void update(float deltaTime);
private:
	Agent* m_owner;
	int m_selection;
	int m_behavior;
};

