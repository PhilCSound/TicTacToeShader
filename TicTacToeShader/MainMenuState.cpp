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
		_widget->connect("pressed", [=]() { DisplayPanel("PlayPanel"); });
	
	_widget = ui.get("BackToMainMenu");
	if (_widget)
		_widget->connect("pressed", [=]() { ReturnToMainMenu(); });
	//
	_widget = ui.get("BeginButton");
	if (_widget)
		_widget->connect("pressed", [=]() { BeginGame(); _app->ChangeState(new PlayState(playerData, boardData)); });

	_widget = ui.get("CreditsButon");
	if (_widget)
		_widget->connect("pressed", [=]() { DisplayPanel("CreditsPanel"); });

	_widget = ui.get("ExitCreditButton");
	if (_widget)
		_widget->connect("pressed", [=]() { ReturnToMainMenu(); });

	tgui::SpinButton::Ptr _button = ui.get<tgui::SpinButton>("MapWidthButton");
	if (_button)
		_button->connect("ValueChanged", [=]() { ChangeLabel("MapWidthText", _button->getValue()); });

	_button = ui.get<tgui::SpinButton>("MapHeightButton");
	if (_button)
		_button->connect("ValueChanged", [=]() { ChangeLabel("MapHeightText", _button->getValue()); });

	_button = ui.get<tgui::SpinButton>("WinConButton");
	if (_button)
		_button->connect("ValueChanged", [=]() { ChangeLabel("WinConLabel", _button->getValue()); });

	_button = ui.get<tgui::SpinButton>("PlayerNumButton");
	if (_button)
		_button->connect("ValueChanged", [=]() { ChangeLabel("PlayerNumLabel", _button->getValue()); });
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

void MainMenuState::DisplayPanel(std::string _panel)
{
	ui.get(_panel)->showWithEffect(tgui::ShowAnimationType::Scale, sf::milliseconds(100));
	ui.get("MainMenuGroup")->setVisible(false);
}

void MainMenuState::ReturnToMainMenu()
{
	ui.get("MainMenuGroup")->showWithEffect(tgui::ShowAnimationType::SlideFromLeft, sf::milliseconds(200));
	tgui::Widget::Ptr _widget = ui.get("PlayPanel");
	if (_widget && _widget->isVisible())
		_widget->hideWithEffect(tgui::ShowAnimationType::SlideToRight, sf::milliseconds(200));
	_widget = ui.get("CreditsPanel");
	if (_widget && _widget->isVisible())
		_widget->hideWithEffect(tgui::ShowAnimationType::SlideToBottom, sf::milliseconds(200));
}

void MainMenuState::BeginGame()
{
	unsigned int _boardWidth = 3, _boardHeight = 3, _numPlayers = 2, _winCondition = 3;
	SetButtonValues("MapWidthButton", _boardWidth);
	SetButtonValues("MapHeightButton", _boardHeight);
	SetButtonValues("NumPlayerButton", _numPlayers);
	SetButtonValues("WinConButton", _winCondition);
	boardData = BoardData(_boardWidth, _boardHeight);
}

void MainMenuState::SetButtonValues(std::string _buttonName, unsigned int& _value)
{
	tgui::SpinButton::Ptr _button = ui.get<tgui::SpinButton>(_buttonName);
	if (_button) 
	{
		_value = static_cast<unsigned int>(_button->getValue());
	}
}

void MainMenuState::ChangeLabel(std::string _labelName, float _value)
{
	//TODO FORMAT
	tgui::Label::Ptr _label = ui.get<tgui::Label>(_labelName);
	if (_label)
		_label->setText(static_cast<unsigned int>(_value));
}
