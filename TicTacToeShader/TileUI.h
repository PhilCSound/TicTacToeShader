#pragma once
#include "UIComponent.h"
#include "Tile.h"

class TileUI : public UIComponent
{
public:
	TileUI(Tile* _tile, sf::FloatRect _spriteSize);

	void Draw(sf::RenderWindow & _window);
	void Update(sf::Time _gameTime);
	Tile* GetTileInfo() { return tile; }
	void UpdateSpriteColor(sf::Color _color);


private:
	sf::RectangleShape sprite;
	Tile* tile;

};