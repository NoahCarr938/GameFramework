#pragma once
#include "Component.h"

class MovementComponent : public Component
{
public:
	MovementComponent() {};
	MovementComponent(Actor* owner);
	~MovementComponent();

	void start();
	void update(float deltaTime);
	void end();
private:
	float m_speed;
};