#pragma once
#include "PlayerEnum.h"
#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(unsigned int _x, unsigned int _y, PlayerEnum _player = PlayerEnum::NO_PLAYER);
	void ChangePlayer(PlayerEnum _player);
	bool ChangedPlayer();
	PlayerEnum GetPlayer() { return status; }
	unsigned int GetX() { return x; }
	unsigned int GetY() { return y; }
private:
	PlayerEnum status = PlayerEnum::NO_PLAYER;
	bool changed = false;
	unsigned int x;
	unsigned int y;
};

