#pragma once
#include <vector>
#include "raylib.h"
#include "Component.h"

class AnimatedSpriteComponent : public Component
{
private:
	struct Frame {
		Texture2D m_texture;
		float m_delay;
		Frame(Texture2D texture, float delay) : m_texture(texture), m_delay(delay) {}
	};

public:
	AnimatedSpriteComponent();
	~AnimatedSpriteComponent();

	void AddFrame(Texture2D texture, float delay);

	void Update(float deltaTime);
	void Draw(int x, int y);

private:
	std::vector<Frame> m_frames;
	int m_currentFrame;
	float m_timer;
};