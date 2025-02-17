#pragma once
#include "raylib.h"
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	~Player();
	Player(float x, float y, const char* name);
	float speed = 10;
	void Start();
	void Update(float deltaTime);
	void End();

private:
	bool m_playerHit = false;
	int m_score = 0;
};