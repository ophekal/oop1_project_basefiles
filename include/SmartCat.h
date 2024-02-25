#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.h"


class SmartCat: public Cat
{
public:
	using Cat::Cat;
	virtual ~SmartCat() = default;
	virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
						  std::vector<std::unique_ptr<MovingObjects>> cats,
		std::unique_ptr<MovingObjects> mouse,
		std::vector<std::unique_ptr<StaticObjects>> staticObjects);

private:
};