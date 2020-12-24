#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "State.h"
#include "TextureManager.h"
#include <vector>
#include "AnimatedBackground.h"

class State;

class Application
{
public:
	Application();
	~Application();
	bool IsRunning();
	void Update();
	void ChangeState(State* _state);
	void PushState(State* _state);
	void PopState();

	sf::RenderWindow& GetWindow() { return window; }
	void ChangeBackground() { background.IncrementBackground(); }
private:
	void HandleInput();

	sf::Clock clock;
	bool isRunning;
	sf::RenderWindow window;
	std::vector<State*> stackOfStates;
	AnimatedBackground background; //TODO: REMOVE THIS FROM APPLICATION AND MAKE SETTINGS
};

