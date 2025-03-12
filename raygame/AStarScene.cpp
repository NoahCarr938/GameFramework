#include "AStarScene.h"
#include "Pathfinding/NodeMap.h"
#include "Pathfinding/PathAgent.h"

void AStarScene::start()
{
	m_nodeMapAStar.cellSize = 32;
	std::vector<std::string> asciiMap;
	asciiMap.push_back("000000000000000000000");
	asciiMap.push_back("010111000000000111100");
	asciiMap.push_back("010101111111111100110");
	asciiMap.push_back("011100000010010000010");
	asciiMap.push_back("010111111111110000110");
	asciiMap.push_back("010000001000000000100");
	asciiMap.push_back("011111111110000000100");
	asciiMap.push_back("000010000000000000100");
	asciiMap.push_back("000010000000000011100");
	asciiMap.push_back("010111011100000010000");
	asciiMap.push_back("010101110110000010000");
	asciiMap.push_back("011100000011111111100");
	asciiMap.push_back("010111111110000000100");
	asciiMap.push_back("010000001000000001100");
	asciiMap.push_back("011111111110000001000");
	asciiMap.push_back("000010001010000001000");
	asciiMap.push_back("000010001000000001000");
	asciiMap.push_back("010111011100000001100");
	asciiMap.push_back("010101110110000000110");
	asciiMap.push_back("011100000010000000010");
	asciiMap.push_back("010111111111111111010");
	asciiMap.push_back("010000001000000001010");
	asciiMap.push_back("011111111110000001110");
	asciiMap.push_back("000000000000000000000");
	m_nodeMapAStar.Initialise(asciiMap);

	// pathAgent is a pointer so we have to new it
	// Since we have made it new we need to delete
	m_pathAgentAStar = new DijkstrasPathfinding::PathAgent;
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
	DijkstrasPathfinding::DrawPath(m_pathAgentAStar->path, lineColor);

	// read mouseclicks, left for start node, end for right node
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		DijkstrasPathfinding::Node* end = m_nodeMapAStar.GetClosestNode(mousePos);
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
