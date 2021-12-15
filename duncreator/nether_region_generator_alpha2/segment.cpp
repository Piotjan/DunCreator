#include"segment.h"

segment::segment(cords cords) : 
	coordinates(cords),
	chest(0),
	enemy(0)
{
}

cords segment::getCords() const noexcept
{
	return coordinates;
}

void segment::setWalls(std::vector<side>& _walls)
{
	if(walls.size() == 0)
		walls = std::move(_walls);
}

std::vector<side> segment::getWalls() const
{
	return walls;
}

void segment::setChest()
{
	std::vector<int> value = { 1,2,3 };
	chest = rngGeom(value);
}

void segment::setEnemy()
{
	std::vector<int> value = { 1,2,3 };
	enemy = rngGeom(value);
}

int segment::getChests() const noexcept
{
	return chest;
}

int segment::getEnemy() const noexcept
{
	return enemy;
}




