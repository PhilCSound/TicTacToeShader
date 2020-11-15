#include "GameboardUI.h"

GameboardUI::GameboardUI(sf::FloatRect _sizeAndClickBox, BoardData _boardData, PlayerData* _p, GameLogic* _l)
	: UIComponent(_sizeAndClickBox), width(_boardData.GetWidth()),
		height(_boardData.GetHeight()), playerData(_p), gameLogic(_l)
{
	//Total of the padding between tiles.
	//TODO VIDEO SETTING AND PADDING
	int _yPaddingTotal = 12 * (height - 1);
	int _xPaddingTotal = 12 * (width - 1);
	tileSize = sf::Vector2f(((clickBox.width - _xPaddingTotal) / width),
		((clickBox.height - _yPaddingTotal) / height));
}

void GameboardUI::Draw(sf::RenderWindow & _window)
{
	for (auto i : TileComponents)
	{
		i.Draw(_window);
	}
}

void GameboardUI::CreateTileComponent(Tile * _tile)
{
	float _positionX = (_tile->GetX() * tileSize.x) + 
		(12* _tile->GetX()) + clickBox.left;
	float _positionY = (_tile->GetY() * tileSize.y) + 
		(12* _tile->GetY()) + clickBox.top;
	sf::FloatRect _rect(sf::Vector2f(_positionX, _positionY), tileSize);
	TileUI _uiTile(_tile, _rect);
	TileComponents.push_back(_uiTile);
}

void GameboardUI::OnClick(sf::Vector2f _pos)
{
	for (TileUI& i : TileComponents)
	{
		if (i.ContainsPosition(_pos)) {
			gameLogic->MakeMove(i.GetTileInfo());
			//TODO Look into making a Player Class to undo this rats nest..
			if (i.GetTileInfo()->ChangedPlayer())
				i.UpdateSpriteColor(playerData->GetPlayerColor(i.GetTileInfo()->GetPlayer()));
		}
	}
}

void GameboardUI::SetOnTileClick(void(*_click)(Tile *))
{
	HandleTileClick = _click;
}

void GameboardUI::Update(sf::Time _time)
{
	for (auto i : TileComponents)
	{
		i.Update(_time);
	}
}
