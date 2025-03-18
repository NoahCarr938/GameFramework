#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class FleeComponent : public Component
{
public:
	FleeComponent() {};
	FleeComponent(Actor* owner, Actor* target);
	~FleeComponent();
	void update(float deltaTime);

private:

	Actor* m_target;
};