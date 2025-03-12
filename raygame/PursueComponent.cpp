#include "PursueComponent.h"
#include "raylib.h"
#include "Actor.h"
#include "Scene.h"
#include "math.h"

PursueComponent::PursueComponent(Actor* owner, Actor* target)
{
	m_target = target;
	this->setDisabled();
}

PursueComponent::~PursueComponent()
{
	setDisabled();
}

void PursueComponent::Update(float deltaTime)
{
	if (getEnabled() == true)
	{
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 targetPosition = m_target->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
		MathLibrary::Vector2 targetVector = targetPosition - playerPosition;
		targetVector.normalize();

		MathLibrary::Vector2 desiredVelocity = targetPosition + targetVector - playerPosition;
		MathLibrary::Vector2 steeringForce = desiredVelocity.normalize() * getOwner()->getTransform()->getMaxVelocity() - playerVelocity;

		// Time to set the new velocity that we have calculated
		getOwner()->getTransform()->setVelocity(playerVelocity + (steeringForce * deltaTime));

		// Time to set the new position that we have calculated
		getOwner()->getTransform()->setLocalPosition(playerPosition + (playerVelocity * deltaTime));

		// Rotates the player if we need to
		getOwner()->getTransform()->setRotation(atan2(playerVelocity.x, playerVelocity.y));
		getOwner()->getTransform()->rotate(1.00);
	}
}
