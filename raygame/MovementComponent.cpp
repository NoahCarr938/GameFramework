#include "MovementComponent.h"
#include "raylib.h"
#include "math.h"
#include "Transform2D.h"

MovementComponent::MovementComponent(Actor* owner) : Component(owner, "Actor")
{
	m_speed = 100;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::start()
{
}

void MovementComponent::update(float deltaTime)
{
	/*MathLibrary::Vector2 movementInput = MathLibrary::Vector2();
	if (IsKeyDown(KEY_A) && m_owner->GetLocalPosition().x > 5)
		movementInput.x -= 1;
	if (IsKeyDown(KEY_D) && Transform->GetLocalPosition().x < GetScreenWidth() * .86)
		movementInput.x += 1;

	MathLibrary::Vector2 deltaMovement = movementInput.getNormalized() * Speed * (float)deltaTime;

	if (deltaMovement.getMagnitude() != 0)
		Transform->SetLocalPosition(Transform->GetLocalPosition() + deltaMovement);*/
}

void MovementComponent::end()
{
}
