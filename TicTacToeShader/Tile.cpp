#include "Tile.h"

Tile::Tile(Point _loc, PlayerEnum _player)
	: location(_loc), status(_player)
{
}

void Tile::ChangePlayer(PlayerEnum _player)
{
	//TODO: SHADERS? COLORS? ANIMATIONS?
	if (status == _player)
		return;
	status = _player;
	changed = true;
}

bool Tile::ChangedPlayer()
{
	if (changed) {
		!changed;
		return true;
	}
	return false;
}
