#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class SeekComponent : public Component
{
public:
	SeekComponent() {};
	SeekComponent(Actor* owner, Actor* target);
	~SeekComponent();
	void update(float deltaTime);

private:

	Actor* m_target;
};