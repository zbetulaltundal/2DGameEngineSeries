#include "GameState.h"

_engine::GameState::GameState(GameDataRef gameData)
	:gameData(gameData)
{
}

void _engine::GameState::Init()
{
	gameData->assets.LoadTexture("Character sprite", );
}

void _engine::GameState::HandleInput()
{
}

void _engine::GameState::Update(float deltaTime)
{
}

void _engine::GameState::Draw()
{
}
