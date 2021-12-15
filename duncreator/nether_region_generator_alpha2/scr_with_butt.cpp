#include"scr_with_butt.h"

scrButton::scrButton():
	SCRWIDTH(sf::VideoMode::getDesktopMode().width),
	SCRHEIGHT(sf::VideoMode::getDesktopMode().height)
{
}

void scrButton::addButton(Button newBut)
{
	buttons.push_back(newBut);
}

Button& scrButton::getButton(const int which)
{
	return buttons[which];
}

int scrButton::getSCRW() const
{
	return SCRWIDTH;
}

int scrButton::getSCRH() const
{
	return SCRHEIGHT;
}

int scrButton::getButAmount() const
{
	return buttons.size();
}

int scrButton::checkChoose(sf::Event event)
{
	sf::Vector2f wherePressed(event.mouseButton.x, event.mouseButton.y);
	for (int i = 0; i < this->getButAmount(); ++i)
	{
		if (this->getButton(i).isClicked(wherePressed))
			return i + 1;
	}
	return 0;
}