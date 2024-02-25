#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"


class Mouse: public MovingObjects
{
public:
	Mouse (const sf::Texture& icon,const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Mouse() = default;
	virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
						  const  std::vector<std::unique_ptr<MovingObjects>>& cats,
						  const std::unique_ptr<MovingObjects>& mouse,
						  const std::vector<std::unique_ptr<StaticObjects>>& staticObjects);
	//virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board);
	virtual void collisionHandling(GameObjects&);
	virtual void collisionHandling(Wall&);
	virtual void collisionHandling(Mouse&);
	virtual void collisionHandling(Cat&);
	virtual void collisionHandling(KillCatGift&);
	virtual void collisionHandling(AddLifeGift&);
	virtual void collisionHandling(AddTimeGift&);
	virtual void collisionHandling(FreezeCatGift&);
	virtual void collisionHandling(Key&);
	virtual void collisionHandling(Cheese&);
	virtual void collisionHandling(Door&);
	int getKeys()const;

protected:
	int m_lives = 3;
	int m_keys = 0;
	//sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in hndelresources
	void checkMovement(sf::Time deltaTime, const sf::RectangleShape& board);
};