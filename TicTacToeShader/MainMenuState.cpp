#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

void MainMenuState::OnEntry(Application * _app)
{
	ui.setTarget(_app->GetWindow());
	ui.loadWidgetsFromFile("Assets/UI/mainmenu.txt");
	
	//Setup button functions
	tgui::Widget::Ptr _widget;
	_widget = ui.get("BackgroundChangeButton");
	if (_widget)
		_widget->connect("pressed", [=]() { _app->ChangeBackground(); });

	_widget = ui.get("PlayButton");
	if (_widget)
		_widget->connect("pressed", [=]() { DisplayPlayPanel(); });
	
	_widget = ui.get("BackToMainMenu");
	if (_widget)
		_widget->connect("pressed", [=]() { ReturnToMainMenu(); });
}

void MainMenuState::OnExit()
{
}

void MainMenuState::Draw(sf::RenderWindow & _window)
{
	ui.draw();
}

void MainMenuState::Update(Application * _app, sf::Time _elapTime)
{
}

void MainMenuState::HandleEvent(sf::Event _event, sf::RenderWindow & _window)
{
	ui.handleEvent(_event);
}

void MainMenuState::Pause()
{
}

void MainMenuState::Unpause()
{
}

void MainMenuState::DisplayPlayPanel()
{
	ui.get("PlayPanel")->showWithEffect(tgui::ShowAnimationType::Scale, sf::milliseconds(100));
	ui.get("MainMenuGroup")->setVisible(false);
}

void MainMenuState::ReturnToMainMenu()
{
	ui.get("MainMenuGroup")->showWithEffect(tgui::ShowAnimationType::SlideFromLeft, sf::milliseconds(200));
	ui.get("PlayPanel")->hideWithEffect(tgui::ShowAnimationType::SlideToRight, sf::milliseconds(200));
}
