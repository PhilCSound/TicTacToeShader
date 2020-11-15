#pragma once
#include "Application.h"

Application::Application()
{
	window.create(sf::VideoMode(800, 600, 32), "Tic Tac Toe");
	window.setFramerateLimit(60);
	isRunning = true;
	TextureManager* t = t->getInstance();	// Singleton instance.
}


Application::~Application()
{
}

bool Application::IsRunning()
{
	return isRunning;
}

void Application::Update()
{
	sf::Time elapsedTime = clock.restart();
	window.clear();
	HandleInput();
	stackOfStates.back()->Update(this, elapsedTime);
	stackOfStates.back()->Draw(window);
	window.display();
}

void Application::ChangeState(State * _state)
{
	if (!stackOfStates.empty()) {
		stackOfStates.back()->OnExit();
		stackOfStates.pop_back();
	}
	_state->OnEntry(this);
	stackOfStates.push_back(_state);

}

void Application::PushState(State * _state)
{
	if (!stackOfStates.empty())
		stackOfStates.back()->Pause();

	_state->OnEntry(this);
	stackOfStates.push_back(_state);
}

void Application::PopState()
{
	if (stackOfStates.empty()) {
		window.close();
	}

	stackOfStates.pop_back();
	stackOfStates.back()->Unpause();
}

void Application::HandleInput()
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
			case sf::Event::Closed:
				window.close();
				isRunning = false;
				return;

			case sf::Event::LostFocus:
				stackOfStates.back()->Pause();
				break;

			case sf::Event::GainedFocus:
				stackOfStates.back()->Unpause();
				break;

			case sf::Event::Resized:
				stackOfStates.back()->HandleEvent(_event, window);
				break;

			default:
				stackOfStates.back()->HandleEvent(_event, window);
				break;
		}
	}
}
