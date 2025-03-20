#include "WanderComponent.h"
#include "math.h"
#include "random"

WanderComponent::WanderComponent(Actor* owner) : Component(owner, "WanderComponent")
{
	this->setDisabled();
	m_timeWandering = 0;
	m_wanderDistance = 300;
	m_wandering = true;

	MathLibrary::Vector2 m_wanderingPosition = { 1, 1 };
	MathLibrary::Vector2 m_wanderComponentCircle = { 1, 1 };
}

WanderComponent::~WanderComponent()
{
	setDisabled();
}

// Updating the wandering position, and wandering circle
void WanderComponent::update(float deltaTime)
{
	if (getEnabled() == true)
	{
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();

		if (m_wandering == true)
		{
			// Getting a random x and y position for wandering
			float wanderX = GetRandomValue(-10, 10);
			float wanderY = GetRandomValue(-10, 10);

			// Time to set the wandering position
			m_wanderingPosition = { wanderX, wanderY };
			m_wanderingPosition.normalize();
			m_wanderingPosition = m_wanderingPosition * m_wanderDistance;
			m_wanderingPosition = m_wanderingPosition + playerPosition;
			m_wanderingPosition = m_wanderingPosition + (getOwner()->getTransform()->getForward() * m_wanderDistance);

			// If statements to ensure that the wandering actor does not go off of screen
			if (m_wanderingPosition.x >= GetScreenWidth())
				m_wanderingPosition.x -= 100;
			if (m_wanderingPosition.x <= GetScreenWidth())
				m_wanderingPosition.x += 100;
			if (m_wanderingPosition.y >= GetScreenHeight())
				m_wanderingPosition.y -= 100;
			if (m_wanderingPosition.y <= GetScreenHeight())
				m_wanderingPosition.y += 100;

			// Time to set the wander circle
			m_wanderComponentCircle = playerPosition + (getOwner()->getTransform()->getForward() * m_wanderDistance);
			
			m_wandering = false;
		}
		if (m_wandering == false)
		{
			Move(m_wanderingPosition, deltaTime);
			m_timeWandering++;
			if (m_timeWandering >= 10000)
			{
				m_wandering = true;
				m_timeWandering = 0;
			}
		}
		// Drawing the wander circle
		DrawCircleLines(m_wanderComponentCircle.x, m_wanderComponentCircle.y, m_wanderDistance, PURPLE);
		// Display where the actor is wandering to
		DrawLine(m_wanderingPosition.x, m_wanderingPosition.y, playerPosition.x, playerPosition.y, PURPLE);
	}
}

// Basic position updating
void WanderComponent::Move(MathLibrary::Vector2 target, float deltaTime)
{
	if (getEnabled() == true)
	{
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();

		// Calculates a vector to the target position along with the point the target is going to.
		MathLibrary::Vector2 targetVector = target - playerPosition;
		float distance = targetVector.getMagnitude();
		targetVector.normalize();

		// Max velocity is positive because we are not trying to avoid it.
		MathLibrary::Vector2 desiredVelocity;
		DrawCircleLines(target.x, target.y, 500, RED);
		if (distance < 500) {
			desiredVelocity = ((targetVector * getOwner()->getTransform()->getMaxVelocity()) * (distance / 1000));
		}
		else {
			desiredVelocity = targetVector * getOwner()->getTransform()->getMaxVelocity();
		}
		MathLibrary::Vector2 steeringForce = desiredVelocity - playerVelocity;

		// Time to set the new velocity that we have calculated
		getOwner()->getTransform()->setVelocity(playerVelocity + (steeringForce * deltaTime));

		// Time to set the new position that we have calculated
		getOwner()->getTransform()->setLocalPosition(playerPosition + (playerVelocity * deltaTime));

		// Rotates the player if we need to
		getOwner()->getTransform()->setRotation(atan2(playerVelocity.x, playerVelocity.y));
		getOwner()->getTransform()->rotate(-1.00);
	}
}
