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
	//Handles changing the states
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
	//Puts the positions and the owner's velocity into variables for ease of use
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 ownerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Actual distance between owner and target
	MathLibrary::Vector2 distanceVector = targetPosition - ownerPosition;
	float distance = distanceVector.getMagnitude();

	//Distance from owner to the circle used to wander
	distanceVector = targetPosition - (ownerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = distanceVector.getMagnitude();

	//Show current state
	DrawText("Agent status: Seek", 100, 40, 40, YELLOW);

	//Tags and changes the state when within a small distance
	if (distance < 40 && m_switchTimer <= 0)
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

	//Starts to speed up after chasing for a while (Swaps to SeekerSeekAndPursue)
	if (m_timeSeeking >= 25000)
	{
		m_state = STATE_PURSUE;
	}

	m_timeSeeking++;
	m_owner->disableAll();
	m_owner->enableBehavior(0);
}

void FiniteStateMachineComponent::PursueBehavior()
{
	//Puts the positions and the owner's velocity into variables for ease of use
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 ownerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Actual distance between owner and target
	MathLibrary::Vector2 distanceVector = targetPosition - ownerPosition;
	float distance = distanceVector.getMagnitude();

	//Distance from owner to the circle used to wander
	distanceVector = targetPosition - (ownerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = distanceVector.getMagnitude();

	//Show current state
	DrawText("Agent status: Seek and Pursue", 100, 40, 40, YELLOW);

	//Tags and changes the state when within a small distance
	if (distance < 40 && m_switchTimer <= 0)
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
	//Puts the positions and the owner's velocity into variables for ease of use
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 ownerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Actual distance between owner and target
	MathLibrary::Vector2 distanceVector = targetPosition - ownerPosition;
	float distance = distanceVector.getMagnitude();

	//Distance from owner to the circle used to wander
	distanceVector = targetPosition - (ownerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = distanceVector.getMagnitude();

	//Show current state
	DrawText("Agent status: Flee", 100, 40, 40, YELLOW);

	//Tags and changes the state when within a small distance
	if (distance < 40 && m_switchTimer <= 0)
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
	//Puts the positions and the owner's velocity into variables for ease of use
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 ownerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Actual distance between owner and target
	MathLibrary::Vector2 distanceVector = targetPosition - ownerPosition;
	float distance = distanceVector.getMagnitude();

	//Distance from owner to the circle used to wander
	distanceVector = targetPosition - (ownerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = distanceVector.getMagnitude();

	//Show current state
	DrawText("Agent status: Flee and Evade", 100, 40, 40, YELLOW);

	//Tags and changes the state when within a small distance
	if (distance < 40 && m_switchTimer <= 0)
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

	//Starts to ease up on running away after a while (Swaps to RunnerFlee)
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
	//A check so that the state properly changes if the user uses the 0 key to activate/deactivate tag
	if (m_gameActive == true)
	{
		//Seeker or Runner
		if (m_isSeeking == true)
		{
			m_state = STATE_SEEK;
		}
		else
		{
			m_state = STATE_EVADE;
		}
	}

	//Puts the positions and the owner's velocity into variables for ease of use
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 ownerVelocity = getOwner()->getTransform()->getVelocity();
	MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

	//Actual distance between owner and target
	MathLibrary::Vector2 distanceVector = targetPosition - ownerPosition;
	float distance = distanceVector.getMagnitude();

	//Distance from owner to the circle used to wander
	distanceVector = targetPosition - (ownerPosition + (getOwner()->getTransform()->getForward() * 200));
	float detectionDistance = distanceVector.getMagnitude();

	//Show detectection range
	MathLibrary::Vector2 wanderCircle = ownerPosition + (getOwner()->getTransform()->getForward() * 200);
	DrawCircleLines(wanderCircle.x, wanderCircle.y, 200, BLUE);
	//Show current state
	DrawText("Agent status: Wander", 100, 40, 40, YELLOW);

	//Agent spots player and starts tag
	if (detectionDistance < 200)
	{
		m_gameActive = true;

		//Seeker or Runner
		if (m_isSeeking == true)
		{
			m_state = STATE_SEEK;
		}
		else
		{
			m_state = STATE_EVADE;
		}
	}

	//Start wandering
	m_owner->disableAll();
	m_owner->enableBehavior(2);
}

void FiniteStateMachineComponent::update(float deltaTime)
{
	if (getEnabled() == true)
	{
		//Puts the positions and the owner's velocity into variables for ease of use
		MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 ownerVelocity = getOwner()->getTransform()->getVelocity();
		MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();

		//Actual distance between owner and target
		MathLibrary::Vector2 distanceVector = targetPosition - ownerPosition;
		float distance = distanceVector.getMagnitude();

		//Distance from owner to the circle used to wander
		distanceVector = targetPosition - (ownerPosition + (getOwner()->getTransform()->getForward() * 200));
		float detectionDistance = distanceVector.getMagnitude();

		//Tell user that you can swap tag active
		DrawText("Press the 0 key to swap active or inactive", 100, 12, 20, YELLOW);
		//Swap tag to be active or inactive outside of normal function
		if (IsKeyPressed(KEY_KP_0))
		{
			m_gameActive = !(m_gameActive);
			m_gameTimer = 0;
			m_switchTimer = 0;
			m_timeSeeking = 0;
			m_timeFleeing = 0;

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
			DrawText(TextFormat("GameTimer: %i", m_gameTimer), 100, 80, 40, YELLOW);
			if (distance > 200)
			{
				m_gameTimer++;
				if (m_gameTimer >= 100000)
				{
					m_gameTimer = 0;
					m_gameActive = false;
				}
			}

			//Shows how far you need to be in order for the gametimer to increment
			DrawCircleLines(ownerPosition.x, ownerPosition.y, 200, BLUE);

			//Show when you can tag
			if (m_switchTimer <= 0)
			{
				DrawCircle(ownerPosition.x, ownerPosition.y, 40, GREEN);
			}
			else
			{
				DrawCircle(ownerPosition.x, ownerPosition.y, 40, RED);
			}

			//Will change the state to wander when tag is over
			if (m_gameActive == false)
			{
				m_state = STATE_WANDERING;
			}
		}
	}
}
