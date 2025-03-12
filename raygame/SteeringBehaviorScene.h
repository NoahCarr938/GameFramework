#pragma once
#include "Scene.h"

class SteeringBehaviorScene : public Scene{
public:
	void start() override;
	void update(float deltaTime) override;
	void end() override;

private:
	
	Texture2D frame1 = LoadTexture("alienGreen_walk1.png");
	Texture2D frame2 = LoadTexture("alienGreen_walk2.png");
};