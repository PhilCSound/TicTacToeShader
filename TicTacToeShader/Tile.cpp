#include "Tile.h"

Tile::Tile(sf::Vector2f _bounds, sf::Vector2f _position, PlayerEnum _player)
	: shape(_bounds), status(_player)
{
	shape.setPosition(_position);
	shape.setOutlineColor(sf::Color(0, 255, 255, 155));
	shape.setOutlineThickness(-3);
}

void Tile::Draw(sf::RenderWindow & _window)
{
	_window.draw(shape);
}

void Tile::ChangePlayer(PlayerEnum _player)
{
	//TODO: SHADERRRRRRS AND COLORS?
	status = _player;
}

void Tile::ChangePosition(sf::Vector2f _pos)
{
	shape.setPosition(_pos);
}

void Tile::ChangeSize(sf::Vector2f _size)
{
	shape.setSize(_size);
}
