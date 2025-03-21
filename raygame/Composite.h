#pragma once
#include "BehaviorTree.h"
#include <vector>

class Composite : public BehaviorTree
{
public:
	Composite* add(BehaviorTree* child);
	void remove(BehaviorTree* child);
	void clear();

protected:
	typedef std::vector<BehaviorTree*> Behaviors;
	Behaviors m_children;
};