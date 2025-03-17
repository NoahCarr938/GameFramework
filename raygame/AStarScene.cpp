#include "AStarScene.h"
#include "Pathfinding/AStarNodeMap.h"
#include "Pathfinding/AStarPathAgent.h"

void AStarScene::start()
{
	m_nodeMapAStar.cellSize = 32;
	std::vector<std::string> asciiMap;
	
	/*asciiMap.push_back("000000000000000000000");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("011111111111111111110");*/
	asciiMap.push_back("000000000000000000000");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("000001000000010000010");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("011111100000000000110");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("000000000001111110110");
	asciiMap.push_back("011111111101111110110");
	asciiMap.push_back("011100000000000110110");
	asciiMap.push_back("011111111111111110110");
	asciiMap.push_back("011101111111110110110");
	asciiMap.push_back("011101111111110110110");
	asciiMap.push_back("011101111111110110110");
	asciiMap.push_back("011110111111101110110");
	asciiMap.push_back("011111011111011110110");
	asciiMap.push_back("011111100000111110110");
	asciiMap.push_back("011111111111111110110");
	asciiMap.push_back("011111111111111111110");
	asciiMap.push_back("000000000000000000000");
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
