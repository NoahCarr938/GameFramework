#pragma once
#include "Component.h"
#include "List.h"
#include "Transform2D.h"

class Agent;

// abstract base class for all of the actions
class Behavior
{
public:

	Behavior();
	~Behavior();

	// Steering Behaviors
	MathLibrary::Vector2 seek(Agent* agent, MathLibrary::Vector2 target, float deltaTime);
	MathLibrary::Vector2 flee(Agent* agent, MathLibrary::Vector2 target, float deltaTime);
	MathLibrary::Vector2 wander(Agent* agent, MathLibrary::Vector2 target, float deltaTime);
	MathLibrary::Vector2 pursue(Agent* agent, MathLibrary::Vector2 target, float deltaTime);
	MathLibrary::Vector2 evade(Agent* agent, MathLibrary::Vector2 target, float deltaTime);
	MathLibrary::Vector2 arrive(Agent* agent, MathLibrary::Vector2 target, float deltaTime);

	/*virtual void Start(Agent* agent) {};
	virtual void Update(Agent* agent, float deltaTime) = 0;
	virtual void End(Agent* agent) {};*/
	
	/*template <typename T>
	T* getWeight(T* weight);

	template <typename T>
	T* setWeight(T* weight);*/
private:
	List<Component*> m_behaviorComponentList;
};

//template<typename T>
//inline T* Behavior::getWeight(T* weight)
//{
//	return nullptr;
//}
//
//template<typename T>
//inline T* Behavior::setWeight(T* weight)
//{
//	return nullptr;
//}
