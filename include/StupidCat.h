#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.h"

class StupidCat:public Cat
{
public:
	using Cat::Cat;
	virtual ~StupidCat() = default;
	void movement(sf::Time deltaTime, const sf::RectangleShape& board,
				  const std::unique_ptr<MovingObjects>& mouse,
		          const std::vector<std::unique_ptr<StaticObjects>>& staticObjects);

private:
};