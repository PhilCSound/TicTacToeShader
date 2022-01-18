#pragma once
#include "State.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "Gameboard.h"
#include "GameboardUI.h"
#include "PlayerData.h"
#include "BoardData.h"

class PlayState : public State
{
public:
	PlayState(PlayerData _playerData, BoardData _boardData, int _winCond=3, int _numPlayers=2);
	void OnEntry(Application * _app) override;
	void OnExit() override;

	void Draw(sf::RenderWindow & _window) override;
	void Update(Application * _app, sf::Time _elapTime) override;
	void HandleEvent(sf::Event _event, sf::RenderWindow & _window) override;

	void Pause() override;
	void Unpause() override;

private:
	Gameboard board;
	GameboardUI boardUI;
	PlayerData playerData;
	PlayerEnum currentPlayer = PLAYER1;
	int winCondition;
	int numberOfPlayers;

	void NextTurn();
};