#include "AssetManager.h"
#include<iostream>

// constructors && destructors
_engine::AssetManager::AssetManager()
{
}

_engine::AssetManager::~AssetManager()
{
}

void _engine::AssetManager::LoadTexture(std::string name, std::string filePath)
{

	sf::Texture texture;
	if (!texture.loadFromFile(filePath)) {
		std::cerr << "Could not load the specified texture" << std::endl;
		return;
	}

	// added to map w given name
	textures[name] = texture;
}

sf::Texture & _engine::AssetManager::GetTexture(std::string name)
{
	return textures.at(name);
}

void _engine::AssetManager::LoadFont(std::string name, std::string filePath)
{
	sf::Font font;
	if (!font.loadFromFile(filePath)) {
		std::cerr << "Could not load the specified font" << std::endl;
		return;
	}

	// added to map w given name
	fonts[name] = font;
}

sf::Font & _engine::AssetManager::GetFont(std::string name)
{
	return fonts.at(name);
}
