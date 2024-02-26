#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"


class Cat: public MovingObjects
{
public:
	Cat(const sf::Texture& icon, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Cat() = default;
	virtual void movement(sf::Time deltaTime, const sf::RectangleShape& board,
						  const std::unique_ptr<MovingObjects>& mouse,
						  const std::vector<std::unique_ptr<StaticObjects>>& staticObjects) = 0;
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
	static int getCount();
	void setCatFreeze(bool freeze);
	bool isFreeze()const;
	const sf::Time& getFreezeStartTime() const;
	void setFreezeStartTime(sf::Time time);

	//void checkCatCovered(const sf::Vector2f& nextPosition,
	//	                 std::vector<std::unique_ptr<StaticObjects>>& staticObjects);

private:
	static int m_count;
	bool m_catFreeze = false;
	sf::Time m_freezeStartTime;
	//sf::Sound m_sound;	//will hold a sound of one of the sounds we'll have in handelresources
};