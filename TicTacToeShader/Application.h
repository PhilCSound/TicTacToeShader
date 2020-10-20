#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "State.h"
#include "TextureManager.h"
#include <vector>
#include "Gameboard.h"

class State;
class GameBoard;

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

private:
	void HandleInput();

	sf::Clock clock;
	bool isRunning;
	sf::RenderWindow window;
	std::vector<State*> stackOfStates;
};

