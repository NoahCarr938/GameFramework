#pragma once
#include "Scene.h"

class BehaviorTreeScene : public Scene {
public:
	void start() override;
	void update(float deltaTime) override;
	void end() override;
private:
};