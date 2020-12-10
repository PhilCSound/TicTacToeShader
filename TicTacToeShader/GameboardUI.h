#pragma once
#include "TileUI.h"
#include <vector>
#include "BoardData.h"
#include "Gameboard.h"
class GameboardUI
{
public:
	GameboardUI(sf::FloatRect _sizeAndClickBox);
	bool ContainsPosition(sf::Vector2f _pos);
	void CreateUI(BoardData _data);
	void Draw(sf::RenderWindow & _window);
	Point GetTileOnClick(sf::Vector2f _pos);
	void Update(sf::Time _time);
	void UpdateTileUIColor(Point _point, sf::Color _color);

private:
	std::vector<TileUI> TileComponents;
	Point mapSize;
	sf::Vector2f tileSize;
	sf::Vector2f tilePadding;
	sf::FloatRect clickBox;

	void CalculateUISizes();
	sf::Vector2f CalculateTileLocation(Point _point);
};

