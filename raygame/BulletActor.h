#pragma once
#include "Actor.h"


/// <summary>
/// The BulletActor is going to seek the enemy ship
/// </summary>
class BulletActor : public Actor
{
public:
	BulletActor();
	~BulletActor();

	MathLibrary::Vector2 bulletSpawn;
	bool collidedOnce;
	void Start();
	void Update(double deltaTime);
	void End();
	void OnCollision();
private:
	bool m_bulletHit = false;
};