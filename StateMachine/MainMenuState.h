#pragma once

#include<SFML/Graphics.hpp>
#include"State.h"
#include"Game.h"

namespace _engine {
	class MainMenuState :public State
	{
		GameDataRef gameData;
		sf::Sprite background;
		sf::Sprite playButton;
		sf::Sprite title;
	public:
		MainMenuState(GameDataRef gameData);

		void Init();
		void HandleInput();
		void Update(float deltaTime);
		void Draw();
	};

};

