#pragma once
#include "UIComponent.h"
#include "BoardData.h"
#include "PlayerEnum.h"
#include "Tile.h"
#include <map>
#include "Point.h"


class Gameboard : public UIComponent
{
public:
	Gameboard(BoardData _boardData, sf::FloatRect _bounds);
	bool IsPointWithinBounds(Point _point);
	bool DoesPointExist(Point _point);
	Tile* GetTileAtPoint(Point _point);
	void Draw(sf::RenderWindow & _window);
	Point* GetPointOnClick(sf::Vector2f _pos);

private:
	std::map<Point, Tile> board;
	sf::Vector2i mapSize;
	sf::Vector2f tileSize;
	sf::Vector2f tilePadding;

	void CalculateUISizes();
	sf::Vector2f CalculateTileLocation(Point _point);
};