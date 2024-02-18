#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Gift: public StaticObjects
{
public:
	Gift(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Gift() = default;
	//virtual void draw(sf::RenderWindow& window)=0;	//each gift will have a different icon so virtual here
	virtual void collisionHandling(GameObjects&);
	virtual void collisionHandling(Cat&);
	virtual void collisionHandling(Mouse&);

private:

};