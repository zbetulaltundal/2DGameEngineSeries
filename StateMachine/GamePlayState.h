#pragma once

#include<SFML/Graphics/Sprite.hpp>

#include"Character.h"
#include"State.h"
#include"Game.h"

namespace _engine {
	class GamePlayState :public State
	{
		GameDataRef gameData;
		Character character;
		float deltaTime;
		sf::Clock clock;

	public:
		GamePlayState(GameDataRef gameData);
		~GamePlayState();

		void Init();
		void HandleInput();
		void Update(float deltaTime);
		void Draw();
		void Pause();
		void Start();
	};
};