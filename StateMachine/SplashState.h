#pragma once

#include<SFML/Graphics.hpp>
#include"State.h"
#include"Game.h"

namespace _engine {

	class SplashState :public State
	{
		// private attributes
		GameDataRef gameData;
		sf::Clock clock;
		sf::Sprite background;
	public:
		
		// constructors & destructors
		SplashState(GameDataRef gameData); 
		~SplashState();

		// methods
		void Init();
		void HandleInput();
		void Update(float deltaTime);
		void Draw();
	};
};