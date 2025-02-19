#pragma once
#include "Behavior.h"
#include "Transform2D.h"
class SeekComponent : public Behavior
{
public:
	SeekComponent(Actor* player, Actor* target);
	~SeekComponent();
	virtual void Update(Agent* agent, float deltaTime);
private:
	MathLibrary::Vector2 target;
	List <Agent*> agents;
};