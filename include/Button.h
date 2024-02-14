#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button();
	void printButton(sf::RenderWindow &window) const;

private:
	sf::Text m_text;
	sf::Font* m_font;
	sf::RectangleShape m_button;
	//sf::Sound m_buttonSound;	//the sound when a button is pressed
}