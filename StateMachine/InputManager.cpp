#include "InputManager.h"


namespace _engine {

	bool InputManager::IsSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow & window)
	{
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect tempRect(obj.getPosition().x, obj.getPosition().y, obj.getGlobalBounds().width, obj.getGlobalBounds().height);
			
			if (tempRect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}
		}

		return false;
	}
	
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow & window)
	{
		return sf::Mouse::getPosition(window);
	}
}
