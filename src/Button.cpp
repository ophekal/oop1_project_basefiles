#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"


Button::Button()
{
}

void Button::printButton(sf::RenderWindow& window, sf::Font &font, std::string type ) const
{
    m_text.setFont(font)
    m_text.setString(type);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    // Set the position of the text (relative to the window)
    text.setPosition(100, 100);

}
