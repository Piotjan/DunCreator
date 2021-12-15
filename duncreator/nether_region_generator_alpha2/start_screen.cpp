#include"start_screen.h"

startScreen::startScreen() :
	scrButton::scrButton()
{
	this->addButton(Button(0.5,"New map", this->getSCRW(), this->getSCRH()));
	this->addButton(Button(0.6, "Creators", this->getSCRW(), this->getSCRH()));
	this->addButton(Button(0.7, "Exit", this->getSCRW(), this->getSCRH()));
}

void startScreen::drawIt(sf::RenderWindow& window)
{
	const int SCRWIDTH = sf::VideoMode::getDesktopMode().width;
	const int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
	sf::Font font;
	font.loadFromFile("fonts/IMMORTAL.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Dun Creator");
	text.setFillColor(sf::Color::Red);
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