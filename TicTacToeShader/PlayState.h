#pragma once
#include "State.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"




class PlayState : public State
{
public:
	PlayState();
	void OnEntry(Application * _app) override;
	void OnExit() override;

	void Draw(sf::RenderWindow & _window) override;
	void Update(Application * _app, sf::Time _elapTime) override;
	void HandleEvent(sf::Event _event, sf::RenderWindow & _window) override;

	void Pause() override;
	void Unpause() override;

private:

};