#pragma once
#include "Actor.h"
#include "raylib.h"
#include "Behavior.h"
#include "list.h"

class Agent : public Actor
{
public:
	Agent();
	Agent(List<Behavior*> m_behaviorList, Behavior m_currentBehavior) : m_currentBehavior(), m_behaviorList() {};
	~Agent();

	void Start();
	void Update(float deltaTime);
	void End();
	void Draw();

private:
	DynamicArray<Actor*> m_pathAgent;
	Behavior m_currentBehavior;
	List<Behavior*> m_behaviorList;
};