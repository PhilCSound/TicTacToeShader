#pragma once
#include "State.h"
#include "TextureManager.h"
#include "Gameboard.h"
#include "AnimatedBackground.h"

class PlayState : public State
{
	void OnEntry(Application * _app) override;
	void OnExit() override;

	void Draw(sf::RenderWindow & _window) override;
	void Update(Application * _app, sf::Time _elapTime) override;
	void HandleEvent(sf::Event _event, sf::RenderWindow & _window) override;

	void Pause() override;
	void Unpause() override;

private:
	//sf::Shader _shader;
	//sf::Sprite _test;
	Gameboard board;
	AnimatedBackground background;
};