#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

class AnimatedBackground
{
public:
	void Initialize();
	void Update(sf::Time _elapsedTime);
	void Draw(sf::RenderWindow& _window);

private:
	void swapAndRotateSprites();

	sf::Sprite currSprite;
	sf::Sprite nextSprite;
	sf::Time animTime = sf::milliseconds(2000);
	sf::Time elapTime;

};

