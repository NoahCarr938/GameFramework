#include "MovementComponent.h"
#include "Transform2D.h"
#include "raylib.h"
#include "Actor.h"

MovementComponent::~MovementComponent()
{
}

MovementComponent::MovementComponent(Actor* owner)
{
}

void MovementComponent::Update(float deltaTime)
{
	/*MathLibrary::Vector2 movementInput = MathLibrary::Vector2();
	if (IsKeyDown(KEY_W) && m_transform->getLocalPosition().y > 5)
		movementInput.y += 10;
	if (IsKeyDown(KEY_S) && m_transform->getLocalPosition().y < 5)
		movementInput.y -= 10;
	if (IsKeyDown(KEY_A) && m_transform->getLocalPosition().x > 5)
		movementInput.x -= 10;
	if (IsKeyDown(KEY_D) && m_transform->getLocalPosition().x < GetScreenWidth() * .86)
		movementInput.x += 10;

	MathLibrary::Vector2 deltaMovement = movementInput.getNormalized() * speed * (float)deltaTime;

	if (deltaMovement.getMagnitude() != 0)
		m_transform->setLocalPosition(m_transform->getLocalPosition() + deltaMovement);*/
}
