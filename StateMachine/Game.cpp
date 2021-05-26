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
	float timeSinceLastFrame = 0.0f;
	sf::Clock clock;

	while (IsRunning())
	{
		// calculate delta time
		timeSinceLastFrame += clock.restart().asSeconds(); 

		// Update the game
		Update(timeSinceLastFrame);
	}
}

void _engine::Game::Update(float timeSinceLastFrame)
{
	// update cycle
	if (timeSinceLastFrame > timePerFrame) 
	{	// time per frame = switch time

		timeSinceLastFrame -= timePerFrame;
		// Update the current state
		thisGameData->states.ProcessStateChange();
		thisGameData->states.GetCurrent()->HandleInput();
		thisGameData->states.GetCurrent()->Update(timePerFrame);

		//Render
		Render();
	}
}

void _engine::Game::Render() {

	thisGameData->states.GetCurrent()->Draw();
}

bool _engine::Game::IsRunning()
{
	return thisGameData->window.isOpen();
}

