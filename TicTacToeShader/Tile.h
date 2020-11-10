#pragma once
#include "PlayerEnum.h"
#include "Settings.h"
#include "SFML/Graphics.hpp"
#include "MouseInteractable.h"

class Tile : public MouseInteractable
{
public:
	Tile() { };
	Tile(sf::FloatRect _bounds, PlayerEnum _player = PlayerEnum::NONE);
	void Draw(sf::RenderWindow &_window);
	void ChangePlayer(PlayerEnum _player);
	void ChangePosition(sf::Vector2f _pos);	
	void ChangeSize(sf::Vector2f _size);
	void Click(const sf::Vector2f _loc);
private:
	sf::RectangleShape shape;
	PlayerEnum status = PlayerEnum::NONE;
};

