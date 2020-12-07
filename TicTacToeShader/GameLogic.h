#pragma once
#include "PlayerData.h"
#include "Point.h"
#include "SFML/Graphics.hpp"
#include "Gameboard.h"

class GameLogic
{
public: 
	GameLogic(Gameboard _board, PlayerData* _pData, unsigned int _winCond = 3, unsigned int _numPlayer=2);
	PlayerEnum GetCurrentPlayer() { return currentPlayer; }
	void MakeMove(PlayerEnum _player, Point _loc);
	Gameboard* GetGameBoard() { return &board; }
private:
	Gameboard board;
	PlayerData* playerData;
	unsigned int winCondition;
	unsigned int numPlayers;
	PlayerEnum currentPlayer = PLAYER1;

	void NextTurn();
	bool CheckForWin(Point _point, PlayerEnum _player);
	int MatchingTilesInDirection(Point _orgin, Point _direction, PlayerEnum _player);
	bool win = false;
};