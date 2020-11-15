#include "Tile.h"

Tile::Tile(unsigned int _x, unsigned int _y, PlayerEnum _player)
	: x(_x), y(_y), status(_player)
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
