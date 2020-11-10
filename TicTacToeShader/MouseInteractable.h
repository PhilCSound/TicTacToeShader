#pragma once
#include "SFML/Graphics.hpp"

class MouseInteractable
{
public:
	MouseInteractable(float _x = 1, float _y = 1, float _w = 1, float _h = 1) 
		: bounds(_x, _y, _w, _h) {}
	bool ContainsPoint(const sf::Vector2f _loc) { return bounds.contains(_loc); }
	void SetBounds(const sf::FloatRect _bounds) { bounds = _bounds; }
	void ChangePosition(const sf::Vector2f _pos);
	void ChangeSize(const sf::Vector2f _size);
	void Click(const sf::Vector2f _loc);
protected:
	sf::FloatRect bounds;
};

