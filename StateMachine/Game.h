#pragma once

#include<SFML/Graphics.hpp>

#include<memory>
#include<string>

#include"StateManager.h"
#include"AssetManager.h"
#include"InputManager.h"

namespace _engine {

	struct GameData {
		StateManager states;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	// GameDataRef is a reference to all items that form our application
	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
		const float timePerFrame = 1.0f / 60.0f; // switchTime
		GameDataRef thisGameData = std::make_shared<GameData>();

	public:
		Game(int width, int height, std::string title);
		~Game();

		// methods
		void Run();
		void Update(float timeSinceLastFrame);
		void Render();

		// Getters
		bool IsRunning();
	};
};