#pragma once
#include <SFML/Graphics.hpp>
#include "Cat.h"

class StupidCat:public Cat
{
public:
	using Cat::Cat;
	virtual ~StupidCat() = default;
	virtual void movement();

private:
};