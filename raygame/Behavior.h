#pragma once
#include "Component.h"

class Agent;

class Behavior : public Component
{
public:
	Behavior(Agent* owner);
	~Behavior();

	void Update(float deltaTime);
private:
	Agent* m_owner;
	int m_behavior;
};

