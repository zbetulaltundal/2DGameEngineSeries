#include<sstream>
#include<iostream>

#include "SplashState.h"
#include "Definitions.h"
#include "MainMenuState.h"

// constructor(s)
_engine::SplashState::SplashState(GameDataRef gameData)
	: gameData(gameData) {
}

// methods
void _engine::SplashState::Init()
{
	gameData->assets.LoadTexture("Splash State Background", SPLASH_STATE_PATH2BACKGROUND);
	background.setTexture(gameData->assets.GetTexture("Splash State Background"));
}

void _engine::SplashState::HandleInput()
{
	// event handling code
	sf::Event ev;

	while (gameData->window.pollEvent(ev)) {
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

void _engine::SplashState::Update(float deltaTime)
{
	if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {

		// SWITCH TO THE MAIN MENU
		gameData->states.PushState(StateRef(new MainMenuState(gameData)), true);
	}
}

void _engine::SplashState::Draw()
{
	gameData->window.clear(sf::Color::Black);
	gameData->window.draw(background);
	gameData->window.display();
}
