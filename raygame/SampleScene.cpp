#include "SampleScene.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include "Pathfinding/pathfinding.h"
#include "Pathfinding/NodeMap.h"


void SampleScene::start()
{
	//This is a better comment
	/*Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });*/

	/*addActor(test);*/

	Agent* enemy = new Agent(150, 50, "Enemy");
	enemy->addComponent(new SpriteComponent(enemy, "Images/enemy.png"));
	enemy->getTransform()->setScale({ 50, 50 });

	Actor* bullet = new Actor(250, 50, "Bullet");
	bullet->addComponent(new SpriteComponent(bullet, "Images/bullet.png"));
	bullet->getTransform()->setScale({ 50, 50 });

	Actor* player = new Actor(50, 50, "Player");
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->getTransform()->setScale({ 50, 50 });

	enemy->getTransform()->setMaxVelovity(100);
	enemy->addComponent(new Behavior(enemy));
	enemy->addComponent(new SeekComponent(enemy, player));

	addActor(player);
	addActor(enemy);
	addActor(bullet);
}

void SampleScene::update(float deltaTime)
{
	/*Scene::update(deltaTime);*/

	Pathfinding::Node a(500, 500);
	Pathfinding::Node b(600, 400);
	Pathfinding::Node c(600, 600);

	a.ConnectTo(&b, 1);
	a.ConnectTo(&c, 4);
	List<Pathfinding::Node*> list;
	Pathfinding::DrawGraph(&a, &list);

	List<Pathfinding::Node*> path = { &a, &b, &c };
	Pathfinding::DrawPath(path, RED);

	Pathfinding::DrawNode(&a, false);
	Pathfinding::DrawNode(&b, true);
	Pathfinding::DrawNode(&c, false);

	/*Nodemap nodemap;
	nodeMap.cellSize = 32;
	List<std::string> asciiMap;
	asciiMap.pushBack("000000000000");
	asciiMap.pushBack("010111011100");
	asciiMap.pushBack("010101110110");
	asciiMap.pushBack("011100000010");
	asciiMap.pushBack("010111111110");
	asciiMap.pushBack("010000001000");
	asciiMap.pushBack("011111111110");
	asciiMap.pushBack("000000000000");
	nodeMap.Initialise(asciiMap);*/
}

void SampleScene::end()
{
	Scene::end();
}
