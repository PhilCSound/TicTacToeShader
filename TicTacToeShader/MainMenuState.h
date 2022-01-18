#pragma once
#include "State.h"
#include "TGUI/TGUI.hpp"
#include "PlayState.h"
#include <string>

class MainMenuState : public State
{
public:
	MainMenuState();
	void OnEntry(Application * _app) override;
	void OnExit() override;

	void Draw(sf::RenderWindow & _window) override;
	void Update(Application * _app, sf::Time _elapTime) override;
	void HandleEvent(sf::Event _event, sf::RenderWindow & _window) override;

	void Pause() override;
	void Unpause() override;

private:
	tgui::Gui ui;
	PlayerData playerData;
	BoardData boardData;

	void DisplayPanel(std::string _panelName);
	void ReturnToMainMenu();
	void BeginGame();
	void ChangeLabel(std::string _labelName, float _value);
	void SetButtonValues(std::string _button, unsigned int& _value);

};

