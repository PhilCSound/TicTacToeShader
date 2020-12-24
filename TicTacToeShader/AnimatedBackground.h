#pragma once
#include <vector>
#include <string>
#include "SFML/Graphics.hpp"
#include "TextureManager.h"

class AnimatedBackground
{
public:
	void Initialize();
	void Update(sf::Time _elapsedTime);
	void Draw(sf::RenderWindow& _window);

	void IncrementBackground();
	void DecrementBackground();

private:
	void updateSpriteTexture();
	void scaleBackground();

	sf::Sprite currSprite;
	sf::Time animTime = sf::milliseconds(16000);
	sf::Time elapTime;
	std::vector<std::string> backgrounds;
	std::vector<std::string>::iterator currentTex;
};

