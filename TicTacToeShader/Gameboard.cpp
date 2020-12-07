#include "Gameboard.h"

Gameboard::Gameboard()
{
}

Gameboard::Gameboard(BoardData _boardData) : boardData(_boardData)
{
	board.clear();
	CreateMapFromData();
}

void Gameboard::CreateUI(std::function<void(Tile*)> _F)
{
	//Go through every entry in board and call the UI function for that Tile.
	//Dont forget board is a map, and entrys are pair<Point, Tile>
	for (auto &_entry : board)
	{
		_F(&_entry.second);
	}
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
		std::vector<Point> _data = boardData.GetData();
		for (auto &_point : _data)
		{
			Tile _tile(_point, NO_PLAYER);
			board.insert(std::pair<Point, Tile>(_point, _tile));
		}
		return true;
	}
}

void Gameboard::ClearAndReloadMapData()
{
	board.clear();
	CreateMapFromData();
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

