#include <iostream>
#include "FiniteStateMachine.h"
#include "raylib.h"
#include "Agent.h"
#include "Transform2D.h"

FiniteStateMachineComponent::FiniteStateMachineComponent(Agent* owner, Actor* target) : Component(owner, "WanderComponent")
{
	m_owner = owner;
	m_target = target;
	int m_state = 0;
	int m_timeSeeking = 0;
	int m_timeFleeing = 0;
	int m_gametimer = 0;
	int m_switchimer = 0;
	bool m_gameActive = false;
	bool m_collided = false;
	bool m_isSeeking = true;
}

FiniteStateMachineComponent::~FiniteStateMachineComponent()
{
	setDisabled();
}

void FiniteStateMachineComponent::HandleStates()
{
	// Switch statement for all of the states
	switch (m_state)
	{
	case STATE_WANDERING:
		WanderBehavior();
		break;

	case STATE_SEEK:
		SeekBehavior();
		break;

	case STATE_PURSUE:
		PursueBehavior();
		break;

	case STATE_FLEE:
		FleeBehavior();
		break;

	case STATE_EVADE:
		EvadeBehavior();
		break;

	default:
		break;
	}
}

void FiniteStateMachineComponent::SeekBehavior()
{
	// Making the positions and velocity into variables
	MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Distance between the player and the target
	MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
	float distance = targetVector.getMagnitude();

	//Distance from the player to the wander circle
	targetVector = targetPosition - (playerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = targetVector.getMagnitude();

	//Displays the current state
	DrawText("Agent status: Seek", 100, 40, 40, YELLOW);

	// Changes the state when within a distance of 25
	if (distance < 25 && m_switchTimer <= 0)
	{
		m_collided = true;
		m_isSeeking = !(m_isSeeking);
		m_switchTimer = 2500;
		m_timeSeeking = 0;
		m_timeFleeing = 0;
		m_state = STATE_FLEE;
	}
	else
	{
		m_switchTimer--;
	}

	//Speeds up after chasing the target for a set amount of time. Swaps to pursue.
	if (m_timeSeeking >= 20000)
	{
		m_state = STATE_PURSUE;
	}

	m_timeSeeking++;
	m_owner->disableAll();
	m_owner->enableBehavior(0);
}

void FiniteStateMachineComponent::PursueBehavior()
{
	// Making the positions and velocity into variables
	MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Distance between the player and the target
	MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
	float distance = targetVector.getMagnitude();

	//Distance from the player to the wander circle
	targetVector = targetPosition - (playerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = targetVector.getMagnitude();

	//Displays the current state
	DrawText("Agent status: Seek and Pursue", 100, 40, 40, YELLOW);

	// Changes the state when within a distance of 25
	if (distance < 25 && m_switchTimer <= 0)
	{
		m_collided = true;
		m_isSeeking = !(m_isSeeking);
		m_switchTimer = 2500;
		m_timeSeeking = 0;
		m_timeFleeing = 0;
		m_state = STATE_EVADE;
	}
	else
	{
		m_switchTimer--;
	}

	m_timeSeeking++;
	m_owner->disableAll();
	m_owner->enableBehavior(0);
	m_owner->enableBehavior(3);
}

void FiniteStateMachineComponent::FleeBehavior()
{
	// Making the positions and velocity into variables
	MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Distance between the player and the target
	MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
	float distance = targetVector.getMagnitude();

	//Distance from the player to the wander circle
	targetVector = targetPosition - (playerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = targetVector.getMagnitude();

	//Displays the current state
	DrawText("Agent status: Flee", 100, 40, 40, YELLOW);

	// Changes the state when within a distance of 25
	if (distance < 25 && m_switchTimer <= 0)
	{
		m_collided = true;
		m_isSeeking = !(m_isSeeking);
		m_switchTimer = 2500;
		m_timeSeeking = 0;
		m_timeFleeing = 0;
		m_state = STATE_SEEK;
	}
	else
	{
		m_switchTimer--;
	}

	m_timeFleeing++;
	m_owner->disableAll();
	m_owner->enableBehavior(1);
}

void FiniteStateMachineComponent::EvadeBehavior()
{
	// Making the positions and velocity into variables
	MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Distance between the player and the target
	MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
	float distance = targetVector.getMagnitude();

	//Distance from the player to the wander circle
	targetVector = targetPosition - (playerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = targetVector.getMagnitude();

	//Displays the current state
	DrawText("Agent status: Flee and Evade", 100, 40, 40, YELLOW);

	// Changes the state when within a distance of 25
	if (distance < 25 && m_switchTimer <= 0)
	{
		m_collided = true;
		m_isSeeking= !(m_isSeeking);
		m_switchTimer = 2500;
		m_timeSeeking = 0;
		m_timeFleeing = 0;
		m_state = STATE_SEEK;
	}
	else
	{
		m_switchTimer--;
	}

	//Starts to slow down running after a moment. State changes to flee
	if (m_timeFleeing >= 25000)
	{
		m_state = STATE_FLEE;
	}

	m_timeFleeing++;
	m_owner->disableAll();
	m_owner->enableBehavior(1);
	m_owner->enableBehavior(4);
}

void FiniteStateMachineComponent::WanderBehavior()
{
	// Checks to make sure the state changes if the 0 key is pressed
	if (m_gameActive == true)
	{
		if (m_isSeeking == true)
		{
			m_state = STATE_SEEK;
		}
		else
		{
			m_state = STATE_EVADE;
		}
	}

	// Making the positions and velocity into variables
	MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Distance between the player and the target
	MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
	float distance = targetVector.getMagnitude();

	//Distance from the player to the wander circle
	targetVector = targetPosition - (playerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = targetVector.getMagnitude();

	//The detection range 
	MathLibrary::Vector2 wanderCircle = playerPosition + (getOwner()->getTransform()->getForward() * 200);
	DrawCircleLines(wanderCircle.x, wanderCircle.y, 200, BLUE);
	//Displays the current state
	DrawText("Agent status: Wander", 100, 40, 40, YELLOW);

	//If the agent spots the player
	if (detectionDistance < 200)
	{
		m_gameActive = true;

		if (m_isSeeking == true)
		{
			m_state = STATE_SEEK;
		}
		else
		{
			m_state = STATE_EVADE;
		}
	}

	//Start to wander
	m_owner->disableAll();
	m_owner->enableBehavior(2);
}

void FiniteStateMachineComponent::update(float deltaTime)
{
	if (getEnabled() == true)
	{
		// Making the positions and velocity into variables
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
		MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

		//Distance between the player and the target
		MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
		float distance = targetVector.getMagnitude();

		//Distance from the player to the wander circle
		targetVector = targetPosition - (playerPosition + (getOwner()->getTransform()->getForward() * 200));
		float detectionDistance = targetVector.getMagnitude();

		//Draw text to show that you can swap active and inactive
		DrawText("Press the 0 key to swap active or inactive", 100, 12, 20, PURPLE);
		//If the 0 key is pressed then swap active and inactive
		if (IsKeyPressed(KEY_KP_0))
		{
			m_gameActive = !(m_gameActive);
			m_gameTimer = 0;
			m_switchTimer = 0;
			m_timeSeeking = 0;
			m_timeFleeing = 0;

			// If the game is not active then the current state is set to wandering
			if (m_gameActive == false)
			{
				m_state = STATE_WANDERING;
			}
		}

		//Contains the finite state machine
		HandleStates();

		//If game is active 
		// (These statements keep track of extra variable that dont fall into a
		//  state section for the finite state machine)
		if (m_gameActive == true)
		{
			//Counter until Game is over
			DrawText(TextFormat("GameTimer: %i", m_gameTimer), 100, 80, 40, PURPLE);
			if (distance > 200)
			{
				m_gameTimer++;
				if (m_gameTimer >= 100000)
				{
					m_gameTimer = 0;
					m_gameActive = false;
				}
			}

			//Show when you can tag
			if (m_switchTimer <= 0)
			{
				DrawCircle(playerPosition.x, playerPosition.y, 40, PURPLE);
			}
			else
			{
				DrawCircle(playerPosition.x, playerPosition.y, 40, PURPLE);
			}

			//Changes the state to wander whenever tag ends.
			if (m_gameActive == false)
			{
				m_state = STATE_WANDERING;
			}
		}
	}
}
