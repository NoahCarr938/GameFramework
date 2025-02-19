#pragma once
#include "Component.h"
#include "List.h"

class Agent;

class Behavior
{
public:
	virtual void Start(Agent* agent) {};
	virtual void Update(Agent* agent, float deltaTime) {};
	virtual void End(Agent* agent) {};
	
	template <typename T>
	T* getWeight(T* weight);

	template <typename T>
	T* setWeight(T* weight);
private:
	List<Component*> m_behaviorComponentList;
};

template<typename T>
inline T* Behavior::getWeight(T* weight)
{
	return nullptr;
}

template<typename T>
inline T* Behavior::setWeight(T* weight)
{
	return nullptr;
}
