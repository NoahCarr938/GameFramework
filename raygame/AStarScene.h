#pragma once
#include "Scene.h"
#include "Pathfinding/NodeMap.h"
#include "Pathfinding/PathAgent.h"

class AStarScene : public Scene{
public:
	void start() override;
	void update(float deltaTime) override;
	void end() override;

private:
	pathfinding::NodeMap m_nodeMapAStar;
	pathfinding::PathAgent* m_pathAgentAStar;
};