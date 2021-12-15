#include"menu_controller.h"

menuController::menuController() :
	SCRWIDTH(sf::VideoMode::getDesktopMode().width),
	SCRHEIGHT(sf::VideoMode::getDesktopMode().height)
{
}

bool menuController::start(std::vector<int>& settings, sf::RenderWindow& window)
{
	startScreen openScreen;
	openScreen.drawIt(window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				switch (openScreen.checkChoose(event))
				{
				case 0: break;
				case 1:
					int current;
					current = this->levelSizeChoose(window, event);
					if (current != 100)
						settings.push_back(current);
					else
					{
						window.close();
						return false;
					}
					current = this->roomSizeChoose(window, event);
					if (current != 100)
						settings.push_back(current);
					else
					{
						window.close();
						return false;
					}
					current = this->difficultChoose(window, event);
					if (current != 100)
						settings.push_back(current);
					else
					{
						window.close();
						return false;
					}
					return false;
				case 2:
					this->creatorsView(window, event);
					openScreen.drawIt(window);
					break;
				case 3:
					window.close();
					return false;
				default: break;
				}
			}
		}
	}
}

bool menuController::newMap(level* myLevel, sf::RenderWindow& window)
{
	window.clear();
	graphCreator graphMap(myLevel);
	graphMap.createMap(window);
	withMapScr addScreen;
	addScreen.drawIt(window);
	window.display();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				switch (addScreen.checkChoose(event))
				{
				case 1:
					this->saveMap(window);
					window.close();
					return false;
				case 2: return true;
				case 3:
					window.close();
					return false;
				default: break;
				}
			}
		}
	}
}

int menuController::levelSizeChoose(sf::RenderWindow& window, sf::Event& event)
{
	window.clear();
	sizeLeveScr thisScreen;
	thisScreen.drawIt(window);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 100;
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				int chosen = thisScreen.checkChoose(event);
				if (chosen > 0)
					return chosen;
			}
		}
	}
}

int menuController::roomSizeChoose(sf::RenderWindow& window, sf::Event& event)
{
	window.clear();
	sizeRoomScr thisScreen;
	thisScreen.drawIt(window);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 100;
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				int chosen = thisScreen.checkChoose(event);
				if (chosen > 0)
					return chosen;
			}
		}
	}
}

int menuController::difficultChoose(sf::RenderWindow& window, sf::Event& event)
{
	window.clear();
	difficultScr thisScreen;
	thisScreen.drawIt(window);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 100;
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				int chosen = thisScreen.checkChoose(event);
				if (chosen > 0)
					return chosen;
			}
		}
	}
}

int menuController::creatorsView(sf::RenderWindow& window, sf::Event& event)
{
	window.clear();
	creatorsScr thisScreen;
	thisScreen.drawIt(window);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 100;
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (thisScreen.checkChoose(event) == 1)
				{
					window.clear();
					return 0;
				}
			}
		}
	}
}

bool menuController::saveMap(sf::RenderWindow& mainApp)
{
	std::fstream file;
	std::string number;
	file.open("config.txt");
	if (file.is_open())
	{
		file >> number;
	}
	int amount = std::stoi(number);
	std::string fileName("saves/map" + number + ".png");
	++amount;
	file << amount;
	file.close();
	remove("config.txt");
	std::fstream newFile;
	newFile.open("config.txt", std::ios::out);
	newFile << amount;
	newFile.close();
	sf::Texture toSave;
	toSave.create(mainApp.getSize().x, mainApp.getSize().y);
	toSave.update(mainApp);
	return toSave.copyToImage().saveToFile(fileName);

}
