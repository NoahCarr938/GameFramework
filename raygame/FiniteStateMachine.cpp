#include <iostream>
#include "FiniteStateMachine.h"
#include "raylib.h"

//int main()
//{
//	enum AIState
//	{
//		STATE_IDLE = 0,
//		STATE_SEEKING,
//		STATE_WANDERING,
//		STATE_FLEEING
//	};
//
//	int state = STATE_IDLE;
//
//	switch (state)
//	{
//	case STATE_IDLE:
//		std::cout << "Current state is Idle" << std::endl;
//		break;
//	case STATE_SEEKING:
//		std::cout << "Current state is Seeking" << std::endl;
//		break;
//	case STATE_WANDERING:
//		std::cout << "Current state is Wandering" << std::endl;
//		break;
//	case STATE_FLEEING:
//		std::cout << "Current state is Fleeing" << std::endl;
//		break;
//	default:
//		std::cout << "Unknown State" << std::endl;
//		break;
//	}
//}

FiniteStateMachineComponent::FiniteStateMachineComponent(Actor* owner)
{
	this->setDisabled();
}

FiniteStateMachineComponent::~FiniteStateMachineComponent()
{
	setDisabled();
}

void FiniteStateMachineComponent::handleSteeringBehaviors()
{
	int state = 0;

	switch (state)
	{
	case 0:
		if (!IsKeyPressed)
		{
			state = 0;
		}
		else if (IsKeyPressed(KEY_W))
		{
			state = 1;
		}
		break;
	case1:
		if (IsKeyPressed(KEY_W))
		{
			state = 1;
		}
		else if (IsKeyPressed(KEY_S))
		{
			state = 2;
		}
		break;
	case2:
		if (IsKeyPressed(KEY_S))
		{
			state = 2;
		}
		else if (IsKeyPressed(KEY_A))
		{
			state = 3;
		}
		break;
	case3:
		if (IsKeyPressed(KEY_A))
		{
			state = 3;
		}
		else if (IsKeyPressed(KEY_W))
		{
			state = 0;
		}
		break;
	}
}
