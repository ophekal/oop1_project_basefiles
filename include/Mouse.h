#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"


class Mouse: public MovingObjects
{
public:
	using MovingObjects::MovingObjects;
	virtual ~Mouse() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void movement();

protected:
	int m_lives;
	int m_keys;
	sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in hndelresources
};