#include "EvadeComponent.h"
#include "raylib.h"
#include "Actor.h"
#include "Scene.h"
#include "math.h"

EvadeComponent::EvadeComponent(Actor* owner, Actor* target)
{
	m_target = target;
	this->setDisabled();
}

EvadeComponent::~EvadeComponent()
{
	setDisabled();
}

void EvadeComponent::Update(float deltaTime)
{
	if (getEnabled() == true)
	{
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
		MathLibrary::Vector2 targetVelocity = m_target->getTransform()->getVelocity();
		// The point that the target is going to
		MathLibrary::Vector2 goToPoint = targetPosition + targetVelocity;
		// Calculates a vector to the target position along with the point the target is going to.
		MathLibrary::Vector2 targetVector = goToPoint - playerPosition;
		targetVector.normalize();

		// Max velocity is negative because we are trying to avoid it.
		MathLibrary::Vector2 desiredVelocity = targetVector * -(getOwner()->getTransform()->getMaxVelocity());
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
