#pragma once
#include "Application.h"

class Application;

class State {

public:
	virtual void OnEntry(Application * _app) = 0;
	virtual void OnExit() = 0;

	virtual void Draw(sf::RenderWindow & _window) = 0;
	virtual void Update(Application * _app, sf::Time _elapTime) = 0;
	virtual void HandleEvent(sf::Event _event) = 0;
	
	virtual void Pause() = 0;
	virtual void Unpause() = 0;
};