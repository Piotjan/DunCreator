#include "level.h"

level::level(const int difficulty, const int size, const int roomSize) :
	difficulty(difficulty),
	size(size),
	roomSize(roomSize)
{
}

void level::setSize()
{
	//Wielkoœæ poziomu
	switch (size)
	{
	case 1: size = 41; break;
	case 2: size = 51; break;
	case 3: size = 61; break;
	default: break;
	}


	//Wielkoœæ pomieszczenia
	switch (roomSize)
	{
	case 1: roomSize = 6; break;
	case 2: roomSize = 9; break;
	case 3: roomSize = 15; break;
	default: break;
	}

	roomNumber = size / roomSize;

	int x1, x2, y1, y2;
	std::vector<int> choices;
	choices.push_back(0);
	choices.push_back(size - 1);
	do
	{
		if (rng(1, 2) % 2 == 0)
		{
			x1 = rngFrom(choices);
			y1 = rng(0, size - 1);
		}
		else
		{
			y1 = rngFrom(choices);
			x1 = rng(0, size - 1);
		}

		if (rng(1, 2) % 2 == 0)
		{
			x2 = rngFrom(choices);
			y2 = rng(0, size - 1);
		}
		else
		{
			y2 = rngFrom(choices);
			x2 = rng(0, size - 1);
		}
	} while (x1 == x2 && y1 == y2);
	enter = cords{ x1,y1 };
	exit = cords{ x2,y2 };
}

bool level::createRooms()
{
	for (int i = 0; i < roomNumber; ++i)
	{
		std::string name("room");
		std::string c = std::to_string(i);
		name.push_back(c[0]);
		myRooms.addChamber(name, size, roomSize);
	}
	taken = myRooms.generateRooms();
	if (taken.size() > 1)
		return true;
	return false;
}

void level::makeConnect()
{
	connections = myRooms.setConnetions(enter, exit);
}

void level::makeCorridors()
{
	std::multimap<std::string, myRoom*> copy;
	for (auto itr = connections.begin(); itr != connections.end(); ++itr)
	{
		if (itr->first == "entry")
			corridors.addCorridor(enter, itr->second);
		else if (itr->first == "exit")
			corridors.addCorridor(exit, itr->second);
		else
		{
			bool ifAdd = true;
			for (auto itrC = copy.begin(); itrC != copy.end(); ++itrC)
			{
				if (itr->first == itrC->first && itr->second == itrC->second)
					ifAdd = false;
			}
			if (ifAdd)
			{
				myRoom* ptr = myRooms.findPtr(itr->first);
				corridors.addCorridor(ptr, itr->second);
				copy.insert(std::pair<std::string, myRoom*>(itr->second->getName(), ptr));
			}
		}
	}
	
	std::vector<cords> newOne(corridors.create());
	for (int i = 0; i < newOne.size(); ++i)
	{
		taken.push_back(newOne[i]);
	}
}

void level::setWalls()
{
	for (int i = 0; i < taken.size(); ++i)
	{
		std::vector<side> neigh;
		for (int j = 0; j < taken.size(); ++j)
		{
			if (taken[j].y == taken[i].y + 1 && taken[j].x == taken[i].x)
				neigh.push_back(south);
			else if (taken[j].y == taken[i].y - 1 && taken[j].x == taken[i].x)
				neigh.push_back(north);
			else if (taken[j].x == taken[i].x + 1 && taken[j].y == taken[i].y)
				neigh.push_back(east);
			else if (taken[j].x == taken[i].x - 1 && taken[j].y == taken[i].y)
				neigh.push_back(west);
		}
		std::vector<side> walls;
		for (int j = 0; j < 4; ++j)
		{
			bool ifAdd = true;
			for (int k = 0; k < neigh.size(); ++k)
			{
				if (neigh[k] == j)
					ifAdd = false;
			}
			if (ifAdd)
			{
				switch (j)
				{
				case 0: walls.push_back(north); break;
				case 1: walls.push_back(east); break;
				case 2: walls.push_back(south); break;
				case 3: walls.push_back(west); break;
				default: break;
				}
			}
		}
		for (int j = walls.size(); j < 3; ++j)
		{
			walls.push_back(none);
		}

		std::thread t1([&] {corridors.setWalls(taken[i], walls); });
		std::thread t2([&] {myRooms.setWalls(taken[i], walls); });
		t1.join();
		t2.join();
	}
}

void level::createEnemies()
{
	int count;
	switch (difficulty)
	{
	case 1: count = 2; break;
	case 2: count = 3; break;
	case 3: count = 5; break;
	default: break;
	}
	myRooms.setEnemies(count);
}

void level::createChests()
{
	int count;
	switch (difficulty)
	{
	case 1: count = 2; break;
	case 2: count = 3; break;
	case 3: count = 5; break;
	default: break;
	}
	myRooms.setChests(count);
}

cCorridor level::getCorridors()
{
	return corridors;
}

cRoom level::getRooms()
{
	return myRooms;
}

int level::getRoomsAmount()
{
	return myRooms.getSize();
}

cords level::getEntry() const noexcept
{
	return enter;
}

cords level::getExit() const noexcept
{
	return exit;
}

int level::getSize()
{
	return size;
}

int level::getElementsCount()
{
	return taken.size();
}

std::vector<cords> level::getTaken() const noexcept
{
	return taken;
}

bool level::getSement(const cords cor)
{
	for (int i = 0; i < taken.size(); ++i)
	{
		if (cor.x == taken[i].x && cor.y == taken[i].y)
			return true;
	}
	return false;
}

bool level::guide()
{
	this->setSize();
	if (!this->createRooms())
		return true;
	this->makeConnect();
	this->makeCorridors();
	this->setWalls();
	this->createChests();
	this->createEnemies();
	return false;
}
