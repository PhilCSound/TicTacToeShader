#include "GameLogic.h"

GameLogic::GameLogic(Gameboard & _board, PlayerData* _pData, unsigned int _winCond, unsigned int _numPlayers)
	: board(_board), playerData(_pData)
{
	if (_winCond > 5 || _winCond < 3)
		winCondition = 3;
	else
		winCondition = _winCond;
	//Check if NumPlayers is within bounds
	if (_numPlayers > 4 || _winCond < 2)
		numPlayers = 2;
	else
		numPlayers = _numPlayers;
}

void GameLogic::MakeMove(Tile *_tile)
{
	PlayerEnum _tilePlayer = _tile->GetPlayer();
	Point _tileLoc(_tile->GetX(), _tile->GetY());
	if (_tilePlayer == NO_PLAYER)
	{
		_tile->ChangePlayer(currentPlayer);
 		if (CheckForWin(_tileLoc, currentPlayer))
			return;
		else
			NextTurn();
	}
}

void GameLogic::NextTurn()
{
	if (currentPlayer + 1 > numPlayers)
		currentPlayer = PLAYER1;
	else
		currentPlayer = static_cast<PlayerEnum>(currentPlayer + 1);
	int x = 1;
}

bool GameLogic::CheckForWin(Point _orgin, PlayerEnum _player)
{
	int Vertical = MatchingTilesInDirection(_orgin, Point::North, _player);
	Vertical += MatchingTilesInDirection(_orgin, Point::South, _player);
	int Horizontal = MatchingTilesInDirection(_orgin, Point::East, _player);
	Horizontal += MatchingTilesInDirection(_orgin, Point::West, _player);
	int RightDiagonal = MatchingTilesInDirection(_orgin, Point::NorthEast, _player);
	RightDiagonal += MatchingTilesInDirection(_orgin, Point::SouthWest, _player);
	int LeftDiagonal = MatchingTilesInDirection(_orgin, Point::NorthWest, _player);
	RightDiagonal += MatchingTilesInDirection(_orgin, Point::SouthEast, _player);

	if (Vertical >= winCondition || Horizontal >= winCondition
		|| RightDiagonal >= winCondition || LeftDiagonal >= winCondition)
	{
		win = true;
		return true;
	}
	return false;

}

int GameLogic::MatchingTilesInDirection(Point _orgin, Point _direction, PlayerEnum _player)
{
	int counter = 0;
	Point _loc = _orgin + _direction;
	while (board.DoesPointExist(_loc))
	{
		//Check to see if it same player, if not. Return.
		Tile* _tile = board.GetTileAtPoint(_loc);
		if (_tile->GetPlayer() != _player)
			return counter;
		//Add one the counter and keep checking
		counter++;
		_loc += _direction;
	}
	return counter;
}
