#pragma once
class Agent;

class Behavior
{
public:
	virtual void Start(Agent* agent) {};
	virtual void Update(Agent* agent, float deltaTime) {};
	virtual void End(Agent* agent) {};

	virtual float determineBehavior(Agent* agent) { return 0.0f; }
};