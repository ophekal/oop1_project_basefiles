#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.h"


class SmartCat: public Cat
{
public:
	using Cat::Cat;
	virtual ~SmartCat() = default;
	virtual void movement(sf::Time deltaTime, sf::Vector2f tileSize);

private:
};