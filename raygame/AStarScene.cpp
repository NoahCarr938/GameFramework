#include "AStarScene.h"
#include "Pathfinding/AStarNodeMap.h"
#include "Pathfinding/AStarPathAgent.h"

void AStarScene::start()
{
	m_nodeMapAStar.cellSize = 32;
	std::vector<std::string> asciiMap;
	asciiMap.push_back("0000000000000000000000");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111001111111110");
	asciiMap.push_back("0111111111111111111110");
	asciiMap.push_back("0111111111111111111110");
	asciiMap.push_back("0111111111011111111110");
	asciiMap.push_back("0111111110101111111110");
	asciiMap.push_back("0111111101110111111110");
	asciiMap.push_back("0111111011111011111110");
	asciiMap.push_back("0111110111111101111110");
	asciiMap.push_back("0111101111111110111110");
	asciiMap.push_back("0111011111111111011110");
	asciiMap.push_back("0000000000000000000000");
	m_nodeMapAStar.Initialise(asciiMap);

	// pathAgent is a pointer so we have to new it
	// Since we have made it new we need to delete
	m_pathAgentAStar = new AStarPathfinding::AStarPathAgent;
	// Setting the start node
	m_pathAgentAStar->SetNode(m_nodeMapAStar.GetNode(1, 1));
	m_pathAgentAStar->speed = 128;
}

void AStarScene::update(float deltaTime)
{
	bool drawNodeMap = true;
	Color lineColor = { 255, 255, 255, 255 };

	// This is currently using Dijkstras's algorithm
	m_nodeMapAStar.Draw(true);
	AStarPathfinding::DrawPath(m_pathAgentAStar->path, lineColor);

	// read mouseclicks, left for start node, end for right node
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		AStarPathfinding::Node* end = m_nodeMapAStar.GetClosestNode(mousePos);
		m_pathAgentAStar->GoToNode(end);
	}

	// Updating and drawing the pathAgent
	m_pathAgentAStar->Update(deltaTime);
	m_pathAgentAStar->Draw();
}

void AStarScene::end()
{
	delete m_pathAgentAStar;
}
