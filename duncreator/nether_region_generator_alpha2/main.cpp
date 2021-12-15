#include<iostream>
#include<SFML/Graphics.hpp>

#include "level.h"
#include "menu_controller.h"
#include"graph_creator.h"

#include "with_map_scr.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "DunCreator");
	menuController myMenu;
	std::vector<int> settings;
	myMenu.start(settings, window);
	if (!window.isOpen())
		return 0;
	bool toEnd = false;
	do
	{
		level myLevel(settings[2], settings[0], settings[1]);
		toEnd = myLevel.guide();
		if(!toEnd)
			toEnd = myMenu.newMap(&myLevel, window);
	} while (toEnd);
	if (!window.isOpen())
		return 0;
}