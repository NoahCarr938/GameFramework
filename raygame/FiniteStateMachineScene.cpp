#include "FiniteStateMachineScene.h"
#include "FiniteStateMachine.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "PursueComponent.h"
#include "EvadeComponent.h"
#include "ArriveComponent.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"
#include "MouseComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "raylib.h"

void FiniteStateMachineScene::start()
{
	Actor* mouse = new Actor(150, 150, "Mouse");
	mouse->addComponent(new SpriteComponent(mouse, "images/player.png"));
	mouse->addComponent(new MouseComponent(mouse));
	mouse->getTransform()->setScale({ 50, 50 });

	Agent* enemy = new Agent(50, 50, "Enemy");
	enemy->getTransform()->setMaxVelovity(500);
	enemy->addComponent(new SeekComponent(enemy, mouse));
	enemy->addComponent(new FleeComponent(enemy, mouse));
	enemy->addComponent(new PursueComponent(enemy, mouse));
	enemy->addComponent(new EvadeComponent(enemy, mouse));
	enemy->addComponent(new ArriveComponent(enemy, mouse));
	enemy->addComponent(new WanderComponent(enemy));
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->addComponent(new FiniteStateMachineComponent(enemy, mouse));
	enemy->getTransform()->setScale({ 50, 50 });
	enemy->enableGame();

	addActor(mouse);
	addActor(enemy);
}
