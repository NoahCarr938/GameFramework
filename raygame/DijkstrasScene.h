#pragma once
#include "Scene.h"
#include "Pathfinding/NodeMap.h"
#include "Pathfinding/PathAgent.h"

class DijkstrasScene :
    public Scene
{
public:
    void start() override;
    void update(float deltaTime) override;
    void end() override;

private:
    // Need a NodeMap and PathAgent
    // Remember that they are in namespace Pathfinding
    DijkstrasPathfinding::NodeMap m_nodeMap;
    // Path Agent is not actually an actor so we have to manually update it
    DijkstrasPathfinding::PathAgent* m_pathAgent;
};

