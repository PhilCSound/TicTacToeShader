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
	bool CreateMapFromData();
	bool CreateMapFromData(BoardData _boardData);
	void ClearAndReloadMapData();
	bool IsValidMove(Point _point, PlayerEnum _player);
	bool IsPointWithinBounds(Point _point);
	bool DoesPointExist(Point _point);
	Tile* GetTileAtPoint(Point _point);
	bool CheckForWin(Point _point, PlayerEnum _player, int _winCond);
	bool CheckForTie();
	void MakeMove(Point _point, PlayerEnum _player);
	int MatchingTilesInDirection(Point _orgin, Point _direction, PlayerEnum _player);

private:
	BoardData boardData;
	std::map<Point, Tile> board;
	Point mapSize;

};