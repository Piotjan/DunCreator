#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
#include<memory>

#include"structures.h"
#include"sRoom.h"
#include"chamber.h"
#include"rand2.h"
#include"rand.hpp"

class myRoom : public chamber
{
	int chests;
	int enemies;
	bool water;
	int roomSize;
	int levelSize;
	cords middle;
	shape plan;
	/*std::multimap<std::string, myRoom*> neigh;*/
public:
	myRoom(const std::string& name, const int levelSize, const int roomSize);
	std::vector<cords> create(std::vector<cords> taken);
	void setChests();
	void setEnemies();
	/*void setConnections(myRoom* neighSet) noexcept;
	std::vector<std::string> getConnections() const noexcept;*/
	cords getMiddle() const noexcept;
	myRoom* getPtr();
	cords getBorder(cords toConnect) const noexcept;
	bool getWater() const noexcept;
	void rerollStart(const std::vector<cords>& taken);
	bool searchByName(const std::string& toCheck);
protected:
	bool checkFull(const std::vector<cords>& taken, const cords& cords0, const cords& cords1);
	
};

