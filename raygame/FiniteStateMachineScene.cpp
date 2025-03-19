#include "FiniteStateMachineScene.h"
#include "Agent.h"
#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "FiniteStateMachine.h"

void FiniteStateMachineScene::start()
{
	Agent* enemyShip = new Agent(150, 150, "Enemy Ship");
	enemyShip->addComponent(new SpriteComponent(enemyShip, "Images/enemy.png"));
	enemyShip->getTransform()->setScale({ 50, 50 });
	addActor(enemyShip);
}
