#pragma once
#include "Behavior.h"
#include "Transform2D.h"
#include "Agent.h"

class Actor;

class SeekComponent : public Component
{
public:
	SeekComponent(Actor* owner, Actor* target);
	~SeekComponent();
	//virtual void Update(Agent* agent, float deltaTime);
	virtual void Update(float deltaTime);

private:
	/*Actor* m_target;
	Actor* m_player;*/
	//List <Agent*> agents;
	//MathLibrary::Vector2 target = MathLibrary::Vector2();
	Agent* m_target;
	Agent* m_player;
	/*MathLibrary::Vector2 velocity;
	MathLibrary::Vector2 position;*/
};