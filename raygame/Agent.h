#pragma once
#include "Actor.h"
#include "raylib.h"
#include "Behavior.h"
#include "Component.h"

class Agent : public Actor
{
public:
	Agent();
	Agent(float x, float y, const char* name);
	~Agent();
	void enableBehavior(int behavior);
	void disableBehavior(int behavior);
	void enableAll();
	void disableAll();
	void enableGame();
	void disableGame();
	bool getBehavior(int behavior);
private:
};