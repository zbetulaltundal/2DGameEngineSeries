#include "Character_Animation.h"
#include "Definitions.h"
#include<iostream>

Character_Animation::Character_Animation()
{
	totalTime = 0.0f;

	// since we will start the animation with the first image, sett curr image to zero
	currentImage.x = 0;

	switchTime = 0.5f;
}

Character_Animation::~Character_Animation()
{
}

void Character_Animation::Update(int row, float deltaTime, bool isMoving)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (isMoving) {
		if (totalTime >= switchTime) {
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
			}
		}
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
	}
	else 
	{
		currentImage.y = 3;
		currentImage.x = 0;
		uvRect.left = 0;
		uvRect.top = currentImage.y * uvRect.height;
	}
}

void Character_Animation::setuvRect(sf::IntRect* uvRect)
{
	this->uvRect = *uvRect;
}

