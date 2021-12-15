#include"cCorridor.h"

cCorridor::cCorridor()
{
}

void cCorridor::addCorridor(myRoom* room1, myRoom* room2)
{
	std::string name = "corridor";
	if (corridors.size() > 9)
	{
		name.push_back(corridors.size() / 10);
		name.push_back(corridors.size() % 10);
	}
	else
		name.push_back(corridors.size());
	cords border1 = room1->getBorder(room2->getMiddle());
	cords border2 = room2->getBorder(room1->getMiddle());
	corridors.push_back(corridor(name, room1->getName(), room2->getName(), border1, border2));
}

void cCorridor::addCorridor(cords door, myRoom* toConnect)
{
	std::string name = "corridor";
	if (corridors.size() > 9)
	{
		name.push_back(corridors.size() / 10);
		name.push_back(corridors.size() % 10);
	}
	else
		name.push_back(corridors.size());
	cords border = toConnect->getBorder(door);
	corridors.push_back(corridor(name, "enter/exit", toConnect->getName(), door, border));
}



std::vector<cords> cCorridor::create()
{
	std::vector<cords>result;
	for (int i = 0; i < corridors.size(); ++i)
	{
		std::vector<cords> newOne(corridors[i].create());
		for (int j = 0; j < newOne.size(); ++j)
		{
			result.push_back(newOne[j]);
		}
	}
	return result;
}

std::vector<cords> cCorridor::getFull() const
{
	std::vector<cords> result;
	for (int i = 0; i < corridors.size(); ++i)
	{
		std::vector<cords> v(corridors[i].getCords());
		for (int j = 0; j < v.size(); ++j)
		{
			result.push_back(v[j]);
		}
	}
	return result;
}



int cCorridor::getSize() const noexcept
{
	return corridors.size();
}

void cCorridor::setWalls(cords toSet, std::vector<side> walls)
{
	for (int i = 0; i < corridors.size(); ++i)
	{
		bool toEnd = corridors[i].setWalls(toSet, walls);
		if (toEnd)
			return;
	}
}

corridor cCorridor::getCorridor(int which) const
{
	return corridors[which];
}
