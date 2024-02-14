#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

class MovingObjects : public GameObjects
{
public:
	using GameObjects::GameObjects;
	virtual ~MovingObject() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void movement() = 0;
	virtual void collisionHandling(GameObjects& ) = 0;

protected:
	sf::Vector2f m_oldPosition;
	sf::Vector2f m_nextPosition;
	float objectSpeed;				//each object will update according to the speed we will set it to
	sf::Clock m_MovementTime;		//hold the previous time the object moved
};