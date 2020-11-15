#pragma once
#include "UIComponent.h"
#include "TileUI.h"
#include <vector>
#include "BoardData.h"
#include "PlayerData.h"
#include "GameLogic.h"

class GameboardUI : public UIComponent
{
public:
	GameboardUI(sf::FloatRect _sizeAndClickBox, BoardData _boardData, PlayerData* _playerData, GameLogic* _logic);
	void Draw(sf::RenderWindow & _window);
	void CreateTileComponent(Tile *_tile);
	void OnClick(sf::Vector2f _pos);
	void SetOnTileClick(void(*_click)(Tile*));
	void Update(sf::Time _time);
private:
	std::vector<TileUI> TileComponents;
	void(*HandleTileClick)(Tile*) = nullptr;
	unsigned width, height;
	sf::Vector2f tileSize;
	PlayerData* playerData;
	GameLogic* gameLogic;
};

