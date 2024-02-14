#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Button
{
public:
	Button() = default;
	void printButton(sf::RenderWindow& window, sf::Font& font, std::string type) const;

private:
	sf::Text m_text;
	sf::RectangleShape m_button;
	//sf::Sound m_buttonSound;	//the sound when a button is pressed
};