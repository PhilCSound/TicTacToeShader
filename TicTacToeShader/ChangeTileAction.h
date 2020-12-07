#pragma once
#include "Action.h"
#include "GameLogic.h"
#include "Point.h"
#include "PlayerEnum.h"

class ChangeTileAction : public Action
{
	ChangeTileAction(PlayerEnum _player, Point _loc);
	void Execute(GameLogic* _logic) {
	}

private:
	PlayerEnum _player;
	Point _loc;
};