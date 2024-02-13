#pragma once
#include <SFML/Graphics.hpp>


class Cat:: public MovingObjects
{
public:
	using MovingObjects::MovingObjects;
	virtual ~Cat() = default;
	virtual void draw(sf::RenderWindow& window) const;
	virtual void movement()=0;

private:
	sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in handelresources
};