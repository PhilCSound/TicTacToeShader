#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Application.h"
#include "PlayState.h"
#include "PlayerData.h"
#include "BoardData.h"


int main()
{
	Application app;
	BoardData _d(5,6);
	_d.FloodMapWithTiles();
	//TODO Launcher State
	State* playState = new PlayState(PlayerData(),_d,3,2);



	app.PushState(playState);

	while (app.IsRunning())
	{
		app.Update();
	}

	return 0;
}