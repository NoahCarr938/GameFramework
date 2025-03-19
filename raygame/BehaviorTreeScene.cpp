#include "BehaviorTreeScene.h"
#include "Agent.h"
#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"

void BehaviorTreeScene::start()
{
	Agent* Player = new Agent(150, 150, "Player");
	Player->addComponent(new SpriteComponent(Player, "Images/player.png"));
	Player->getTransform()->setScale({ 50, 50 });
	addActor(Player);
}

void BehaviorTreeScene::update(float deltaTime)
{
}

void BehaviorTreeScene::end()
{
}
