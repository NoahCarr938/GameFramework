#include "SampleScene.h"
#include "Pathfinding/DijkstrasPathfinding.h"
#include "Pathfinding/NodeMap.h"


void SampleScene::start()
{
	Scene::start();

	// We dont need to make the node map it is in the header file
	m_nodeMap.cellSize = 32;
	std::vector<std::string> asciiMap;
	asciiMap.push_back("000000000000000000000");
	asciiMap.push_back("010111000000000111100");
	asciiMap.push_back("010101111111111100110");
	asciiMap.push_back("011100000010010000000");
	asciiMap.push_back("010111111111110000000");
	asciiMap.push_back("010000001000000000000");
	asciiMap.push_back("011111111110000000000");
	asciiMap.push_back("000010000000000000000");
	asciiMap.push_back("000010000000000000000");
	asciiMap.push_back("010111011100000000000");
	asciiMap.push_back("010101110110000000000");
	asciiMap.push_back("011100000010000000000");
	asciiMap.push_back("010111111110000000000");
	asciiMap.push_back("010000001000000000000");
	asciiMap.push_back("011111111110000000000");
	asciiMap.push_back("000010001010000000000");
	asciiMap.push_back("000010001000000000000");
	asciiMap.push_back("010111011100000000000");
	asciiMap.push_back("010101110110000000000");
	asciiMap.push_back("011100000010000000000");
	asciiMap.push_back("010111111110000000000");
	asciiMap.push_back("010000001000000000000");
	asciiMap.push_back("011111111110000000000");
	asciiMap.push_back("000000000000000000000");
	m_nodeMap.Initialise(asciiMap);

	// pathAgent is a pointer so we have to new it
	// Since we have made it new we need to delete
	m_pathAgent = new DijkstrasPathfinding::PathAgent;
	// Setting the start node
	m_pathAgent->SetNode(m_nodeMap.GetNode(1, 1));
	m_pathAgent->speed = 128;
}

void SampleScene::update(float deltaTime)
{
	// We do not have to begin and end the drawing, we are doing that in scene;
	bool drawNodeMap = true;
	Color lineColor = { 255, 255, 255, 255 };

	m_nodeMap.Draw(true);
	DijkstrasPathfinding::DrawPath(m_pathAgent->path, lineColor);

	// read mouseclicks, left for start node, end for right node
	if (IsMouseButtonPressed(0))
	{
		Vector2 mousePos = GetMousePosition();
		DijkstrasPathfinding::Node* end = m_nodeMap.GetClosestNode(mousePos);
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
