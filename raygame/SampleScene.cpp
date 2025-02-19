#include "SampleScene.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "Transform2D.h"

void SampleScene::start()
{
	//This is a better comment
	/*Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });*/

	/*addActor(test);*/

	Actor* player = new Actor(50, 50, 10, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->addComponent(new MovementComponent(player));
	player->getTransform()->setScale({ 50, 50 });

	addActor(player);

	Actor* enemy = new Actor(150, 50, 0, "Enemy");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->getTransform()->setScale({ 50, 50 });

	addActor(enemy);

}

void SampleScene::update(double deltaTime)
{
	Scene::update(deltaTime);
}

void SampleScene::end()
{
	Scene::end();
}
