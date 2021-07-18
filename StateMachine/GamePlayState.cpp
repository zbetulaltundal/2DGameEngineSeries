#include "GamePlayState.h"
#include "Character.h"
#include "Definitions.h"

_engine::GamePlayState::GamePlayState(GameDataRef gameData)
	:gameData(gameData), character(gameData)
{
}

_engine::GamePlayState::~GamePlayState()
{
}

void _engine::GamePlayState::Init()
{
	gameData->assets.LoadTexture("Character texture", GAME_PLAY_STATE_PATH2PLAYERTEXTURE);
	character.setTexture(gameData->assets.GetRef2Texture("Character texture"));
	deltaTime = 0.0f;
}

void _engine::GamePlayState::HandleInput()
{
	sf::Event evnt;
	while (gameData->window.pollEvent(evnt)) {
		switch (evnt.type)
		{
		// if close button is pressed close the window
		case sf::Event::Closed:
			gameData->window.close();
			break;
		default:
			break;
		}
	}
}

void _engine::GamePlayState::Update(float deltaTime)
{
	character.Update(deltaTime);
}

void _engine::GamePlayState::Draw()
{
	gameData->window.clear(sf::Color::Black);
	character.Draw();
	gameData->window.display();
}

void _engine::GamePlayState::Pause()
{
}

void _engine::GamePlayState::Start()
{
}
