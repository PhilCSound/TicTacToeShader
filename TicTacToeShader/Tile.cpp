#include "Tile.h"

Tile::Tile(sf::FloatRect _bounds, PlayerEnum _player)
	: shape(sf::Vector2f(_bounds.width, _bounds.height)), status(_player)
{
	SetBounds(_bounds);
	shape.setPosition(sf::Vector2f(_bounds.left, _bounds.top));
	shape.setOutlineColor(sf::Color(10, 173, 255, 255));
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
	shape.setFillColor(Settings::GetPlayerColor(_player));
}

void Tile::ChangePosition(sf::Vector2f _pos)
{
	shape.setPosition(_pos);
	bounds.left = _pos.x;
	bounds.top = _pos.y;
}

void Tile::ChangeSize(sf::Vector2f _size)
{
	shape.setSize(_size);
	bounds.width = _size.x;
	bounds.height = _size.y;
}

void Tile::Click(const sf::Vector2f _loc)
{
	ChangePlayer(PLAYER2);
}
