#include "ActionQueue.h"



ActionQueue::ActionQueue()
{
}


ActionQueue::~ActionQueue()
{
	for (Action* i : actionList)
		delete i;
}

void ActionQueue::ProcessActions(GameLogic * _logic)
{
	for (Action* i : actionList)
	{
		i->Execute(_logic);
		delete i;
	}
	actionList.clear();
}
