#pragma once
#include "Component.h"

class MouseComponent : public Component
{
public:
	MouseComponent() {};
	MouseComponent(Actor* owner);
	~MouseComponent();

	void update(float deltaTime);
};