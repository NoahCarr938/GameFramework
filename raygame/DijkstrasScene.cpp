#include "DijkstrasScene.h"
#include "Pathfinding/DijkstrasPathfinding.h"
#include "Pathfinding/NodeMap.h"


void DijkstrasScene::start()
{
	Scene::start();

	// We dont need to make the node map it is in the header file
	m_nodeMap.cellSize = 32;
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
	m_nodeMap.Initialise(asciiMap);

	// pathAgent is a pointer so we have to new it
	// Since we have made it new we need to delete
	m_pathAgent = new DijkstrasPathfinding::PathAgent;
	// Setting the start node
	m_pathAgent->SetNode(m_nodeMap.GetNode(1, 1));
	m_pathAgent->speed = 128;
}

void DijkstrasScene::update(float deltaTime)
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

void DijkstrasScene::end()
{
	delete m_pathAgent;
}
