#pragma once
#include "PlayerData.h"
#include "Gameboard.h"


class GameLogic
{
public: 
	GameLogic(Gameboard& _board, PlayerData* _pData, unsigned int _winCondition =3, unsigned int _numPlayer=2);
	PlayerEnum GetCurrentPlayer() { return currentPlayer; }
	void MakeMove(Tile *_tile);
private:
	PlayerData* playerData;
	Gameboard board;
	unsigned int winCondition;
	unsigned int numPlayers;
	PlayerEnum currentPlayer = PLAYER1;

	void NextTurn();
	bool CheckForWin(Point _point, PlayerEnum _player);
	int MatchingTilesInDirection(Point _orgin, Point _direction, PlayerEnum _player);
	bool win = false;
};

