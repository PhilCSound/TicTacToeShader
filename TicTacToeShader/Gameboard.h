#pragma once
#include "PlayerEnum.h"
#include "Tile.h"
#include <map>
#include "Point.h"
#include "BoardData.h"
#include <functional>

class Application;


class Gameboard
{
public:
	Gameboard(BoardData _boardData);
	void CreateUI(std::function<void(Tile*)> _F);
	bool IsPointWithinBounds(Point _point);
	bool DoesPointExist(Point _point);
	Tile* GetTileAtPoint(Point _point);
private:
	std::map<Point, Tile> board;
	unsigned int width, height;
};