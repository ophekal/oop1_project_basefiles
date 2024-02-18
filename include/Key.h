#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Mouse;
class cat;
class StaticObject;

class Key:public StaticObjects
{
public:
	Key(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Key() = default;

	virtual void collisionHandling(GameObjects& object);
	virtual void collisionHandling(Mouse& mouse);
	virtual void collisionHandling(Cat& cat);

private:
};