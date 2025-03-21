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


void BehaviorTreeScene::start()
{
	BehaviorTreeAgent agent(200, 200);
}

void BehaviorTreeScene::update(float deltaTime)
{

}

void BehaviorTreeScene::end()
{
}
