#include "TileUI.h"

TileUI::TileUI(Point _loc, sf::FloatRect _spriteSize)
	: UIComponent(_spriteSize), point(_loc)
{
	sprite.setPosition(_spriteSize.left, _spriteSize.top);
	sprite.setSize(sf::Vector2f(_spriteSize.width, _spriteSize.height));
	sprite.setOutlineThickness(-3);
	sprite.setOutlineColor(sf::Color::Cyan);
}

void TileUI::Draw(sf::RenderWindow & _window)
{
	_window.draw(sprite);
}

void TileUI::Update(sf::Time _gameTime)
{
}

void TileUI::UpdateSpriteColor(sf::Color _color)
{
	sprite.setFillColor(_color);
}

