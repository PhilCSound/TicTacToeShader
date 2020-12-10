#pragma once
#include "UIComponent.h"
#include "Tile.h"
#include "Point.h"
#include "PlayerEnum.h"

class TileUI : public UIComponent
{
public:
	TileUI(Point _loc, sf::FloatRect _spriteSize);

	void Draw(sf::RenderWindow & _window);
	void Update(sf::Time _gameTime);
	Point GetPoint() { return point; }
	void UpdateSpriteColor(sf::Color _color);


private:
	sf::RectangleShape sprite;
	Point point;
};