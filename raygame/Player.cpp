#include "Player.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "Collider.h"
#include "AABBCollider.h"
#include "raylib.h"

Player::Player()
{
	m_transform = new Transform2D(this);
}

Player::~Player()
{
	delete m_transform;
}

Player::Player(float x, float y, const char* name)
{
	//Initializing the default values
	m_transform = new Transform2D(this);
	m_transform->setLocalPosition({ x, y });
	m_name = name;
}

void Player::Start()
{
	Actor::start();

	if (m_transform->getLocalPosition().y != (GetScreenHeight() * .9))
	{
		m_transform->setLocalPosition(MathLibrary::Vector2((GetScreenWidth() * .45), (GetScreenHeight() * .9)));
	}
}

void Player::Update(float deltaTime)
{
	Actor::update(deltaTime);



	//// Player Movement
	//MathLibrary::Vector2 movementInput = MathLibrary::Vector2();
	//if (IsKeyDown(KEY_W) && m_transform->getLocalPosition().y > 5)
	//    movementInput.y += 10;
	//if (IsKeyDown(KEY_S) && m_transform->getLocalPosition().y < 5)
	//	movementInput.y -= 10;
	//if (IsKeyDown(KEY_A) && m_transform->getLocalPosition().x > 5)
	//	movementInput.x -= 10;
	//if (IsKeyDown(KEY_D) && m_transform->getLocalPosition().x < GetScreenWidth() * .86)
	//	movementInput.x += 10;

	//MathLibrary::Vector2 deltaMovement = movementInput.getNormalized() * speed * (float)deltaTime;

	//if (deltaMovement.getMagnitude() != 0)
	//	m_transform->setLocalPosition(m_transform->getLocalPosition() + deltaMovement);

	DrawText(TextFormat("Points %i", m_score), 320, 40, 40, RED);
}

void Player::End()
{
	Actor::end();
}
