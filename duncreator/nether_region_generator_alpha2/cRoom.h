#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<math.h>

#include"structures.h"
#include"segment.h"
#include"chamber.h"
#include"myRoom.h"
#include"corridor.h"


class cRoom
{
	std::vector<myRoom> rooms;
	std::multimap<std::string, myRoom*> connections;
public:
	cRoom();
	void addChamber(const std::string& name, const int size, const int roomSize);
	std::vector<cords> generateRooms();
	std::multimap<std::string, myRoom*> setConnetions(const cords& entry, const cords& exit);
	std::vector<cords> getFull();
	int getSize() const noexcept;
	myRoom getRoom(const int which) const;
	/*std::multimap<std::string, cords> getNeigCords() const noexcept;*/
	myRoom* findPtr(std::string toFind);
	/*myRoom* findByCords(cords toFind) const noexcept;*/
	void setWalls(cords toSet, std::vector<side> walls);
	void setChests(const int count);
	void setEnemies(const int count);
private:
	double pythagoras(int x1, int x2, int y1, int y2) const;
};