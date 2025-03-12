#include "FleeComponent.h"
#include "raylib.h"
#include "Actor.h"
#include "Scene.h"
#include "math.h"

FleeComponent::FleeComponent(Actor* owner, Actor* enemy) : Component(owner, "SeekComponent")
{
	m_enemy = enemy;
	this->setDisabled();
}

FleeComponent::~FleeComponent()
{
	setDisabled();
}

void FleeComponent::Update(float deltaTime)
{
	if (getEnabled() == true)
	{
		MathLibrary::Vector2 playerPosition = getOwner()->getTransform()->getLocalPosition();
		MathLibrary::Vector2 enemyPosition = m_enemy->getTransform()->getLocalPosition();
		MathLibrary::Vector2 playerVelocity = getOwner()->getTransform()->getVelocity();
		MathLibrary::Vector2 enemyVector = enemyPosition - playerPosition;
		enemyVector.normalize();
		MathLibrary::Vector2 desiredVelocity = enemyVector * getOwner()->getTransform()->getMaxVelocity();
		MathLibrary::Vector2 steeringForce = desiredVelocity - playerVelocity;

		// Time to set the new velocity that we have calculated
		getOwner()->getTransform()->setVelocity(playerVelocity + (steeringForce * deltaTime));

		// Time to set the new position that we have calculated
		getOwner()->getTransform()->setLocalPosition(playerPosition + (playerVelocity * deltaTime));

		// Rotates the player if we need to
		getOwner()->getTransform()->setRotation(atan2(playerVelocity.x, playerVelocity.y));
		getOwner()->getTransform()->rotate(1.00);
	}
}