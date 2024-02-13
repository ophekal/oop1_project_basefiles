#pragma once
#include <SFML/Graphics.hpp>


Class MovingObjects:: public GameObjects
{
public:
	using GameObjects::GameObjects;
	virtual ~MovingObject() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void movement() = 0;

private:
	sf::Vector2f m_oldPosition;
	sf::Vector2f m_nextPosition;
	float objectSpeed;				//each object will update according to the speed we will set it to
};