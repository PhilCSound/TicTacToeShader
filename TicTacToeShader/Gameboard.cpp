#include "Gameboard.h"

Gameboard::Gameboard(BoardData _boardData) : boardData(_boardData)
{
	board.clear();
	CreateMapFromData();
}

bool Gameboard::CreateMapFromData()
{
	//Data is empty failed
	if (boardData.IsEmpty())
		return false;
	else
	{
		std::vector<Point> _data = boardData.GetData();
		for (auto &_point : _data)
		{
			Tile _tile(_point, NO_PLAYER);
			board.insert(std::pair<Point, Tile>(_point, _tile));
		}
		return true;
	}
}

bool Gameboard::CreateMapFromData(BoardData _boardData)
{
	//Data is empty failed
	if (_boardData.IsEmpty())
		return false;
	else
	{
		boardData = _boardData;
		CreateMapFromData();
		return true;
	}
}

void Gameboard::ClearAndReloadMapData()
{
	board.clear();
	CreateMapFromData();
}

bool Gameboard::IsValidMove(Point _point, PlayerEnum _player)
{
	if ((!IsPointWithinBounds(_point) && (!DoesPointExist(_point))))
		return false;
	if (GetTileAtPoint(_point)->GetPlayer() == NO_PLAYER)
		return true;
	return false;
}

bool Gameboard::IsPointWithinBounds(Point _point)
{
	if (_point.X >= mapSize.X || _point.Y >= mapSize.Y)
		return false;
	else
		return true;
}

bool Gameboard::DoesPointExist(Point _point)
{
		std::map<Point, Tile>::iterator _it = board.find(_point);
		//Doesn't exist
		if (_it == board.end()) {
			return false;
		}
		return true;
}

Tile* Gameboard::GetTileAtPoint(Point _point)
{
	return &board.at(_point);
}

bool Gameboard::CheckForWin(Point _orgin, PlayerEnum _player, int _winCond)
{
	int Vertical = MatchingTilesInDirection(_orgin, Point::North, _player);
	Vertical += 1 + MatchingTilesInDirection(_orgin, Point::South, _player);
	int Horizontal = MatchingTilesInDirection(_orgin, Point::East, _player);
	Horizontal += 1 + MatchingTilesInDirection(_orgin, Point::West, _player);
	int RightDiagonal = MatchingTilesInDirection(_orgin, Point::NorthEast, _player);
	RightDiagonal += 1 + MatchingTilesInDirection(_orgin, Point::SouthWest, _player);
	int LeftDiagonal = MatchingTilesInDirection(_orgin, Point::NorthWest, _player);
	LeftDiagonal += 1 + MatchingTilesInDirection(_orgin, Point::SouthEast, _player);

	if (Vertical >= _winCond || Horizontal >= _winCond
		|| RightDiagonal >= _winCond || LeftDiagonal >= _winCond)
			return true;
	else
		return false;
}

bool Gameboard::CheckForTie()
{
	for (auto &i : board)
	{
		if (i.second.GetPlayer() == NO_PLAYER)
			return false;
	}
	return true;
}

void Gameboard::MakeMove(Point _point, PlayerEnum _player)
{
	board.at(_point).ChangePlayer(_player);
}

int Gameboard::MatchingTilesInDirection(Point _orgin, Point _direction, PlayerEnum _player)
{
	int counter = 0;
	Point _loc = _orgin + _direction;
	while (DoesPointExist(_loc))
	{
		//Check to see if it same player, if not. Return.
		Tile* _tile = GetTileAtPoint(_loc);
		if (_tile->GetPlayer() != _player)
			return counter;	
		//Add one the counter and keep checking
		counter++;
		_loc += _direction;
	}
	return counter;
}
