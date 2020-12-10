#include "Tile.h"

Tile::Tile(Point _loc, PlayerEnum _player)
	: location(_loc), status(_player)
{
}

void Tile::ChangePlayer(PlayerEnum _player)
{
	if (status == _player)
		return;
	status = _player;
}

