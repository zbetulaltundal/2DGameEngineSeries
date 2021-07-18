#pragma once
#include<SFML\Graphics.hpp>

class Character_Animation
{

	//private variables
private:
	sf::Vector2u imageCount;  // number of elements in each row and number of rows in the spreatsheet  
	sf::Vector2u  currentImage; // never gonna be less than zero, 
	//if less than zero you try to reach an img that is not available


	//switching between images
	float totalTime; // how long animation gonna take in total
	float switchTime; // amount of time that takes before we want to switch to next img

// public member functions
public:
	// the reason that we use a pointer to store texture is we only care about it's size
	Character_Animation();
	~Character_Animation();

	/* deltaTime
		provides robustness
		provides animations run at the same time on all computers
		in high computers have high fps, runs games better. so it is small
		in lower computers run it slower. delta time will be higher
	*/
	void Update(int row, float deltaTime, bool);
	void setuvRect(sf::IntRect* uvRect);

	// public attributes
public:
	sf::IntRect uvRect;
};

