#pragma once
#include "Actor.h"
#include "raylib.h"

class Agent : public Actor
{
public:
	Agent();
	Agent();
	~Agent();

	void Start();
	void Update();
	void End();
	void Draw();

private:
	Agent m_pathAgent;

	Color m_color;

};