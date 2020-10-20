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
void Gameboard::CreateGameboard(unsigned int _x, unsigned int _y)
{
	width = _x;
	height = _y;

	//Location where we start drawing the board
	sf::Vector2f _northEastCorner(Settings::BOARD_WEST_PADDING, Settings::BOARD_NORTH_PADDING);

	//Get the window size, Calculate padding offset for size of board bounds
	sf::Vector2f _winSize = sf::Vector2f(Settings::WINSIZE);
	int _yOffset = Settings::BOARD_NORTH_PADDING + Settings::BOARD_SOUTH_PADDING;
	int _xOffset = Settings::BOARD_EAST_PADDING + Settings::BOARD_WEST_PADDING;
	
	//Bounds of the board
	sf::Vector2f _boardBounds = _winSize - sf::Vector2f(_xOffset, _yOffset);

	//Calculate TilePaddingOffset and then TileSize.
	int _yTileOffset = Settings::BETWEEN_TILE_PADDING * height;
	int _xTileOffset = Settings::BETWEEN_TILE_PADDING * width;

	sf::Vector2f _tileSize = sf::Vector2f(((_boardBounds.x - _xTileOffset ) / width), 
		((_boardBounds.y - _yTileOffset) / height));

	//Now to fill the board
	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			Point _pos(x, y);
			if (!DoesPointExist(_pos) && IsPointWithinBounds(_pos))
			{
				int _tilePositionX = Settings::BOARD_EAST_PADDING + (x*Settings::BETWEEN_TILE_PADDING) + (x * _tileSize.x);
				int _tilePositionY = Settings::BOARD_NORTH_PADDING + (y*Settings::BETWEEN_TILE_PADDING) + (y * _tileSize.y);
				Tile _tile(_tileSize, sf::Vector2f(_tilePositionX, _tilePositionY));
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
