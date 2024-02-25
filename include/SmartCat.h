#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.h"


class SmartCat: public Cat
{
public:
	using Cat::Cat;
	virtual ~SmartCat() = default;
	virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
						 const  std::vector<std::unique_ptr<MovingObjects>> &cats,
						 const std::unique_ptr<MovingObjects>& mouse,
						 const std::vector<std::unique_ptr<StaticObjects>>& staticObjects);

private:
};