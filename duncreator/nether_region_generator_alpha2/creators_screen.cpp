#include"creators_screen.h"

creatorsScr::creatorsScr() :
	scrButton::scrButton()
{
	this->addButton(Button(0.9, "Back", this->getSCRW(), this->getSCRH()));
}

void creatorsScr::drawIt(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("fonts/IMMORTAL.ttf");
	sf::Text header1;
	header1.setFont(font);
	header1.setString("Code written by:");
	header1.setFillColor(sf::Color::Red);
	header1.setCharacterSize(32);
	sf::FloatRect textRect = header1.getLocalBounds();
	header1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	header1.setPosition(sf::Vector2f(this->getSCRW() / 2.0f, this->getSCRH() / 5.0f));
	window.draw(header1);

	sf::Text name1;
	name1.setFont(font);
	name1.setString("Piotr Janowski");
	name1.setFillColor(sf::Color::Red);
	name1.setCharacterSize(42);
	textRect = name1.getLocalBounds();
	name1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	name1.setPosition(sf::Vector2f(this->getSCRW() / 2.0f, this->getSCRH() / 5.0f + 45));
	window.draw(name1);

	sf::Text header2;
	header2.setFont(font);
	header2.setString("Graphic by:");
	header2.setFillColor(sf::Color::Red);
	header2.setCharacterSize(32);
	textRect = header2.getLocalBounds();
	header2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	header2.setPosition(sf::Vector2f(this->getSCRW() / 2.0f, 2 * (this->getSCRH() / 5.0f)));
	window.draw(header2);

	sf::Text name2;
	name2.setFont(font);
	name2.setString("Jakub Hampel");
	name2.setFillColor(sf::Color::Red);
	name2.setCharacterSize(42);
	textRect = name2.getLocalBounds();
	name2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	name2.setPosition(sf::Vector2f(this->getSCRW() / 2.0f, 2 * (this->getSCRH() / 5.0f) + 45));
	window.draw(name2);

	sf::Text studioName;
	studioName.setFont(font);
	studioName.setString("Red Trash Panda Studio, 2021");
	studioName.setFillColor(sf::Color::Red);
	studioName.setCharacterSize(32);
	textRect = studioName.getLocalBounds();
	studioName.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	studioName.setPosition(sf::Vector2f(this->getSCRW() / 2.0f, 4 * (this->getSCRH() / 5.0f)));
	window.draw(studioName);


	for (int i = 0; i < this->getButAmount(); ++i)
	{
		this->getButton(i).draw(window);
	}
	window.display();
}
