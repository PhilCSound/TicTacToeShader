#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Application.h"
#include "MainMenuState.h"

int main()
{
	Application app;
	BoardData _d(5,6);
	_d.FloodMapWithTiles();
	//TODO Launcher State
	State* playState = new MainMenuState();



	app.PushState(playState);

	while (app.IsRunning())
	{
		app.Update();
	}

	return 0;
}