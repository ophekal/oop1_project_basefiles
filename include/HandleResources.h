#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string.h>
#include <vector>
#include "Macros.h"

class HandleResources
{
public:
	static HandleResources& instance();

	const sf::Texture* getObjectTexture(IconType icon);
	const sf::Texture* getBackgroundTexture(Background icon);
	const sf::Texture* getInfoBarTexture(Bar icon);
	const sf::Texture* getScreenTexture(Screen icon);
	const sf::Font* getFont();
	//static HandleResources& getSounds();
	

private:
	HandleResources();   //update all the resources of the play
	//~HandleResources() = delete;   
	void updateObjectVector();
	void updateBackgroundVector();
	void updateInfoBarVector();
	void updateScreenVector();

	std::vector<sf::Texture> m_objectsTextures;
	std::vector<sf::Texture> m_backgroundsTextures;	//menu, infobar, window
	std::vector<sf::Texture> m_infoBarTextures;	//menu, infobar, window
	std::vector<sf::Texture> m_screenTextures;

	sf::Font m_font;				//holds the font
	//sf::Sound m_sounds[numOfSounds];	//hold the different sounds of the game
	//sf::SoundBuffer m_soundBuffer[numOfSounds];

};