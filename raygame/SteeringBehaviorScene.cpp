#include "SteeringBehaviorScene.h"
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

void SteeringBehaviorScene::start()
{
	Actor* mouse = new Actor(150, 150, "Mouse");
	mouse->addComponent(new SpriteComponent(mouse, "images/player.png"));
	mouse->addComponent(new MouseComponent(mouse));
	mouse->getTransform()->setScale({ 50, 50 });

	Agent* enemy = new Agent(50, 50, "Enemy");
	enemy->getTransform()->setMaxVelovity(500);
	enemy->addComponent(new SeekComponent(enemy, mouse));
	enemy->addComponent(new FleeComponent(enemy, mouse));
	enemy->addComponent(new WanderComponent(enemy));
	enemy->addComponent(new PursueComponent(enemy, mouse));
	enemy->addComponent(new EvadeComponent(enemy, mouse));
	enemy->addComponent(new ArriveComponent(enemy, mouse));
	enemy->addComponent(new Behavior(enemy));
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
    enemy->getTransform()->setScale({ 50, 50 });

	addActor(mouse);
	addActor(enemy);

	//Agent* enemy = new Agent(150, 150, "Enemy");
	//enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	//enemy->getTransform()->setScale({ 50, 50 });

	///*Actor* bullet = new Actor(250, 50, "Bullet");
	//bullet->addComponent(new SpriteComponent(bullet, "Images/bullet.png"));
	//bullet->getTransform()->setScale({ 50, 50 });*/

	///*Actor* player = new Actor(50, 50, "Player");
	//player->addComponent(new SpriteComponent(player, "Images/player.png"));
	//player->getTransform()->setScale({ 50, 50 });*/
	//Agent* player = new Agent(50, 150, "Player");
	//player->addComponent(new SpriteComponent(player, "Images/player.png"));
	//player->getTransform()->setScale({ 50, 50 });

	//enemy->getTransform()->setMaxVelovity(100);
	//enemy->addComponent(new Behavior(enemy));
	//enemy->addComponent(new SeekComponent(enemy, player));
	//enemy->addComponent(new FleeComponent(enemy, player));
	//enemy->addComponent(new PursueComponent(enemy, player));
	//enemy->addComponent(new EvadeComponent(enemy, player));
	//enemy->addComponent(new ArriveComponent(enemy, player));
	//enemy->addComponent(new WanderComponent(enemy));

	//addActor(player);
	//addActor(enemy);
	////addActor(bullet);
}
