#include "Character.h"
#include"Definitions.h"
#include<iostream>

// constructor
_engine::Character::Character(GameDataRef gameData)
	:gameData(gameData) {
	row = 3;
	body.setSize(sf::Vector2f(90.0f, 90.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(0, 0);
	canMoveUp = true, canMoveDown = true, canMoveLeft = true, canMoveRight = true;
	moveSpeed = MAIN_CHARACTER_SPEED;
}

// destructor
_engine::Character::~Character()
{
}

// methods
void _engine::Character::Update(float deltaTime)
{
	Move(deltaTime);
}

void _engine::Character::Move(float deltaTime)
{
	bool isMoving = false;
	sf::Vector2f position(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (canMoveLeft)) {
		position.x -= (deltaTime * moveSpeed);
		isMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (canMoveRight)) {
		position.x += (deltaTime * moveSpeed);
		isMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (canMoveUp)) {
		position.y -= (deltaTime * moveSpeed);
		isMoving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (canMoveDown)) {
		position.y += (deltaTime * moveSpeed);
		isMoving = true;
	}

	if (position.x == 0) {
		row = 3;
	}
	else if (position.x < 0.0f) {
		row = 0;
	}
	else if (position.x > 0.0f) {
		row = 1;
	}

	if (position.y < 0.0f)
		row = 2;
	else if (position.y > 0.0f) {
		row = 3;
	}

	animation.Update(row, deltaTime, isMoving);
	//std::cout << "left " << animation.uvRect.left << "top"<< animation.uvRect.top << std::endl;
	body.setTextureRect(animation.uvRect);
	body.move(position);
}


void _engine::Character::Draw()
{
	gameData->window.draw(body);
}

void _engine::Character::setTexture(const sf::Texture* characterTexture)
{
	sf::IntRect uvRect;
	sf::Vector2u imageCount = MAIN_CHARACTER_SPREATSHEET_VECTOR;
	//calculating height and width of each tux
	uvRect.width = characterTexture->getSize().x / float(imageCount.x);
	uvRect.height = characterTexture->getSize().y / float(imageCount.y);
	animation.setuvRect(&uvRect);
	body.setTextureRect(uvRect);
	body.setTexture(characterTexture);
}
