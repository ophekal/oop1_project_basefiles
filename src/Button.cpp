#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

//---------------------------------------------------------------------------------------

Button::Button()
    :m_rectangle(sf::Vector2f(400.f, 100.f))
{
}
//---------------------------------------------------------------------------------------
void Button::updateSize(float width, float hight)
{
    m_rectangle.setSize({ width, hight });
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
   // m_rectangle.setOutlineThickness(3.f);
    //m_rectangle.setOutlineColor(sf::Color::Red);
    window.draw(m_rectangle);
    //window.draw(m_sprite);
   // window.draw(m_text);
}

//-------------------------------------------------------------
sf::RectangleShape Button::getRectangleButton()const
{
    return m_rectangle;
}
