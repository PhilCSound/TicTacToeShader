#pragma once
#include "PlayerEnum.h"
#include "Tile.h"
#include <map>
#include "TextureManager.h"
#include "Application.h"
#include "Point.h"

class Application;


class Gameboard
{
public:
	Gameboard();
	void CreateGameboard(unsigned int _x, unsigned int _y);
	void Draw(sf::RenderWindow &_window);
	bool IsPointWithinBounds(Point _point);
	bool DoesPointExist(Point _point);
	Tile GetTileAtPoint(Point _point);
private:

	std::map<Point, Tile> board;
	unsigned int width, height;
};

