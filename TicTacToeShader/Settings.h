#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerEnum.h"

namespace Settings {

	//Screen Settings
	static sf::Vector2u WINSIZE = sf::Vector2u(800, 600);
	//Board Settings
	static int BETWEEN_TILE_PADDING = 12;

	//TODO: Starting to think a player class is more appropriate..
	static sf::Color GetPlayerColor(PlayerEnum &_player)
	{
		switch (_player)
		{
		default:
			return sf::Color::White;
			break;

		case PLAYER1:
			return sf::Color::Red;
			break;

		case PLAYER2:
			return sf::Color::Green;
			break;

		case PLAYER3:
			return sf::Color::Green;
			break;

		case PLAYER4:
			return sf::Color::Magenta;
			break;
		}
	}
}
