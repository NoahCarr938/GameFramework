#include "SampleScene.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "Transform2D.h"
#include "Agent.h"

void SampleScene::start()
{
	//This is a better comment
	/*Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });*/

	/*addActor(test);*/

	/*Actor* enemy = new Actor(150, 50, "Enemy");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->getTransform()->setScale({ 50, 50 });

	Actor* bullet = new Actor(250, 50, "Bullet");
	bullet->addComponent(new SpriteComponent(bullet, "Images/bullet.png"));
	bullet->getTransform()->setScale({ 50, 50 });

	Actor* player = new Actor(50, 50, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->addComponent(new SeekComponent(player, enemy));
	player->getTransform()->setScale({ 50, 50 });*/

	Agent* enemy = new Agent(150, 50, "Enemy");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	//enemy->addComponent(new SeekComponent(player, enemy));
	enemy->getTransform()->setScale({ 50, 50 });

	Agent* bullet = new Agent(250, 50, "Bullet");
	bullet->addComponent(new SpriteComponent(bullet, "Images/bullet.png"));
	bullet->getTransform()->setScale({ 50, 50 });

	Agent* player = new Agent(50, 50, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->addComponent(new SeekComponent(player, enemy));
	player->getTransform()->setScale({ 50, 50 });

	

	addActor(player);
	addActor(enemy);
	addActor(bullet);
}

void SampleScene::update(double deltaTime)
{
	Scene::update(deltaTime);
}

void SampleScene::end()
{
	Scene::end();
}
