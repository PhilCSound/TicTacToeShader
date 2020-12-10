#include "GameboardUI.h"

GameboardUI::GameboardUI(sf::FloatRect _sizeAndClickBox)
	: clickBox(_sizeAndClickBox)
{
}

bool GameboardUI::ContainsPosition(sf::Vector2f _pos)
{
	for (TileUI& i : TileComponents)
	{
		if (i.ContainsPosition(_pos))
			return clickBox.contains(_pos);
	}
	return false;
}

void GameboardUI::CreateUI(BoardData _data)
{
	mapSize = _data.GetSize();
	CalculateUISizes();

	std::vector<Point> _boardInfo = _data.GetData();
	for (Point &_p : _boardInfo)
	{
		sf::Vector2f _tileLoc = CalculateTileLocation(_p);
		TileUI _tileUI(_p, sf::FloatRect(_tileLoc, tileSize));
		TileComponents.push_back(_tileUI);
	}
}

void GameboardUI::Draw(sf::RenderWindow & _window)
{
	for (auto i : TileComponents)
	{
		i.Draw(_window);
	}
}

Point GameboardUI::GetTileOnClick(sf::Vector2f _pos)
{
	for (TileUI& i : TileComponents)
	{
		if (i.ContainsPosition(_pos)) {
			return i.GetPoint();
		}
	}
}

void GameboardUI::Update(sf::Time _time)
{
	for (TileUI& i : TileComponents)
	{
		i.Update(_time);
	}
}

void GameboardUI::UpdateTileUIColor(Point _point, sf::Color _color)
{
	for (TileUI& i : TileComponents)
	{
		if (i.GetPoint() == _point){
			i.UpdateSpriteColor(_color);
		}
	}
}

void GameboardUI::CalculateUISizes()
{
	//TODO TILE PADDING
	//Calculate padding between each tile, 12 being a constant in px.
	tilePadding = sf::Vector2f((mapSize.X * 12), (mapSize.Y * 12));
	//Calculates tileSize
	tileSize = sf::Vector2f(((clickBox.width - tilePadding.x) / mapSize.X),
		((clickBox.height - tilePadding.y) / mapSize.Y));
}

sf::Vector2f GameboardUI::CalculateTileLocation(Point _point)
{
	//TODO VIDEO SETTINGS/PADDING
	float _posX = (tileSize.x * _point.X ) + (_point.X * 12) + clickBox.left;
	float _posY = (tileSize.y * _point.Y) + (_point.Y * 12) + clickBox.top;
	return sf::Vector2f(_posX, _posY);
}