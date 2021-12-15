#include"with_map_scr.h"

withMapScr::withMapScr()
{
	int SCRWIDTH = sf::VideoMode::getDesktopMode().width;
	int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
	sf::Vector2i position;
	position.x = SCRWIDTH - 200;
	position.y = 10;
	this->addButton(Button(position, "Save"));
	position.y += 50;
	this->addButton(Button(position, "Reroll"));
	position.y += 50;
	this->addButton(Button(position, "Exit"));
}

void withMapScr::drawIt(sf::RenderWindow& window)
{
	for (int i = 0; i < this->getButAmount(); ++i)
	{
		this->getButton(i).draw(window);
	}
}
