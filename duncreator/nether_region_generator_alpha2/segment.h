#pragma once
#include<iostream>
#include<vector>
#include<string>

#include"structures.h"
#include"rand.hpp"

class segment
{
	cords coordinates;
	//std::string graphicName;
	std::vector<side> walls;
	int chest;
	int enemy;
public:
	segment(cords cords);
	virtual ~segment() {};
	//void setGraphic(const std::string& name);
	//std::string getGraphic() const;
	cords getCords() const noexcept;
	void setWalls(std::vector<side>& _walls);
	std::vector<side> getWalls() const;
	/*void setNeighbours(const std::vector<segment*>& neigh) noexcept;*/
	void setChest();
	void setEnemy();
	int getChests() const noexcept;
	int getEnemy() const noexcept;
	//virtual void setChest() noexcept = 0;
};



