#include "stdafx.h"
#include "PlayerObject.h"
#include "Game.h"

PlayerObject::PlayerObject()
{
	// Since these will never change, load them here
	Load("img/object.png");
	assert(IsLoaded()); // Can't return false in constructor

	CenterOrigo();

	// Inherited
	_velocityX = 0.0f;
	_velocityY = 0.0f;
	_maxVelocity = 500.0f;

	_movedLeft = false;
	_movedRight = false;
	_movedUp = false;
	_movedDown = false;
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

void PlayerObject::Update(float elapsedTime)
{
	float velocityInc = 10.0f; // Pixels

	// Use polling instead of event
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_velocityX -= velocityInc;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_velocityX += velocityInc;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_velocityY -= velocityInc;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_velocityY += velocityInc;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		_velocityX = 0.0f;
		_velocityY = 0.0f;
	}

	// Protected inherited members of base class
	LimitVelocity();
	WallBounce();
	HandleMovingCollisions();
	MoveSprite(elapsedTime);
}