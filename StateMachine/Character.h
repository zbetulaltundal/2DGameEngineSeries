#pragma once

#include<SFML/Graphics.hpp>

#include"State.h"
#include"Game.h"
#include"Character_Animation.h"

namespace _engine {

	class Character
	{
		// private attributes
		GameDataRef gameData;
		Character_Animation animation;
		sf::Clock clock;
		sf::RectangleShape body;
		sf::Texture characterTexture;
		unsigned int row;
		float playerScale;
		float moveSpeed;
		bool canMoveUp, canMoveDown, canMoveLeft, canMoveRight;
	public:

		// constructors & destructors
		Character(GameDataRef gameData);
		~Character();

		// methods
		void Move(float deltaTime);
		void Update(float deltaTime);
		void Draw();
		void setTexture(const sf::Texture* characterTexture);
	};
};