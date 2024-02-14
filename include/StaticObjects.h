#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

class Mouse;
class Cat;
class Wall;
class KillCatGift;
class AddTimeGift;
class FreezeCatGift;
class AddLifeGift;
class Key;
class Cheese;
class Door;

class StaticObjects:: public GameObjects
{
public:
	using GameObjects::GameObjects;
	virtual ~StaticObject() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void collisionHandling() = 0;


	virtual void collisionHandling(GameObjects&) = 0;
	virtual void collisionHandling(Mouse&) = 0;
	virtual void collisionHandling(Cat&) = 0;
	virtual void collisionHandling(Wall&) = 0;
	virtual void collisionHandling(Door&) = 0;
	virtual void collisionHandling(Cheese&) = 0;
	virtual void collisionHandling(Key&) = 0;
	virtual void collisionHandling(KillCatGift&) = 0;
	virtual void collisionHandling(AddTimeGift&) = 0;
	virtual void collisionHandling(FreezeCatGift&) = 0;
	virtual void collisionHandling(AddLifeGift&) = 0;

protected:
	bool currOnBoard = false;
};