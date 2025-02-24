#pragma once
#include "Actor.h"
#include "raylib.h"
#include "Behavior.h"
#include "list.h"
#include "Component.h"

class Agent : public Actor
{
public:
	Agent();
	//Agent(List<Behavior*> m_behaviorList, Behavior m_currentBehavior) : m_currentBehavior(), m_behaviorList() {};
	Agent(float x, float y, const char* name);
	~Agent();
    void Update(float deltaTime);

	float maxForce;
	float maxVelocity;
	
	/* Velocity variables and functions*/
	//Max velocity will be a scalar
	MathLibrary::Vector2 target = MathLibrary::Vector2();
	//MathLibrary::Vector2 maxVelocity = MathLibrary::Vector2();
	MathLibrary::Vector2 currentVelocity = MathLibrary::Vector2();
	MathLibrary::Vector2 velocity = MathLibrary::Vector2();
	MathLibrary::Vector2 position = MathLibrary::Vector2();
	//MathLibrary::Vector2 desiredVelocity = ((m_transform->getLocalPosition() - m_transform->getLocalPosition()).normalize()) * maxVelocity;
	//MathLibrary::Vector2 steeringForce = desiredVelocity - currentVelocity;
	
	//float getPosition();
	MathLibrary::Vector2 getPosition();
	MathLibrary::Vector2 setPosition(Vector2 position);
	MathLibrary::Vector2 getVelocity();
	MathLibrary::Vector2 setVelocity(Vector2 velocity);
	MathLibrary::Vector2 getForce();
	MathLibrary::Vector2 setForce();
	MathLibrary::Vector2 getTarget();
	MathLibrary::Vector2 setTarget(Agent* target);
	float getMaxVelocity() { return maxVelocity; }
	float getMaxForce() { return maxForce; }

	Behavior* m_currentBehavior;

private:
	Actor* m_Agent;
	/*Behavior* m_currentBehavior;*/
	List<Behavior*> m_behaviorList;
};