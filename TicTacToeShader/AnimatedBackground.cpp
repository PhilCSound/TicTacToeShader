#include "AnimatedBackground.h"

void AnimatedBackground::Initialize()
{
	//TODO VIDEO SETTINGS
	sf::Texture& _texture = TextureManager::getInstance()->GetTexture("background");
	currSprite.setTexture(_texture);
	//Scale it to window size
	sf::Vector2f _winSize = sf::Vector2f(800, 600);
	sf::Vector2f _sprSize = sf::Vector2f(_texture.getSize());
	currSprite.setScale(sf::Vector2f((_winSize.x / _sprSize.x), (_winSize.y / _sprSize.y)));
	//Set origin of sprite for rotation, and adjust draw position to stay in center of screen.
	currSprite.setOrigin(sf::Vector2f(_sprSize.x / 2, _sprSize.y / 2));
	currSprite.setPosition(sf::Vector2f(_winSize.x / 2, _winSize.y / 2));
	//Make next same as current sprite but rotate it.
	nextSprite = currSprite;
	nextSprite.rotate(90.0f);
	nextSprite.setColor(sf::Color(255,255,255,0));
	//Flip Sprite scale x and y to accomdate for screen size
	nextSprite.setScale(nextSprite.getScale().y, nextSprite.getScale().x);
}

void AnimatedBackground::Update(sf::Time _elapsedTime)
{
	elapTime += _elapsedTime;
	if (elapTime >= animTime)
	{
		elapTime = elapTime.Zero;
		swapAndRotateSprites();
	}
	else
	{
		float _tScale = elapTime / animTime;
		int _transparancy = _tScale * 255;
		currSprite.setColor(sf::Color(255, 255, 255, 255 - _transparancy));
		nextSprite.setColor(sf::Color(255, 255, 255, _transparancy));
	}
}

void AnimatedBackground::Draw(sf::RenderWindow& _window)
{
	_window.draw(currSprite);
	_window.draw(nextSprite);
}

void AnimatedBackground::swapAndRotateSprites()
{
	nextSprite.setColor(sf::Color(255, 255, 255, 255));
	currSprite = nextSprite;
	nextSprite.rotate(90.0f);
	nextSprite.setColor(sf::Color(255, 255, 255, 0));
	nextSprite.setScale(nextSprite.getScale().y, nextSprite.getScale().x);
}
