#include "SteeringBehaviorScene.h"
#include "SampleScene.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "Transform2D.h"
#include "Agent.h"

void SteeringBehaviorScene::start()
{
	Agent* enemy = new Agent(150, 50, "Enemy");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->getTransform()->setScale({ 50, 50 });

	/*Actor* bullet = new Actor(250, 50, "Bullet");
	bullet->addComponent(new SpriteComponent(bullet, "Images/bullet.png"));
	bullet->getTransform()->setScale({ 50, 50 });*/

	Actor* player = new Actor(50, 50, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->getTransform()->setScale({ 50, 50 });

	enemy->getTransform()->setMaxVelovity(100);
	enemy->addComponent(new Behavior(enemy));
	enemy->addComponent(new SeekComponent(enemy, player));

	addActor(player);
	addActor(enemy);
	//addActor(bullet);
}
