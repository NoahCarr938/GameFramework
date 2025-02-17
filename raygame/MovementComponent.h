#pragma once
#include "Component.h"

class MovementComponent : public Component
{
public:
	MovementComponent() {}
	~MovementComponent();
	MovementComponent(Actor* owner);
	void Update(float deltaTime);
	float speed = 10;
};