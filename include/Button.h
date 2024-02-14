#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Button
{
public:
	Button();
	void updateButton(const sf::Font& font, std::string type, float x, float y);
	void printButton(sf::RenderWindow& window) const;
	sf::RectangleShape getRectangleButton()const;

private:
	sf::Text m_text;
	sf::RectangleShape m_rectangle;

	//sf::Sound m_buttonSound;	//the sound when a button is pressed
};