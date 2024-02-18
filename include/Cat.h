#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"


class Cat: public MovingObjects
{
public:
	Cat(const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Cat() = default;
	virtual void draw(sf::RenderWindow& window) const;
	virtual void movement()=0;

private:
	sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in handelresources
};