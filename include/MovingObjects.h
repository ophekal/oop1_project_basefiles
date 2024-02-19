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

class MovingObjects : public GameObjects
{
public:
	MovingObjects(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~MovingObjects() = default;
	virtual void movement(sf::Time deltaTime) = 0;
	void setDirection(sf::Keyboard::Key key);
	void setObjectSpeed(float speed);

	virtual void collisionHandling(GameObjects&) = 0;
	virtual void collisionHandling(Mouse&) = 0;
	virtual void collisionHandling(Cat&) = 0;
	virtual void collisionHandling(KillCatGift&) = 0;
	virtual void collisionHandling(AddLifeGift&) = 0;
	virtual void collisionHandling(AddTimeGift&) = 0;
	virtual void collisionHandling(FreezeCatGift&) = 0;
	virtual void collisionHandling(Key&) = 0;
	virtual void collisionHandling(Cheese&) = 0;
	virtual void collisionHandling(Door&) = 0;
	virtual void collisionHandling(Wall&);

protected:
	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	float m_objectSpeed = 50.f;		//each object will update according to the speed we will set it to
	//sf::Clock m_MovementTime;		//hold the previous time the object moved
};