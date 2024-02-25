#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"

class Controller;

class Gift: public StaticObjects
{
public:
	Gift(const sf::Texture& picture, const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~Gift() = default;
	void setActive(bool activate);
	bool isActive()const;
	virtual void handleGift(Controller& controller) =0;
	virtual void collisionHandling(GameObjects&);
	virtual void collisionHandling(Cat&);
	virtual void collisionHandling(Mouse&);
	static int getCount();

private:
	static int m_count;
	bool m_giftActive = false;

};