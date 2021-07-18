#pragma once

#include<SFML/Graphics.hpp>
#include"State.h"
#include"Game.h"

namespace _engine {
	class GameState :public State
	{
		GameDataRef gameData;
		sf::Sprite background;
		sf::Sprite character;
		sf::Sprite wall;
	public:
		GameState(GameDataRef gameData);

		void Init();
		void HandleInput();
		void Update(float deltaTime);
		void Draw();
	};
};

