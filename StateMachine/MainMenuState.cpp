#include "MainMenuState.h"
#include"Definitions.h"
#include<sstream>
#include<iostream>
#include"GamePlayState.h"

// constructor
_engine::MainMenuState::MainMenuState(GameDataRef gameData)
	:gameData(gameData)
{
}

// methods
void _engine::MainMenuState::Init()
{
	gameData->assets.LoadTexture("Main menu background", MAIN_MENU_STATE_PATH2BACKGROUND);
	gameData->assets.LoadTexture("Play button", MAIN_MENU_STATE_PATH2PLAYBUTTON);
	gameData->assets.LoadTexture("Main menu title", MAIN_MENU_STATE_PATH2TITLE);
	background.setTexture(gameData->assets.GetTexture("Main menu background"));
	playButton.setTexture(gameData->assets.GetTexture("Play button"));
	title.setTexture(gameData->assets.GetTexture("Main menu title"));

	playButton.setPosition((SCREEN_WIDTH / 2) - playButton.getGlobalBounds().width / 2, (SCREEN_HEIGHT / 2) - playButton.getGlobalBounds().height / 2);
	title.setPosition((SCREEN_WIDTH / 2) - title.getGlobalBounds().width / 2, title.getGlobalBounds().height * 0.1); // slightly above top
}

void _engine::MainMenuState::HandleInput()
{
	// event handling code
	sf::Event ev;

	while (gameData->window.pollEvent(ev)) {

		if (gameData->input.IsSpriteClicked(playButton, sf::Mouse::Left, gameData->window)) {

			gameData->states.PushState(StateRef(new GamePlayState(gameData)), true);
		}

		switch (ev.type) {
		case(sf::Event::Closed):
			std::cout << "Close" << std::endl;
			gameData->window.close();
			break;
		case(sf::Event::KeyPressed):
			if (ev.key.code == sf::Keyboard::Escape)
				std::cout << "Close" << std::endl;
			gameData->window.close();
			break;
		}
	}
}

void _engine::MainMenuState::Update(float deltaTime)
{
}

void _engine::MainMenuState::Draw()
{
	gameData->window.clear();
	gameData->window.draw(background);
	gameData->window.draw(title);
	gameData->window.draw(playButton);
	gameData->window.display();
}
