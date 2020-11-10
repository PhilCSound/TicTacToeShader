#pragma once
#include "PlayerEnum.h"
#include "Tile.h"
#include <map>
#include "TextureManager.h"
#include "Application.h"
#include "Point.h"
#include "MouseInteractable.h"

class Application;


class Gameboard : public MouseInteractable
{
public:
	Gameboard();
	void CreateGameboard(sf::FloatRect _bounds, unsigned int _width, unsigned int _height);
	void Draw(sf::RenderWindow &_window);
	bool IsPointWithinBounds(Point _point);
	bool DoesPointExist(Point _point);
	Tile GetTileAtPoint(Point _point);
	void Click(const sf::Vector2f _loc);
private:
	std::map<Point, Tile> board;
	unsigned int width, height;
};