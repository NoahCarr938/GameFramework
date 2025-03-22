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
	DrawText("Agent status: Seek", 60, 40, 25, YELLOW);

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
	DrawText("Agent status: Seek and Pursue", 60, 40, 25, YELLOW);

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
	DrawText("Agent status: Flee", 60, 40, 25, YELLOW);

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
	DrawText("Agent status: Evade", 60, 40, 25, YELLOW);

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
	if (m_timeFleeing >= 20000)
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
	DrawText("Agent status: Wander", 60, 40, 25, YELLOW);
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
	//If the agent spots the player
	if (detectionDistance < 100)
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

		//Contains the finite state machine
		HandleStates();

		//If game is active 
		// (These statements keep track of extra variable that dont fall into a
		//  state section for the finite state machine)
		if (m_gameActive == true)
		{
			//Counter until Game is over
			DrawText(TextFormat("GameTimer: %i", m_gameTimer), 60, 80, 25, PURPLE);
			if (distance > 200)
			{
				m_gameTimer++;
				if (m_gameTimer >= 100000)
				{
					m_gameTimer = 0;
					m_gameActive = false;
				}
			}
		}
	}
}
