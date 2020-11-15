#include "Gameboard.h"

Gameboard::Gameboard(BoardData _boardData)
	: width(_boardData.GetWidth()), height(_boardData.GetHeight())
{
	board.clear();
	std::vector<Point> _data = _boardData.GetData();
	for (auto _point : _data)
	{
		Tile _tile(_point.X, _point.Y, NO_PLAYER);
		board.insert(std::pair<Point, Tile>(_point, _tile));
	}
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

bool Gameboard::IsPointWithinBounds(Point _point)
{
	if (_point.X > width || _point.Y > height)
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

