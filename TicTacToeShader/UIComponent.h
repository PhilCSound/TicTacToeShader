#pragma once
#include "SFML/Graphics.hpp"
#include <functional>

class UIComponent
{
public:
	UIComponent(sf::FloatRect _clickBox, bool _blocking = true) 
		: clickBox(_clickBox), blocking(_blocking) {};

	bool ContainsPosition(sf::Vector2f _pos) { return clickBox.contains(_pos); }
	virtual void Draw(sf::RenderWindow & _window) {};
	virtual void OnClick(sf::Vector2f _pos) {};
	virtual void OnHover(sf::Vector2f _pos) {};
	virtual void Update(sf::Time _gameTime) {};
	bool isBlocking() { return blocking; }
	bool SetBlocking(bool _b) { blocking = _b; }

protected:
	sf::FloatRect clickBox;
	bool blocking = true;
};