#include "Behavior.h"
#include "Agent.h"

Behavior::Behavior(Agent* owner) : Component(owner, "Behavior")
{
	m_owner = owner;
	m_behavior = 0;
	m_owner->disableAll();
	m_owner->enableBehavior(m_behavior);
	this->setEnabled();

	m_selection = 0;
}

Behavior::~Behavior()
{
	setDisabled();
}

void Behavior::update(float deltaTime)
{
	
	if (getEnabled() == true)
	{
		DrawText("Press the number 0 key for seek", 30, 20, 20, PURPLE);
		DrawText("Press the number 1 key for flee", 30, 40, 20, PURPLE);
		DrawText("Press the number 2 key for pursue", 30, 60, 20, PURPLE);
		DrawText("Press the number 3 key for evade", 30, 80, 20, PURPLE);
		DrawText("Press the number 4 key for arrive", 30, 100, 20, PURPLE);
		DrawText("Press the number 5 key for wander", 30, 120, 20, PURPLE);
		DrawText("Press the number 6 to disable all behaviors", 30, 140, 20, PURPLE);

		// Seek is working
		if (IsKeyPressed(KEY_KP_0))
		{
			DrawText("Seek enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(0);
		}
		// Flee is working
		if (IsKeyPressed(KEY_KP_1))
		{
			DrawText("Flee enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(1);
		}
		// Pursue is working
		if (IsKeyPressed(KEY_KP_2))
		{
			DrawText("Pursue enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(2);
		}
		// Evade is working
		if (IsKeyPressed(KEY_KP_3))
		{
			DrawText("Evade enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(3);
		}
		// Arrive is working
		if (IsKeyPressed(KEY_KP_4))
		{
			DrawText("Arrive enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(4);
		}
		// Wander is working
		if (IsKeyPressed(KEY_KP_5))
		{
			DrawText("Wander enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(5);
		}

		if (IsKeyPressed(KEY_KP_6))
		{
			DrawText("All disabled", 50, 50, 10, PURPLE);
			m_owner->disableAll();
		}
	}
}
