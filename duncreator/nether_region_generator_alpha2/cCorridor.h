#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>


#include"structures.h"
#include"segment.h"
#include"chamber.h"
#include"myRoom.h"
#include"corridor.h"

class cCorridor
{
	std::vector<corridor> corridors;
public:
	cCorridor();
	void addCorridor(myRoom* room1, myRoom* room2);
	void addCorridor(cords door, myRoom* toConnect);
	std::vector<cords> create();
	std::vector<cords> getFull() const;
	int getSize() const noexcept;
	void setWalls(cords toSet, std::vector<side> walls);
	corridor getCorridor(int which) const;
};