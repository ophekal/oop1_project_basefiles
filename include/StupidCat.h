#pragma once
#include <SFML/Graphics.hpp>


class StupidCat:: public Cat
{
public:
	using Cat::Cat;
	virtual ~StupidCat() = default;
	virtual void movement();

private:
};