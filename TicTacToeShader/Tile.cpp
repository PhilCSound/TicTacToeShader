#include "Tile.h"

Tile::Tile(Point _loc, sf::FloatRect _bounds, PlayerEnum _player)
	: UIComponent(_bounds), location(_loc), player(_player)
{
	sprite.setPosition(_bounds.left, _bounds.top);
	sprite.setSize(sf::Vector2f(_bounds.width, _bounds.height));
	sprite.setOutlineThickness(-3);
	sprite.setOutlineColor(sf::Color::Cyan);
}

void Tile::ChangePlayer(PlayerEnum _player)
{
	//TODO: SHADERS? COLORS? ANIMATIONS?
	if (player == _player)
		return;
	player = _player;
	changed = true;
}

void Tile::ChangeColor(sf::Color _color)
{
	sprite.setFillColor(_color);
}

bool Tile::ChangedPlayer()
{
	return false;
}

void Tile::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}
