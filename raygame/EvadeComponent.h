#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class EvadeComponent : public Component
{
public:
	EvadeComponent() {};
	EvadeComponent(Actor* owner, Actor* target);
	~EvadeComponent();
	virtual void Update(float deltaTime);

private:

	Actor* m_target;
};