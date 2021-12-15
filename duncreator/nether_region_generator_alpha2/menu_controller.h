#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<chrono>
#include<fstream>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System/Vector2.hpp>
#include<SFML/System/String.hpp>

#include"start_screen.h"
#include"size_level_screen.h"
#include"size_room_screen.h"
#include"difficult_screen.h"
#include"creators_screen.h"
#include"graph_creator.h"
#include"with_map_scr.h"
#include"loading_screen.h"

class menuController
{
	int SCRWIDTH;
	int SCRHEIGHT;
public:
	menuController();
	bool start(std::vector<int>& settings, sf::RenderWindow& window);
	bool newMap(level* myLevel, sf::RenderWindow& window);
private:
	//da sie to wcisn¹æ w jedn¹ funkcjê, polimorfizm siê k³ania
	int levelSizeChoose(sf::RenderWindow& window, sf::Event& event);
	int roomSizeChoose(sf::RenderWindow& window, sf::Event& event);
	int difficultChoose(sf::RenderWindow& window, sf::Event& event);
	//int withMapChoose(sf::RenderWindow& window, sf::Event& event, withMapScr& thisScreen);
	int creatorsView(sf::RenderWindow& window, sf::Event& event);
	bool saveMap(sf::RenderWindow& mainApp);
};