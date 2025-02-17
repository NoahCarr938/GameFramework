#include "BulletActor.h"
#include "Player.h"
#include "Enemy.h"
#include "raylib.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "SampleScene.h"

BulletActor::BulletActor()
{
}

BulletActor::~BulletActor()
{
}

void BulletActor::Start()
{
	m_started = true;
	collidedOnce = false;
}

void BulletActor::Update(double deltaTime)
{
}

void BulletActor::End()
{
}

void BulletActor::OnCollision()
{
}
