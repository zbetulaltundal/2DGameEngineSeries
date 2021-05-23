#include "Game.h"
#include"SplashState.h"

// constructor(s)
_engine::Game::Game(int width, int height, std::string title)
{
	thisGameData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	//TODO
	// ADD FIRST STATE
	thisGameData->states.PushState( StateRef(new SplashState(this->thisGameData)), true);
	timeSinceLastFrame = 0.0f;
}

// destructor(s)
_engine::Game::~Game()
{
}

void _engine::Game::Update()
{
	// puts the time ctr back to zero
	timeSinceLastFrame = clock.restart().asSeconds(); // deltaTime

	thisGameData->states.ProcessStateChange();
	thisGameData->states.GetCurrent()->HandleInput();
	// update cycle
	while (timeSinceLastFrame > timePerFrame) {

		// update will only happen if time since the last update is more than 1/60 seconds 
		timeSinceLastFrame -= timePerFrame;

		//// TODO
		thisGameData->states.GetCurrent()->Update(timeSinceLastFrame);
	}
}

void _engine::Game::Render() {

	std::cout << "Rendering" << std::endl;
	thisGameData->states.GetCurrent()->Draw();
}

bool _engine::Game::IsRunning()
{
	return thisGameData->window.isOpen();
}

