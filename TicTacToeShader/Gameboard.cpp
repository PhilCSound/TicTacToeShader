#include "Gameboard.h"


Gameboard::Gameboard(BoardData _boardData, sf::FloatRect _bounds)
	: UIComponent(_bounds)
{
	mapSize = _boardData.GetMapSize();
	CalculateUISizes();

	//Create the board
	for (Point i : _boardData.GetData())
	{
		sf::FloatRect _tileBounds(CalculateTileLocation(i), tileSize);
		Tile _tile(i, _tileBounds);
		board.emplace(i, _tile);
	}
}

bool Gameboard::IsPointWithinBounds(Point _point)
{
	if (_point.X < 0 || _point.Y < 0)
		return false;
	if (_point.X >= mapSize.x || _point.Y >= mapSize.y)
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

void Gameboard::Draw(sf::RenderWindow & _window)
{
	for (auto &i : board)
	{
		i.second.Draw(_window);
	}
}

Point* Gameboard::GetPointOnClick(sf::Vector2f _pos)
{
	for (auto &i : board)
	{
		if (i.second.ContainsPosition(_pos))
			return &i.second.GetLocation();
	}
	return nullptr;
}

void Gameboard::CalculateUISizes()
{
	//TODO TILE PADDING
	//Calculate padding between each tile, 12 being a constant in px.
	tilePadding = sf::Vector2f((12 * mapSize.x), (12 * mapSize.y));
	//Calculates tileSize
	tileSize = sf::Vector2f(((clickBox.width - tilePadding.x) / mapSize.x),
		((clickBox.height - tilePadding.y) / mapSize.y));
}

sf::Vector2f Gameboard::CalculateTileLocation(Point _point)
{
	//TODO VIDEO SETTINGS/PADDING
	float _posX = (_point.X * tileSize.x) + (12 * _point.X) + clickBox.left;
	float _posY = (_point.Y * tileSize.y) + (12 * _point.Y) + clickBox.top;
	return sf::Vector2f(_posX, _posY);
}

