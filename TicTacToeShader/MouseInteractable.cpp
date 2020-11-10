#include "MouseInteractable.h"

void MouseInteractable::ChangePosition(const sf::Vector2f _pos)
{
	bounds = sf::FloatRect(_pos, sf::Vector2f(bounds.width, bounds.height));
}

void MouseInteractable::ChangeSize(const sf::Vector2f _size)
{
	bounds = sf::FloatRect(sf::Vector2f(bounds.left, bounds.height), _size);
}

void MouseInteractable::Click(const sf::Vector2f _loc)
{
}
