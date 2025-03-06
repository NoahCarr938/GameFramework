#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"
#include "raylib.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;

    m_transform->updateTransforms();

    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->start();
    }
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->onCollision(other);
    }
}

void Actor::update(float deltaTime)
{
    m_transform->updateTransforms();

    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->update(deltaTime);
    }

    ////Player Rotation
    //if (IsKeyDown(KEY_RIGHT))
    //    m_transform->rotate(rotationSpeed * -1 * (float)deltaTime);
    //if (IsKeyDown(KEY_LEFT))
    //    m_transform->rotate(rotationSpeed * 1 * (float)deltaTime);

    // //Player Movement
    //MathLibrary::Vector2 movementInput = MathLibrary::Vector2();
    //if (IsKeyDown(KEY_W) && m_transform->getLocalPosition().y > 5)
    //    movementInput.y -= 10;
    //if (IsKeyDown(KEY_S) && m_transform->getLocalPosition().y > 5)
    //    movementInput.y += 10;
    //if (IsKeyDown(KEY_A) && m_transform->getLocalPosition().x > 5)
    //    movementInput.x -= 10;
    //if (IsKeyDown(KEY_D) && m_transform->getLocalPosition().x < GetScreenWidth() * .86)
    //    movementInput.x += 10;

    //MathLibrary::Vector2 deltaMovement = movementInput.getNormalized() * speed * (float)deltaTime;

    //if (deltaMovement.getMagnitude() != 0)
    //    m_transform->setLocalPosition(m_transform->getLocalPosition() + deltaMovement);
}

void Actor::draw()
{
    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->draw();
    }
}

void Actor::end()
{
    m_started = false;
    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->end();
    }
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());

    for (int i = 0; i < m_components.Length(); i++)
    {
        m_components[i]->onDestroy();
    }
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}