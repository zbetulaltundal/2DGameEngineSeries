#pragma once

#include<map>
#include<memory>
#include<string>

#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Font.hpp>

namespace _engine {
	class AssetManager
	{
		// a map consists of key and value pairs 
		// keys are sorted
		std::map<std::string, sf::Texture>  textures;
		std::map<std::string, sf::Font>  fonts;

	public:
		AssetManager();
		~AssetManager();

		sf::Texture* LoadTexture(std::string name, std::string filePath);
		sf::Texture &GetTexture(std::string name);
		sf::Texture *GetRef2Texture(std::string name);

		void LoadFont(std::string name, std::string filePath);
		sf::Font &GetFont(std::string name);
	};
}