#pragma once
#include "GameLogic.h"

class Action
{
public:
	virtual void Execute(GameLogic* _logic) = 0;
};