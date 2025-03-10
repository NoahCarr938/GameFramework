#include "pathfinding.h"
#include <stdio.h>

namespace Pathfinding
{

	bool NodeSort(Node* i, Node* j)
	{
		return (i->gScore < j->gScore);
	}

	void Node::ConnectTo(Node* other, float cost)
	{
		connections.pushBack(Edge(other, cost));
	}

	List<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
	{
		//Validate the input
		if (startNode == nullptr || endNode == nullptr)
		{
			return List<Node*>();
		}

		if (startNode == endNode)
		{
			List<Node*> singleNodePath;
			singleNodePath.pushBack(startNode);
			return singleNodePath;
		}

		//Initialize the starting node
		startNode->gScore = 0;
		startNode->previous = nullptr;

		//Create our temporary lists for storing nodes
		List<Node*> openList;
		List<Node*> closedList;

		//Add the starting node to openList
		openList.pushBack(startNode);


		while (openList.getLength() > 0)
		{
			//Set the current node to the first node in the openList
			Node* currentNode = openList.first();
			//Remove currentNode from openList
			openList.popFront();
			//Add currentNode to closedList
			closedList.pushBack(currentNode);

			//If the destination node was added to the closed list,
			//the shortest path has been found
			if (currentNode == endNode)
			{
				break;
			}

			//For each Edge e in currentNode's connections
			for (Edge e : currentNode->connections)
			{
				//If the target node is in the closedList, ignore it
				if (closedList.find(e.target) != closedList.end()) {
					continue;
				}
				//If the target node is not in the openList, update it
				if (openList.find(e.target) == openList.end()) {
					//Calculate the target node's G Score
					e.target->gScore = currentNode->gScore + e.cost;
					//Set the target node's previous to currentNode
					e.target->previous = currentNode;
					//Push the targetr into the open list
					openList.pushFront(e.target);

				}
				//Otherwise the target node IS in the open list
				else {
					//Compare the new G Score to the old one before updating
					if (currentNode->gScore + e.cost < e.target->gScore) {
						//Calculate the target node's G Score
						e.target->gScore = currentNode->gScore + e.cost;
						//Set the target node's previous to currentNode
						e.target->previous = currentNode;
						//Find the earliest point we should insert the node
					    //to the list to keep it sorted
						auto insertionPos = openList.end();
						int index = 0;
						for (auto i = openList.begin(); i != openList.end(); i++) {
							if (e.target->gScore < (*i)->gScore) {
								break;
							}
						}
						//Insert the node at the appropriate position
						openList.insert(e.target, index);
					}
				}
			}
		}

		//Create path in reverse from endNode to startNode
		List<Node*> path;
		Node* currentNode = endNode;

		while (currentNode != nullptr)
		{
			//Add the current node to the beginning of the path
			path.pushFront(currentNode);
			//Go to the previous node
			currentNode = currentNode->previous;
		}

		return path;
	}

	void DrawPath(List<Node*>& path, Color lineColor)
	{
		auto currentIter = path.begin();
		auto previousIter = currentIter;
		currentIter++;
		for (currentIter; currentIter != path.end(); currentIter++, previousIter++)
		{
			// (*previousIter)
			DrawLine(
				(*previousIter)->position.x,
				(*previousIter)->position.y,
				(*previousIter)->position.x,
				(*previousIter)->position.y,
				lineColor);
		}
	}

	void DrawNode(Node* node, bool selected)
	{
		// Making a static char buffer that allows for 10 things to be in it
		static char buffer[10];
		sprintf_s(buffer, "%.0f", node->gScore);

		//Draw the circle for the outline
		DrawCircle(node->position.x, node->position.y, 25, YELLOW);
		//Draw the inner circle
		if (selected)
		{
			DrawCircle(node->position.x, node->position.y, 22, BROWN);
		}
		else
		{
			DrawCircle(node->position.x, node->position.y, 22, BLACK);
		}
		//Draw the text
		DrawText(buffer, node->position.x - 10, node->position.y - 10, 15, WHITE);
	}

	void DrawGraph(Node* node, List<Node*>* drawnList)
	{
		DrawNode(node);
		drawnList->pushBack(node);

		//For each Edge in this node's connections
		for (Edge edge : node->connections)
		{
			//Draw the Edge
			DrawLine(node->position.x, node->position.y, edge.target->position.x, edge.target->position.y, WHITE);
			//Draw the cost
			Vector2 costPos = { (node->position.x + edge.target->position.x) / 2, (node->position.y + edge.target->position.y) / 2 };
			static char buffer[10];
			sprintf_s(buffer, "%.0f", edge.cost);
			DrawText(buffer, costPos.x, costPos.y, 15, WHITE);
			//Draw the target node
			// Try to use list->find instead
			if (drawnList->find(edge.target) == drawnList->end());
			{
				DrawGraph(edge.target, drawnList);
			}
		}
	}
}