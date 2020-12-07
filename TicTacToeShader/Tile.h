#pragma once
#include "PlayerEnum.h"
#include "SFML/Graphics.hpp"
#include "Point.h"
#include "UIComponent.h"

class Tile : public UIComponent
{
public:
	Tile(Point _point, sf::FloatRect _bounds , PlayerEnum _player = NO_PLAYER);
	void ChangePlayer(PlayerEnum _player);
	void ChangeColor(sf::Color _color);
	bool ChangedPlayer();
	const PlayerEnum& GetPlayer() { return player; }
	Point GetLocation() { return location; }
	void Draw(sf::RenderWindow &window);

private:
	PlayerEnum player;
	Point location;
	sf::RectangleShape sprite;
	bool changed = false;
};

