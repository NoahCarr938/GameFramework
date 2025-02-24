#include "SeekComponent.h"
#include "raylib.h"
#include "Actor.h"
#include "Scene.h"

SeekComponent::SeekComponent(Actor* owner, Actor* target)
{
	/*agent->setTarget(MathLibrary::Vector2(640, 360));
	target = MathLibrary::Vector2(640, 360);*/
}

SeekComponent::~SeekComponent()
{
	//agents.destroy();
}

void SeekComponent::Update(float deltaTime)
{
	//Vector2 steeringForce = m_player->m_currentBehavior()->Seek(m_player, m_player->getTarget(), deltaTime);
	m_player->update(deltaTime);
}
