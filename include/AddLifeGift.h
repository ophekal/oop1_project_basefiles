#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"


class AddLifeGift : public Gift
{
public:
	using Gift::Gift;
	virtual ~AddLifeGift() = default;
	void collisionHandling(GameObjects& object);
	void collisionHandling(Mouse& mouse);
	void collisionHandling(Cat& cat);

	virtual void handleGift(Controller& controller);

private:

};