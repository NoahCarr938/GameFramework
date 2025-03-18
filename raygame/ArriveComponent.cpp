#include "ArriveComponent.h"
#include "math.h"

ArriveComponent::ArriveComponent(Actor* owner, Actor* target)
{
	m_target = target;
	this->setDisabled();
}

ArriveComponent::ArriveComponent(Actor* owner, MathLibrary::Vector2 target) : Component(owner, "ArriveComponent")
{
	m_target->getTransform()->setLocalPosition(target);
	this->setDisabled();
}

ArriveComponent::~ArriveComponent()
{
	setDisabled();
}

void ArriveComponent::update(float deltaTime)
{
	if (getEnabled() == true)
	{
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();

		// Calculates a vector to the target position along with the point the target is going to.
		MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
		float distance = targetVector.getMagnitude();
		targetVector.normalize();

		// Max velocity is positive because we are not trying to avoid it.
		MathLibrary::Vector2 desiredVelocity;
		DrawCircleLines(targetPosition.x, targetPosition.y, 500, RED);
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
