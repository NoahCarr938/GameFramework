#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class ArriveComponent : public Component
{
public:
	ArriveComponent() {};
	ArriveComponent(Actor* owner, Actor* target);
	ArriveComponent(Actor* owner, MathLibrary::Vector2 target);
	~ArriveComponent();
	void update(float deltaTime);

private:

	Actor* m_target;
};