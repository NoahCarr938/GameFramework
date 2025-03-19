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
		/*DrawRectangleLines(m_selection + 10, 10, 100, 40, PURPLE);*/
		/*DrawText("Seeking", 50, 10, 10, PURPLE);
		if (m_owner->getBehavior(0) == false)
		{
			DrawText("Seek disabled", 50, 50, 10, PURPLE);
		}*/
		/*DrawText("Press the right arrow key to enable behaviors", 50, 30, 25, PURPLE);
		DrawText("Press the left arrow key to enable behaviors", 50, 60, 25, PURPLE);*/
		DrawText("Press the number 0 key for seek", 30, 20, 20, PURPLE);
		DrawText("Press the number 1 key for flee", 30, 40, 20, PURPLE);
		DrawText("Press the number 2 key for flee", 30, 60, 20, PURPLE);
		DrawText("Press the number 3 key for flee", 30, 80, 20, PURPLE);
		DrawText("Press the number 4 key for flee", 30, 100, 20, PURPLE);
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
		// Arrive breaks
		if (IsKeyPressed(KEY_KP_4))
		{
			DrawText("Arrive enabled", 50, 50, 10, PURPLE);
			m_owner->enableBehavior(4);
		}
		// Wander breaks
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

		////// Disables the current behavior
		//if (IsKeyPressed(KEY_LEFT))
		//{
		//	switch (m_selection)
		//	{
		//	case 0:
		//		// Disable seek
		//		//DrawText("Seek disabled", 50, 50, 10, PURPLE);
		//		m_owner->disableBehavior(0);
		//		break;
		//	case 100:
		//		// Disable flee
		//		//DrawText("Flee disabled", 50, 50, 10, PURPLE);
		//		m_owner->disableBehavior(1);
		//		break;
		//	case 200:
		//		// Disable pursue
		//		//DrawText("Pursue disabled", 50, 50, 10, PURPLE);
		//		m_owner->disableBehavior(2);
		//		break;
		//	case 300:
		//		// Disable evade
		//		//DrawText("Evade disabled", 50, 50, 10, PURPLE);
		//		m_owner->disableBehavior(3);
		//		break;
		//	case 400:
		//		// Disable arrive
		//		//DrawText("Arrive disabled", 50, 50, 10, PURPLE);
		//		m_owner->disableBehavior(4);
		//		break;
		//	case 500:
		//		// Disables Wander
		//		//DrawText("Wander disabled", 50, 50, 10, PURPLE);
		//		m_owner->disableBehavior(5);
		//		break;
		//	}
		//}

		////  Enables a behavior
		//if (IsKeyPressed(KEY_RIGHT))
		//{
		//	switch (m_selection)
		//	{
		//	case 0:
		//		// Enables Seek
		//		DrawText("Seek enabled", 50, 50, 10, PURPLE);
		//		m_owner->enableBehavior(0);
		//		break;
		//		// Enables Flee
		//	case 100:
		//		DrawText("Flee enabled", 50, 50, 10, PURPLE);
		//		m_owner->enableBehavior(1);
		//		// Enables Pursue
		//	case 200:
		//		DrawText("Pursue enabled", 50, 50, 10, PURPLE);
		//		m_owner->enableBehavior(2); 
		//		// Enables Evade
		//	case 300:
		//		DrawText("Evade enabled", 50, 50, 10, PURPLE);
		//		m_owner->enableBehavior(3);
		//		// Enables Arrive
		//	case 400:
		//		DrawText("Arrive enabled", 50, 50, 10, PURPLE);
		//		m_owner->enableBehavior(4);
		//		// Enables Wander
		//	case 500:
		//		DrawText("Wander enabled", 50, 50, 10, PURPLE);
		//		m_owner->enableBehavior(5);
		//	}
		//}

		/*switch (GetKeyPressed())
		{
		case KeyboardKey(KEY_A):
			m_selection = 0;
			break;
		}*/
	}
}
