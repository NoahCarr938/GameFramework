#pragma once
#include "Component.h"

class Actor;

class FiniteStateMachineComponent : public Component {
	FiniteStateMachineComponent() {};
	FiniteStateMachineComponent(Actor* owner);
	~FiniteStateMachineComponent();

	void handleSteeringBehaviors();
};