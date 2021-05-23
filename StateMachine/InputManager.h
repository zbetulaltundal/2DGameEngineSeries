#pragma once

#include<SFML/Graphics.hpp>

namespace _engine {

	class InputManager
	{
	public:
		// constructor & destructor
		InputManager() {};
		~InputManager() {};

		// methods
		bool IsSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window);
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};

};
