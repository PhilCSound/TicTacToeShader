#include "PlayState.h"

PlayState::PlayState(PlayerData _playerData, BoardData _boardData, int _winCond, int _numPlayers)
	: board(_boardData), playerData(_playerData ), boardUI(sf::FloatRect(80, 60, 640, 480)),
		winCondition(_winCond), numberOfPlayers(_numPlayers)
{
	boardUI.CreateUI(_boardData);
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
}

void PlayState::OnExit()
{
}

void PlayState::Draw(sf::RenderWindow & _window)
{
	//_test.setPosition(200, 200); //Part of shader tests
	//_window.draw(_test, &_shader); //Was part of shadertest.
	boardUI.Draw(_window);
}

void PlayState::Update(Application * _app, sf::Time _elapTime)
{
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
				Point _loc = boardUI.GetTileOnClick(_pos);
				if (board.IsValidMove(_loc, currentPlayer))
				{
					board.MakeMove(_loc, currentPlayer);
					boardUI.UpdateTileUIColor(_loc, playerData.GetPlayerColor(currentPlayer));
					if (board.CheckForWin(_loc, currentPlayer, winCondition) || board.CheckForTie())
						winCondition = 100; //TODO.
					NextTurn();
				}
			}
		}
}

void PlayState::Pause()
{
}

void PlayState::Unpause()
{
}

void PlayState::NextTurn()
{
	if (currentPlayer + 1 > numberOfPlayers)
		currentPlayer = PLAYER1;
	else
		currentPlayer = static_cast<PlayerEnum>(currentPlayer + 1);
	int x = 1;
}
