#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<thread>
#include<cmath>
#include<exception>
#include<SFML/Graphics.hpp>
#include<SFML/System/Vector2.hpp>
#include<SFML/Graphics/Rect.hpp>

#include"graphic_name.h"
#include"level.h"
#include"structures.h"
#include"rand.hpp"
#include"rand2.h"
#include"cCorridor.h"
#include"cRoom.h"
#include"chamber.h"
#include"corridor.h"
#include"myRoom.h"
#include"segment.h"
#include"sRoom.h"
#include"sCorridor.h"

class graphCreator : public graphicsName
{
	level* levelToCreate;
	int SCRWIDTH;
	int SCRHEIGHT;
	int pixelRatio;
public:
	graphCreator(level* _level);
	bool createMap(sf::RenderWindow& window) noexcept;
private:
	void drawFloorRoom(const sf::RenderWindow& window, const std::vector<cords>& taken) noexcept;
	std::vector<cords> drawWater(sf::RenderWindow& window);
	void drawWallsCor(sf::RenderWindow& window);
	void drawWallsRom(sf::RenderWindow& window);
	sf::Vector2f setResize() const noexcept;
	bool wallSetGraphic(sf::Texture& tWall, const std::vector<side>& whereWalls, const int whichTextur);
	std::vector<cords> setDeepWater(const cords startCords);
	std::vector<cords> setPuddleWater(const std::vector<cords>& deep);
	std::vector<cords> drawChests(sf::RenderWindow& window);
	void drawEnemies(sf::RenderWindow& window);
	void drawDecorations(sf::RenderWindow& window, const std::vector<cords>& water);
	bool isItNeigh(const cords& a, const cords& b);
};