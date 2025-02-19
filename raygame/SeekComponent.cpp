#include "SeekComponent.h"
#include "raylib.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Scene.h"

SeekComponent::SeekComponent(Actor* player, Actor* target)
{
	//Velocity variables and functions
	/*MathLibrary::Vector2 maxVelocity;
	MathLibrary::Vector2 desiredVelocity = (player.getLocalPosition - target.getLocalPosition()).getNormalized() * maxVelocity;
	MathLibrary::Vector2 currentVelocity;
	MathLibrary::Vector2 steeringForce = desiredVelocity - currentVelocity;*/

}

SeekComponent::~SeekComponent()
{
}

void SeekComponent::Update(Agent* agent, float deltaTime)
{
	if (KeyboardKey(KEY_SPACE))
	{
		/*MathLibrary::Vector2 seekPos = actor.GetLocalPosition();
		agent->goTo(MathLibrary::Vector2(seekPos.x, seekPos.y));*/
	}
}
