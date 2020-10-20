#pragma once
#include "SFML/Graphics.hpp"

namespace Settings {

	//Screen Settings
	static sf::Vector2u WINSIZE = sf::Vector2u(800, 600);
	//Player Settings
	static sf::Color PLAYER1COLOR = sf::Color::Red;
	static sf::Color PLAYER2COLOR = sf::Color::Blue;
	static sf::Color PLAYER3COLOR = sf::Color::Green;
	static sf::Color PLAYER4COLOR = sf::Color::Yellow;
	//Board Settings
	static int BOARD_NORTH_PADDING = 80;
	static int BOARD_EAST_PADDING = 40;
	static int BOARD_SOUTH_PADDING = 80;
	static int BOARD_WEST_PADDING = 40;
	static int BETWEEN_TILE_PADDING = 12;
}