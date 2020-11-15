#include "PlayState.h"

PlayState::PlayState(PlayerData _playerData, BoardData _boardData, int _winCond, int _numPlayers)
	: board(_boardData), playerData(_playerData ),gameLogic(board, &playerData, _winCond, _numPlayers),
	boardUI(sf::FloatRect(80, 60, 640, 480), _boardData, &playerData, &gameLogic)
{

}

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
	using namespace std::placeholders;
	//board
	background.Initialize(); 
	board.CreateUI(std::bind(&GameboardUI::CreateTileComponent, &boardUI, _1));
}

void PlayState::OnExit()
{
}

void PlayState::Draw(sf::RenderWindow & _window)
{
	background.Draw(_window);
	//_test.setPosition(200, 200); //Part of shader tests
	//_window.draw(_test, &_shader); //Was part of shadertest.
	boardUI.Draw(_window);
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
			if (boardUI.ContainsPosition(_pos))
			{
				boardUI.OnClick(_pos);
			}
		}
}

void PlayState::Pause()
{
}

void PlayState::Unpause()
{
}
