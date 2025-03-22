#pragma once
#include "DynamicArray.h"
#include "Component.h"
#include "Vector2.h"

class Transform2D;
class Collider;
class Component;

class Actor
{
public:

    /*DynamicArray<Component*> m_components;
    DynamicArray<Component*> m_componentsToBeRemoved;*/

    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    float speed = 200;
    float rotationSpeed = 5;

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; }

    /// <summary>
    /// Iterates through all components in the component array to find one
    /// that matches the given name.
    /// </summary>
    /// <param name="componentName">The name of the component to search for.</param>
    /// <returns>A pointer to the component if a match was found.
    /// Returns nullptr if a match wasn't found.</returns>
    template <typename T> 
    T* getComponent();
    /*Component* getComponent(const char* componentName);*/

    template <typename T>
    T* addComponent(T* component);
    /*Component* addComponent(Component* component);*/

    template <typename T>
    T* removeComponent(T* component);
    /*bool removeComponent(const char* componentName);*/

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

    /*Transform2D* m_transform;
    bool m_started;*/

protected:
    const char* m_name;
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    DynamicArray<Component*> m_components;
private:
    
};

template<typename T>
inline T* Actor::getComponent()
{
    for (Component* element : m_components)
    {
        if (dynamic_cast<T*>(element) != nullptr)
        {
            return dynamic_cast<T*>(element);
        }
    }
    return nullptr;
}

template<typename T>
inline T* Actor::addComponent(T* component)
{
    Component* ptr = dynamic_cast<Component*>(component);
    if (ptr == nullptr)
        return nullptr;
    else
    {
        Actor* owner = component->getOwner();
        if (owner && owner != this)
        {
            return nullptr;
        }
        m_components.Add(component);
        return component;
    }
}

template<typename T>
inline T* Actor::removeComponent(T* component)
{
    Component* ptr = dynamic_cast<Component*>(component);
    if (ptr == nullptr)
        return nullptr;
    else
    {
        if (!component)
        {
            return false;
        }
        if (m_components.Contains(component))
        {
            m_components.Remove(component);
            return true;
        }
    }
    return false;
}
