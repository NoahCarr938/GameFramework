#include "BehaviorTreeAgent.h"
#include "BehaviorTree.h"
#include "Behaviors.h"
#include "Transform2D.h"
#include "Component.h"
#include "Collider.h"
#include <string.h>

BehaviorTreeAgent::BehaviorTreeAgent()
{
	Actor::m_transform = new Transform2D(this);
}

BehaviorTreeAgent::BehaviorTreeAgent(float x, float y, const char* name = "Agent") : m_behaviorTree(nullptr), m_attack(false)
{
	m_transform = new Transform2D(this);
	m_name = name;
	m_transform->setLocalPosition({ x, y });
	m_maxSpeed = 100;
	//m_position = { x, y };

	// looks hideous, but basically builds the tree without using temp variables
	m_behaviorTree =
		(new Selector())->add(
		(new Sequence())->add(
		new MouseCloseCondition())->add(
		new AttackAction()))->add(
		(new Sequence())->add(
		new StopAttackAction())->add(
		new SeekAction()));
			
		

}

BehaviorTreeAgent::~BehaviorTreeAgent()
{
	if (m_behaviorTree != nullptr)
	{
		delete m_behaviorTree;
	}
	delete m_transform;
}

// Update the agent and its behaviours
void BehaviorTreeAgent::update(float deltaTime)
{

	if (m_behaviorTree != nullptr)
		m_behaviorTree->tick(this, deltaTime);

	m_velocity.x += m_acceleration.x;
	m_velocity.y += m_acceleration.y;

	if (m_velocity.x > m_maxSpeed) {
		m_velocity.x = m_maxSpeed;
	}
	else if (m_velocity.x < -m_maxSpeed) {
		m_velocity.x < -m_maxSpeed;
	}
	if (m_velocity.y > m_maxSpeed) {
		m_velocity.y = m_maxSpeed;
	}
	else if (m_velocity.y < -m_maxSpeed) {
		m_velocity.y < -m_maxSpeed;
	}

	m_acceleration.x = 0;
	m_acceleration.y = 0;

	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;

}

//void BehaviorTreeAgent::Draw()
//{
//	if (!m_attack)
//		DrawRectangle(m_position.x, m_position.y, 10, 10, RED);
//	else
//		DrawRectangle(m_position.x, m_position.y, 10, 10, GREEN);
//}

void BehaviorTreeAgent::btEnableBehavior(int behavior)
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == behavior)
			this->m_components[i]->setEnabled();
	}
}

void BehaviorTreeAgent::btDisableBehavior(int behavior)
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == behavior)
			this->m_components[i]->setDisabled();
	}
}

void BehaviorTreeAgent::btEnableAll()
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		this->m_components[i]->setEnabled();
	}
}

void BehaviorTreeAgent::btDisableAll()
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		this->m_components[i]->setDisabled();
	}
}

void BehaviorTreeAgent::btEnableGame()
{
	for (int i = 0; i <= m_components.Length(); i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == m_components.Length() - 1)
			this->m_components[i]->setEnabled();
	}
}

void BehaviorTreeAgent::btDisableGame()
{
	for (int i = 0; i <= m_components.Length(); i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == m_components.Length() - 1)
			this->m_components[i]->setDisabled();
	}
}

bool BehaviorTreeAgent::btGetBehavior(int behavior)
{
	for (int i = 0; i <= 5; i++)
	{
		if (i >= m_components.Length())
			break;
		if (i == behavior)
			this->m_components[i]->getEnabled();
	}
	return false;
}