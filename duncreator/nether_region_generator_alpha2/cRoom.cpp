#include"cRoom.h"

cRoom::cRoom()
{
}

std::vector<cords> cRoom::generateRooms()
{
	int made = 0;
	std::vector<cords> result;
	do
	{
		std::vector<cords> v(rooms[made].create(result));
		if (v.size() > 1)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				result.push_back(v[i]);
			}
			++made;
		}
		else
		{
			result.clear();
			result.push_back(cords{ 1,1 });
			return result;
		}
	} while (made < rooms.size());
	return result;
}

std::multimap<std::string, myRoom*> cRoom::setConnetions(const cords& entry, const cords& exit)     //tu popsute
{
	std::multimap<std::string, myRoom*> result;
	std::vector<cords> middles;
	for (int i = 0; i < rooms.size(); ++i)
	{
		middles.push_back(rooms[i].getMiddle());
	}
	for (int i = 0; i < middles.size(); ++i)
	{
		double min = 100000;
		double minSecond = 10000;
		myRoom* firstConnect = nullptr;
		myRoom* secondConnect = nullptr;
		for (int j = 0; j < middles.size(); ++j)
		{
			if (rooms[j].getName() != rooms[i].getName())
			{
				double pythag = pythagoras(middles[i].x, middles[j].x, middles[i].y, middles[j].y);
				if (pythag < min)
				{
					min = pythag;
					firstConnect = &rooms[j];
				}
				else if (pythag < minSecond)
				{
					minSecond = pythag;
					secondConnect = &rooms[j];
				}
			}
		}
		result.insert(std::pair<std::string, myRoom*>(rooms[i].getName(), firstConnect));
		if(secondConnect!=nullptr)
			result.insert(std::pair<std::string, myRoom*>(rooms[i].getName(), secondConnect));
	}
	int min = 10000;
	myRoom* toEntry;
	for (int i = 0; i < middles.size(); ++i)
	{
		double pythag;
		pythag = pythagoras(entry.x, middles[i].x, entry.y, middles[i].y);
		if (pythag < min)
		{
			min = pythag;
			toEntry = &rooms[i];
		}
	}
	result.insert(std::pair<std::string, myRoom*>("entry", toEntry));
	min = 10000;
	myRoom* toExit;
	for (int i = 0; i < middles.size(); ++i)
	{
		double pythag;
		pythag = pythagoras(entry.x, middles[i].x, entry.y, middles[i].y);
		if (pythag < min && rooms[i].getName()!=toEntry->getName())
		{
			min = pythag;
			toExit = &rooms[i];
		}
	}
	result.insert(std::pair<std::string, myRoom*>("exit", toExit));
	return result;
}

void cRoom::addChamber(const std::string& name, const int size, const int roomSize)
{
	rooms.push_back(myRoom(name, size, roomSize));
}

std::vector<cords> cRoom::getFull()
{
	std::vector<cords> result;
	for (int i = 0; i < rooms.size(); ++i)
	{
		std::vector<cords> v(rooms[i].getCords());
		for (int j = 0; j < v.size(); ++j)
		{
			result.push_back(v[j]);
		}
	}
	return result;
}



int cRoom::getSize() const noexcept
{
	return rooms.size();
}

myRoom cRoom::getRoom(const int which) const
{
	return rooms[which];
}

myRoom* cRoom::findPtr(std::string toFind)
{
	for (int i = 0; i < rooms.size(); ++i)
	{
		if (rooms[i].getName() == toFind)
			return &rooms[i];
	}
	return nullptr;
}

void cRoom::setWalls(cords toSet, std::vector<side> walls)
{
	for (int i = 0; i < rooms.size(); ++i)
	{
		bool toEnd = rooms[i].setWalls(toSet, walls);
		if (toEnd)
			return;
	}
}

void cRoom::setChests(const int count)
{
	for (int i = 0; i < count; ++i)
	{
		rooms[rng(0, rooms.size() - 1)].setChests();
	}
}

void cRoom::setEnemies(const int count)
{
	for (int i = 0; i < count; ++i)
	{
		rooms[rng(0, rooms.size() - 1)].setEnemies();
	}
}

double cRoom::pythagoras(int x1, int x2, int y1, int y2) const
{
	double result = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));
	return result;
}
