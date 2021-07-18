#include "Game.h"
#include"SplashState.h"

// constructor(s)
_engine::Game::Game(int width, int height, std::string title)
{
	thisGameData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	//TODO
	// ADD FIRST STATE
	thisGameData->states.PushState( StateRef(new SplashState(this->thisGameData)), true);
	this->Run();
}

// destructor(s)
_engine::Game::~Game()
{
}

// methods
void _engine::Game::Run(){

	// delta time
	float newTime, frameTime, interpolation;
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (IsRunning())
	{
		thisGameData->states.ProcessStateChange();
		// calculate delta time
		newTime = this->clock.getElapsedTime().asSeconds();
		// Update the game
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;
		while (accumulator >= dt) {
			// Update the current state
			thisGameData->states.GetCurrent()->HandleInput();
			thisGameData->states.GetCurrent()->Update(accumulator);

			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		Render(interpolation);
	}
}

void _engine::Game::Render(float interpolation) {

	thisGameData->states.GetCurrent()->Draw();
}

bool _engine::Game::IsRunning()
{
	return thisGameData->window.isOpen();
}

