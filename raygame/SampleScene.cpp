#include "SampleScene.h"
#include "Pathfinding/pathfinding.h"
#include "Pathfinding/NodeMap.h"


void SampleScene::start()
{
	Scene::start();

	// We dont need to make the node map it is in the header file
	m_nodeMap.cellSize = 32;
	std::vector<std::string> asciiMap;
	asciiMap.push_back("000000000000");
	asciiMap.push_back("010111011110");
	asciiMap.push_back("010101110110");
	asciiMap.push_back("011100000010");
	asciiMap.push_back("010111111110");
	asciiMap.push_back("010000001000");
	asciiMap.push_back("01111111110");
	asciiMap.push_back("000010000010");
	asciiMap.push_back("000010000000");
	asciiMap.push_back("010111011100");
	asciiMap.push_back("010101110110");
	asciiMap.push_back("011100000010");
	asciiMap.push_back("010111111110");
	asciiMap.push_back("010000001000");
	asciiMap.push_back("011111111110");
	asciiMap.push_back("000010001010");
	asciiMap.push_back("000010001000");
	asciiMap.push_back("010111011100");
	asciiMap.push_back("010101110110");
	asciiMap.push_back("011100000010");
	asciiMap.push_back("010111111110");
	asciiMap.push_back("010000001000");
	asciiMap.push_back("011111111110");
	asciiMap.push_back("000000000000");
	m_nodeMap.Initialise(asciiMap);

	// pathAgent is a pointer so we have to new it
	// Since we have made it new we need to delete
	m_pathAgent = new pathfinding::PathAgent;
	// Setting the start node
	m_pathAgent->SetNode(m_nodeMap.GetNode(1, 1));
	m_pathAgent->speed = 64;
}

void SampleScene::update(float deltaTime)
{
	// We do not have to begin and end the drawing, we are doing that in scene;
	bool drawNodeMap = true;
	Color lineColor = { 255, 255, 255, 255 };

	m_nodeMap.Draw(true);
	pathfinding::DrawPath(m_pathAgent->path, lineColor);

	// read mouseclicks, left for start node, end for right node
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		pathfinding::Node* end = m_nodeMap.GetClosestNode(mousePos);
		m_pathAgent->GoToNode(end);
	}

	// Updating and drawing the pathAgent
	m_pathAgent->Update(deltaTime);
	m_pathAgent->Draw();
}

void SampleScene::end()
{
	delete m_pathAgent;
}
