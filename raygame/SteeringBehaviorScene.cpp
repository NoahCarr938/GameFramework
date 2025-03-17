#include "SteeringBehaviorScene.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "PursueComponent.h"
#include "EvadeComponent.h"
#include "ArriveComponent.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "raylib.h"

void SteeringBehaviorScene::start()
{
	Agent* enemy = new Agent(150, 150, "Enemy");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->getTransform()->setScale({ 50, 50 });

	/*Actor* bullet = new Actor(250, 50, "Bullet");
	bullet->addComponent(new SpriteComponent(bullet, "Images/bullet.png"));
	bullet->getTransform()->setScale({ 50, 50 });*/

	/*Actor* player = new Actor(50, 50, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->getTransform()->setScale({ 50, 50 });*/
	Agent* player = new Agent(50, 150, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->getTransform()->setScale({ 50, 50 });

	enemy->getTransform()->setMaxVelovity(100);
	enemy->addComponent(new Behavior(enemy));
	enemy->addComponent(new SeekComponent(enemy, player));
	enemy->addComponent(new FleeComponent(enemy, player));
	enemy->addComponent(new PursueComponent(enemy, player));
	enemy->addComponent(new EvadeComponent(enemy, player));
	enemy->addComponent(new ArriveComponent(enemy, player));
	enemy->addComponent(new WanderComponent(enemy));

	addActor(player);
	addActor(enemy);
	//addActor(bullet);
}
