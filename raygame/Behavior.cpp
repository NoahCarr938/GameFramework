#include "Behavior.h"
#include "Agent.h"

Behavior::Behavior(Agent* owner) : Component(owner, "BehaviorComponent")
{
	m_owner = owner;
	m_behavior = 0;
	for (int i = 0; i <= 6; i++)
	{
		m_owner->disableBehavior(m_behavior);
	}
	m_owner->enableBehavior(m_behavior);
	this->setEnabled();

	m_selection = 0;
}

Behavior::~Behavior()
{
	setDisabled();
}

void Behavior::Update(float deltaTime)
{
	
	if (getEnabled() == true)
	{
		/*DrawRectangleLines(m_selection + 10, 10, 100, 40, RED);*/
		DrawText("Seeking", 10, 10, 10, RED);
		if (m_owner->getBehavior(0) == false)
		{
			DrawText("Seek disabled", 50, 50, 10, RED);
		}
		// Disables the current behavior
		if (IsKeyPressed(KEY_S))
		{
			switch (m_selection)
			{
				// Disable seek
			case 0:
				m_owner->disableBehavior(0);
				break;
				// Disable flee
			case 100:
				m_owner->disableBehavior(1);
				break;
				// Disable persue
			case 200:
				m_owner->disableBehavior(2);
				break;
				// Disable evade
			case 300:
				m_owner->disableBehavior(3);
				break;
				// Disable arrive
			case 400:
				m_owner->disableBehavior(4);
				break;
			/*case 500:
				m_owner->disableBehavior(0);
				break;*/
			}
		}

		//  Enables a behavior
		if (IsKeyPressed(KEY_W))
		{
			switch (m_selection)
			{
				// Seek
			case 0:
				m_owner->enableBehavior(0);
				break;
				// Flee
			case 100:
				m_owner->enableBehavior(1);
				// Pursue
			case 200:
				m_owner->enableBehavior(2); 
				// Evade
			case 300:
				m_owner->enableBehavior(3);
				// Arrive
			case 400:
				m_owner->enableBehavior(4);
			/*case 500:
				m_owner->enableBehavior(1);*/
			}
		}

		switch (GetKeyPressed())
		{
		case KeyboardKey(KEY_A):
			m_selection = 0;
			break;
		}
	}
}
