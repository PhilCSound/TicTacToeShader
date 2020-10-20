#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Application.h"
#include "PlayState.h"

int main()
{
	Application app;

	State* playState = new PlayState();



	app.PushState(playState);

	while (app.IsRunning())
	{
		app.Update();
	}

	return 0;
}