#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <string.h>
#include "HandleResources.h"
//---------------------------------------------------------------------------------------

Button::Button()
    :m_rectangle(sf::Vector2f(400.f, 100.f))
{
    m_text.setFont(*HandleResources::instance().getFont());
}

//---------------------------------------------------------------------------------------

void Button::updateButton(const sf::Texture& background, float x, float y, const sf::Vector2f size)
{
    
    m_rectangle.setSize(size);
    //Set the position and color of the rectangle
    m_rectangle.setPosition(x,y);
   // m_rectangle.setFillColor(sf::Color::White);
    m_rectangle.setTexture(&background);


    //m_text.setFont(font);
    //m_text.setString(type);
    //m_text.setCharacterSize(textSize);
    //m_text.setFillColor(sf::Color::Black);

    //// Set the position of the text to be centered within the rectangle
    //sf::FloatRect textBounds = m_text.getLocalBounds();
    //float textX = x + (m_rectangle.getSize().x - textBounds.width) / 2;
    //float textY = y + (m_rectangle.getSize().y - textBounds.height) / 2;
    //m_text.setPosition(textX, textY);

}

//---------------------------------------------------------------------------------------

void Button::printButton(sf::RenderWindow& window) const
{
    window.draw(m_rectangle);
}

//-------------------------------------------------------------
sf::RectangleShape Button::getRectangleButton()const
{
    return m_rectangle;
}
//-------------------------------------------------------------
void Button::setText(const std::string& text)
{
  
    m_text.setString(text);
    m_text.setCharacterSize(INFOBAR_TEXT_SIZE);
    m_text.setFillColor(sf::Color::Black);

    // Set the position of the text to be centered within the rectangle
    sf::FloatRect textBounds = m_text.getLocalBounds();
    float textX = m_rectangle.getPosition().x + (m_rectangle.getSize().x - textBounds.width) / 2;
    float textY = m_rectangle.getPosition().y + (m_rectangle.getSize().y - textBounds.height) / 2;
    m_text.setPosition(textX, textY);

}