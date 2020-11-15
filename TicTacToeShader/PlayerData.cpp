#include "PlayerData.h"

PlayerData::PlayerData()
{
}

void PlayerData::SetPlayerColor(sf::Color _color, PlayerEnum _player)
{
	switch (_player)
	{
	default:
		return;
	case PLAYER1:
		P1_Color = _color;
		return;
	case PLAYER2:
		P2_Color = _color;
		return;
	case PLAYER3:
		P3_Color = _color;
		return;
	case PLAYER4:
		P4_Color = _color;
		return;
	}
}

const sf::Color PlayerData::GetPlayerColor(PlayerEnum _player)
{
		switch (_player)
		{
		default:
			return sf::Color::White;
		case PLAYER1:
			return P1_Color;
		case PLAYER2:
			return P2_Color;
		case PLAYER3:
			return P3_Color;
		case PLAYER4:
			return P4_Color;
		}
}
