#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.h"

class SmartCat: public Cat
{
public:
	using Cat::Cat;
	virtual ~SmartCat() = default;
	virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
						  const std::unique_ptr<MovingObjects>& mouse,
						  const std::vector<std::unique_ptr<StaticObjects>>& staticObjects);
	bool nextStepIsMouse(sf::RectangleShape up, sf::RectangleShape down, sf::RectangleShape left,
						 sf::RectangleShape right, const std::unique_ptr<MovingObjects>& mouse);
	
	bool validStep(sf::RectangleShape direction, const sf::RectangleShape& board,
				   const std::vector<std::unique_ptr<StaticObjects>>& staticObjects);

private:
	void updateTheNextStep(sf::RectangleShape up, sf::RectangleShape down,
						   sf::RectangleShape left, sf::RectangleShape right,
						   const sf::RectangleShape& board,
						   const std::unique_ptr<MovingObjects>& mouse,
						   const std::vector<std::unique_ptr<StaticObjects>>& staticObjects);
};