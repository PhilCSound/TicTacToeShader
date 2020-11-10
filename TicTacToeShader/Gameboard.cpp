#include "Gameboard.h"
#include "Settings.h"

//TODO: While allows for more interesting maps than a standard two dimensional array...
//This still wont have the flexibility I want possibly in the future......	
//A linked list with pointers to each tile in each direction I think would suit me better..?
//Or I can Make a base tile class and make a Empty Tile class? Oh the decisions to be made later...
Gameboard::Gameboard()
{
}

//TODO Clean this up later.
void Gameboard::CreateGameboard(sf::FloatRect _bounds, unsigned int _width, unsigned int _height)
{
	SetBounds(_bounds);
	width = _width;
	height = _height;


	//Location where we start drawing the board
	sf::Vector2f _northEastCorner(_bounds.left, _bounds.top);

	//Total of the padding between tiles.
	int _yPaddingTotal = Settings::BETWEEN_TILE_PADDING * (height-1);
	int _xPaddingTotal = Settings::BETWEEN_TILE_PADDING * (width-1);

	sf::Vector2f _tileSize = sf::Vector2f(((_bounds.width - _xPaddingTotal ) / width), 
		((_bounds.height - _yPaddingTotal) / height));

	//Now to fill the board
	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			Point _pos(x, y);
			if (!DoesPointExist(_pos) && IsPointWithinBounds(_pos))
			{
				int _tilePositionX = _bounds.left + (x*Settings::BETWEEN_TILE_PADDING) + (x * _tileSize.x);
				int _tilePositionY = _bounds.top + (y*Settings::BETWEEN_TILE_PADDING) + (y * _tileSize.y);
				Tile _tile(sf::FloatRect(sf::Vector2f(_tilePositionX, _tilePositionY), _tileSize));
				board.insert(std::pair<Point, Tile>(_pos, _tile));
			}
		}
	}
}

//Deciding against vertex arrays a
void Gameboard::Draw(sf::RenderWindow &_window)
{
	std::map<Point, Tile>::iterator _it;
	
	for (_it = board.begin(); _it != board.end(); _it++)
	{
		_it->second.Draw(_window);
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

Tile Gameboard::GetTileAtPoint(Point _point)
{
	if (!DoesPointExist(_point))
	{
		//TODO: ERROR HANDLING prob throw exception for now a blank tile
		return Tile();
	}
	return board.at(_point);
}

void Gameboard::Click(const sf::Vector2f _loc)
{
	std::map<Point, Tile>::iterator _it;
	for (_it = board.begin(); _it != board.end(); _it++)
	{
		if (_it->second.ContainsPoint(_loc))
		{
			_it->second.Click(_loc);
			return;
		}
	}
}

