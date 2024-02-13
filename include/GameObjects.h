#pragma once
#include <SFML/Graphics.hpp>

Class GameObject
{
public:
	GameObject(sf::Vector2f position, sf::Vector2f size);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void collisionHandling() = 0;

private:
	sf::RectangleShape m_object;
};