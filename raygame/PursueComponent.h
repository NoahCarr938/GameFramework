#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class PursueComponent : public Component
{
public:
	PursueComponent() {};
	PursueComponent(Actor* owner, Actor* target);
	~PursueComponent();
	virtual void Update(float deltaTime);

private:

	Actor* m_target;
};