#include "MouseComponent.h"
#include "Transform2D.h"
#include "raylib.h"
#include "Actor.h"
// In this class we will get the mouse's position as a component

MouseComponent::MouseComponent(Actor* owner) : Component(owner, "MouseComponent")
{
	this->setEnabled();
}

MouseComponent::~MouseComponent()
{
	setDisabled();
}

void MouseComponent::update(float deltaTime)
{
	if (this->getEnabled() == true)
	{
		// Getting the mouse position
		MathLibrary::Vector2 currentMousePosition(GetMousePosition().x, GetMousePosition().y);
		// Setting the mouse position
		getOwner()->getTransform()->setLocalPosition(currentMousePosition);
	}
}
