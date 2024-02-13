#pragma once
#include <SFML/Graphics.hpp>


class Mouse:: public MovingObjects
{
public:
	using MovingObjects::MovingObjects;
	virtual ~Mouse() = default;
	virtual void draw(sf::RenderWindow& window);
	virtual void movement();

private:
	int m_lives;
	int m_keys;
	sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in hndelresources
};