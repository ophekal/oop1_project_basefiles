#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"


class Cat: public MovingObjects
{
public:
	Cat(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Cat() = default;
	//virtual void draw(sf::RenderWindow& window) const;
	virtual void movement() = 0;
	virtual void collisionHandling(GameObjects&);
	virtual void collisionHandling(Mouse&);
	virtual void collisionHandling(Cat&);
	virtual void collisionHandling(KillCatGift&);
	virtual void collisionHandling(AddLifeGift&);
	virtual void collisionHandling(AddTimeGift&);
	virtual void collisionHandling(FreezeCatGift&);
	virtual void collisionHandling(Key&);
	virtual void collisionHandling(Cheese&);
	virtual void collisionHandling(Door&);
	static int getCount();

private:
	static int m_count;
	//sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in handelresources
};