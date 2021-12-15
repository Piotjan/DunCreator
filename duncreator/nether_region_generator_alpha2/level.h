#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<thread>
#include <unordered_set>

#include"structures.h"
#include"myRoom.h"
#include"cRoom.h"
#include"cCorridor.h"
#include"rand2.h"
#include"rand.hpp"
#include"text_display2.h"

class level
{
	int difficulty;
	int size;
	int roomSize;
	int roomNumber;
	cRoom myRooms;
	cCorridor corridors;
	std::vector<cords> taken;
	std::multimap<std::string, myRoom*> connections;
	cords enter;
	cords exit;
public:
	level(const int difficulty, const int size, const int roomSize);
	void setSize();
	bool createRooms();
	void makeConnect();
	void makeCorridors();
	void setWalls();
	void createEnemies();
	void createChests();

	cCorridor getCorridors();
	cRoom getRooms();
	int getRoomsAmount();
	cords getEntry() const noexcept;
	cords getExit() const noexcept;

	int getSize();
	int getElementsCount();
	std::vector<cords> getTaken() const noexcept;
	bool getSement(const cords cor);
	bool guide();
};