#include "PlayState.h"

void PlayState::OnEntry(Application * _app)
{
	//TODO move this singleton in main or application
	TextureManager* _textMan = TextureManager::instance;

	//Loading texures
	_textMan->LoadFile("background.PNG", "background");
	
	/*
	//Shader Related Tests.. Ignore
	_test.setTexture(_textMan->GetTexture("tile"));
	_shader.loadFromFile("color.frag", sf::Shader::Fragment);
	_shader.setUniform("iChannel1", sf::Shader::CurrentTexture);
	_shader.setUniform("iColor", sf::Glsl::Vec4(1,0,0,1));
	*/

	//board
	background.Initialize();
	board.CreateGameboard(sf::FloatRect(40, 80, 720, 440), 10, 10);
}

void PlayState::OnExit()
{
}

void PlayState::Draw(sf::RenderWindow & _window)
{
	background.Draw(_window);
	//_test.setPosition(200, 200); //Part of shader tests
	//_window.draw(_test, &_shader); //Was part of shadertest.
	board.Draw(_window);
}

void PlayState::Update(Application * _app, sf::Time _elapTime)
{
	background.Update(_elapTime);
}

void PlayState::HandleEvent(sf::Event _event, sf::RenderWindow & _window)
{

	//TODO Player logic and handling mouse.
	if (_event.type == sf::Event::MouseButtonReleased)
		if (_event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i _pixPos(_event.mouseButton.x, _event.mouseButton.y);
			sf::Vector2f _pos = _window.mapPixelToCoords(_pixPos);
			if (board.ContainsPoint(_pos))
				board.Click(_pos);
		}
}

void PlayState::Pause()
{
}

void PlayState::Unpause()
{
}
