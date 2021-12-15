#include "size_level_screen.h"

sizeLeveScr::sizeLeveScr() :
	scrButton::scrButton()
{
	this->addButton(Button(0.5, "Small", this->getSCRW(), this->getSCRH()));
	this->addButton(Button(0.6, "Medium", this->getSCRW(), this->getSCRH()));
	this->addButton(Button(0.7, "Large", this->getSCRW(), this->getSCRH()));
}

void sizeLeveScr::drawIt(sf::RenderWindow& window)
{
	const int SCRWIDTH = sf::VideoMode::getDesktopMode().width;
	const int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
	sf::Font font;
	font.loadFromFile("fonts/IMMORTAL.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Choose map size");
	text.setFillColor(sf::Color::Blue);
	text.setCharacterSize(64);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, SCRHEIGHT / 4.0f));
	window.draw(text);

	for (int i = 0; i < this->getButAmount(); ++i)
	{
		this->getButton(i).draw(window);
	}
	window.display();
}
