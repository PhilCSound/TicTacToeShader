#pragma once
#include <vector>
#include "ChangeTileAction.h"
#include "GameLogic.h"
class ActionQueue
{
public:
	ActionQueue();
	~ActionQueue();

	void ProcessActions(GameLogic* _logic);

private:
	std::vector<Action*> actionList;

};

