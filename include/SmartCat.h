#pragma once
#include <SFML/Graphics.hpp>


class SmartCat:: public Cat
{
public:
	using Cat::Cat;
	virtual ~SmartCat() = default;
	virtual void movement();

private:
};