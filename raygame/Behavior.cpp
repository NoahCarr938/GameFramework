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
		DrawText("Seeking", 10, 10, 10, RED);
		if (m_owner->getBehavior(0) == false)
		{
			DrawText("Seek disabled")
		}
		// Disables the current behavior
		if (IsKeyPressed(KEY_SPACE))
		{
			switch (m_selection)
			{
			case 0:
				m_owner->disableBehavior(0);
				break;
			}
		}

		//  Enables a behavior
		if (IsKeyPressed(KEY_W))
		{
			switch (m_selection)
			{
			case 0:
				m_owner->enableBehavior(0);
				break;
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
