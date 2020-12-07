#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerEnum.h"

class PlayerData
{
public:
	PlayerData();
	
	//TODO Load from file to save player preferences?

	void SetPlayerColor(sf::Color _color, PlayerEnum _player);
	sf::Color GetPlayerColor(PlayerEnum _player);
private:
	sf::Color P1_Color = sf::Color::Red;
	sf::Color P2_Color = sf::Color::Blue;
	sf::Color P3_Color = sf::Color::Green;
	sf::Color P4_Color = sf::Color::Yellow;
};

