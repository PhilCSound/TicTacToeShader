#pragma once
#include "PlayerEnum.h"
#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile() { };
	Tile(sf::Vector2f _bounds, sf::Vector2f _position, PlayerEnum _player = PlayerEnum::NONE);
	void Draw(sf::RenderWindow &_window);
	void ChangePlayer(PlayerEnum _player);
	void ChangePosition(sf::Vector2f _pos);	
	void ChangeSize(sf::Vector2f _size);
private:
	sf::RectangleShape shape;
	PlayerEnum status = PlayerEnum::NONE;
};

