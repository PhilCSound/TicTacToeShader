#pragma once
#include "PlayerEnum.h"
#include "SFML/Graphics.hpp"
#include "Point.h"

class Tile
{
public:
	Tile() {};
	Tile(Point _loc, PlayerEnum _player = PlayerEnum::NO_PLAYER);
	void ChangePlayer(PlayerEnum _player);
	bool ChangedPlayer();
	PlayerEnum GetPlayer() { return status; }
	const int GetX() { return location.X; }
	const int GetY() { return location.Y; }
	const Point GetLocation() { return location; }
private:
	PlayerEnum status = PlayerEnum::NO_PLAYER;
	bool changed = false;
	Point location;
};

