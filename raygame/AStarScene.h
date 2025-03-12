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
	DijkstrasPathfinding::NodeMap m_nodeMapAStar;
	DijkstrasPathfinding::PathAgent* m_pathAgentAStar;
};