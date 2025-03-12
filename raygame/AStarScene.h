#pragma once
#include "Scene.h"
#include "Pathfinding/AStarNodeMap.h"
#include "Pathfinding/AStarPathAgent.h"

class AStarScene : public Scene{
public:
	void start() override;
	void update(float deltaTime) override;
	void end() override;

private:
	AStarPathfinding::AStarNodeMap m_nodeMapAStar;
	AStarPathfinding::AStarPathAgent* m_pathAgentAStar;
};