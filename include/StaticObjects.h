#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

class StaticObjects:public GameObjects
{
public:
	StaticObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~StaticObjects() = default;
	const sf::Vector2f& getPosition() const;
	virtual void collisionHandling(GameObjects&) = 0;
	virtual void collisionHandling(Mouse&) = 0;
	virtual void collisionHandling(Cat&) = 0;
	virtual void collisionHandling(Wall&) {};
	virtual void collisionHandling(Door&) {};
	virtual void collisionHandling(Cheese&) {};
	virtual void collisionHandling(Key&) {};
	virtual void collisionHandling(KillCatGift&) {};
	virtual void collisionHandling(AddTimeGift&) {};
	virtual void collisionHandling(FreezeCatGift&) {};
	virtual void collisionHandling(AddLifeGift&) {};

protected:
	bool m_currOnBoard = false;
};