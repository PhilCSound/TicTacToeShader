#pragma once
#include "State.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "Gameboard.h"
#include "AnimatedBackground.h"
#include "GameboardUI.h"
#include "PlayerData.h"
#include "BoardData.h"
#include "GameLogic.h"
#include <functional>


class PlayState : public State
{
public:
	PlayState(PlayerData _playerData, BoardData _boardData, int _winCond, int _numPlayers);
	void OnEntry(Application * _app) override;
	void OnExit() override;

	void Draw(sf::RenderWindow & _window) override;
	void Update(Application * _app, sf::Time _elapTime) override;
	void HandleEvent(sf::Event _event, sf::RenderWindow & _window) override;

	void Pause() override;
	void Unpause() override;

private:
	//sf::Shader _shader;
	//sf::Sprite _test;
	Gameboard board;
	GameboardUI boardUI;
	GameLogic gameLogic;
	PlayerData playerData;
	AnimatedBackground background;
};