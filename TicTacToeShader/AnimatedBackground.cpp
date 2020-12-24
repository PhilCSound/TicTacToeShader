#include "AnimatedBackground.h"

void AnimatedBackground::Initialize()
{
	TextureManager* _textMan = TextureManager::instance;
	_textMan->LoadFile("Assets/Backgrounds/1.png", "bg1");
	_textMan->LoadFile("Assets/Backgrounds/2.png", "bg2");
	_textMan->LoadFile("Assets/Backgrounds/3.png", "bg3");
	_textMan->LoadFile("Assets/Backgrounds/4.png", "bg4");
	_textMan->LoadFile("Assets/Backgrounds/5.png", "bg5");
	_textMan->LoadFile("Assets/Backgrounds/6.png", "bg6");
	_textMan->LoadFile("Assets/Backgrounds/7.png", "bg7");
	_textMan->LoadFile("Assets/Backgrounds/8.png", "bg8");

	//Textman
	backgrounds.push_back("bg1");
	backgrounds.push_back("bg2");
	backgrounds.push_back("bg3");
	backgrounds.push_back("bg4");
	backgrounds.push_back("bg5");
	backgrounds.push_back("bg6");
	backgrounds.push_back("bg7");
	backgrounds.push_back("bg8");

	//
	currentTex = backgrounds.begin();
	//TODO VIDEO SETTINGS
	sf::Texture& _texture = _textMan->GetTexture(backgrounds.front());
	currSprite.setTexture(_texture);
}

void AnimatedBackground::Update(sf::Time _elapsedTime)
{
	elapTime += _elapsedTime;
	if (elapTime >= animTime)
		elapTime = elapTime.Zero;
	float _t = elapTime / animTime;
	currSprite.setTextureRect(sf::IntRect(800 * _t, 0, 800, 600));
}

void AnimatedBackground::Draw(sf::RenderWindow& _window)
{
	_window.draw(currSprite);
}

void AnimatedBackground::IncrementBackground()
{
	//If iter is end, go to begin. Remember end() is empty placeholder so go back one.
	if (currentTex == --backgrounds.end())
		currentTex = backgrounds.begin();
	else
		++currentTex;

	updateSpriteTexture();
}

void AnimatedBackground::DecrementBackground()
{
	//If iter is begining, go to end. Remember end() is empty placeholder so go back one.
	if (currentTex == backgrounds.begin())
		currentTex = --backgrounds.end();
	else
		--currentTex;

	updateSpriteTexture();

}

void AnimatedBackground::updateSpriteTexture()
{
	TextureManager* _textMan = TextureManager::instance;
	currSprite.setTexture(_textMan->GetTexture(*currentTex));
	scaleBackground();
}

void AnimatedBackground::scaleBackground()
{
	//Scale it to window size. TODO: ADD RESOLUTIONS AND REMOVE CONSTANT MAGIC NUMBER 800,600
	//Also make this public and handle resize events maybe after the above TODO.
	sf::Vector2f _winSize = sf::Vector2f(800, 600);
	sf::Vector2f _sprSize = sf::Vector2f(currSprite.getTexture()->getSize());
	currSprite.setScale(sf::Vector2f((_winSize.x / _sprSize.x), (_winSize.y / _sprSize.y)));
}