#include "BehaviorTreeScene.h"
#include "BehaviorTree.h"
#include "BehaviorTreeAgent.h"
#include "Agent.h"
#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "MouseComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "PursueComponent.h"
#include "EvadeComponent.h"
#include "ArriveComponent.h"
#include "WanderComponent.h"
#include "MovementComponent.h"


void BehaviorTreeScene::start()
{
	Actor* player = new Actor(150, 100, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->addComponent(new MouseComponent(player));
	player->getTransform()->setScale({ 50, 50 });

	BehaviorTreeAgent* enemy = new BehaviorTreeAgent(200, 100, "Agent");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->getTransform()->setScale({ 50 , 50 });

	addActor(player);
	addActor(enemy);
}

void BehaviorTreeScene::update(float deltaTime)
{
	Scene::update(deltaTime);
}

void BehaviorTreeScene::end()
{
	Scene::end();
}
