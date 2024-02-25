#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

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

class GameObjects
{
public:
	GameObjects(const sf::Texture& picture, const sf::Vector2f& position,const sf::Vector2f& size);
	virtual ~GameObjects() = default;
	virtual void draw(sf::RenderWindow& window);
	//void setPosition(const sf::Vector2f& newPosition);
	bool offBoard()const;
	void setOffBoard(bool off);
	void setCovered(bool covered);
	bool isCovered()const;
	bool checkCollision(GameObjects& objcet);
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
	virtual void collisionHandling(Wall&) = 0;


protected:
	sf::RectangleShape m_object;
	bool m_offBoard;
	bool m_covered;
};