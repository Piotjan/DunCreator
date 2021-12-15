#include "myRoom.h"

myRoom::myRoom(const std::string& name, const int levelSize, const int roomSize) :
	chamber::chamber(name),
	levelSize(levelSize),
	roomSize(roomSize)
{
	water = rngProb(0.3);
}

std::vector<cords> myRoom::create(std::vector<cords> taken)	
{
	rerollStart(taken);
	bool end;
	int options = 0;

	plan = static_cast<shape>(rng(0,3));
	cords temp[2];
	int dif = roomSize / 2;
	if (plan == shape::room)
	{
		temp[1] = { middle.x + dif + 3, middle.y + dif + 3 };
		temp[0] = { middle.x - dif, middle.y - dif };
	}
	else
	{
		temp[1] = { middle.x + dif, middle.y + dif };
		temp[0] = { middle.x - dif, middle.y - dif };
	}
	do
	{
		if (checkFull(taken, temp[0], temp[1]))
		{
			taken.push_back(middle);
			end = false;
			rerollStart(taken);
			++options;
			if (plan == shape::room)
			{
				temp[1] = { middle.x + dif + 3, middle.y + dif + 3 };
				temp[0] = { middle.x - dif, middle.y - dif };
			}
			else
			{
				temp[1] = { middle.x + dif, middle.y + dif };
				temp[0] = { middle.x - dif, middle.y - dif };
			}
		}
		else if (temp[0].x < 0 || temp[0].y < 0 || temp[1].x >= levelSize || temp[1].y >= levelSize)
		{
			taken.push_back(middle);
			end = false;
			rerollStart(taken);
			++options;
			if (plan == shape::room)
			{
				temp[1] = { middle.x + dif + 3, middle.y + dif + 3 };
				temp[0] = { middle.x - dif, middle.y - dif };
			}
			else
			{
				temp[1] = { middle.x + dif, middle.y + dif };
				temp[0] = { middle.x - dif, middle.y - dif };
			}
		}
		else
			end = true;
	} while (!end && options < levelSize);

	if (options == levelSize)
	{
		cords c = { 0,0 };
		std::vector<cords> r;
		r.push_back(c);
		return r;
	}

	switch (plan)
	{
	case 0:
	{
		for (int i = 0; i < roomSize; ++i)
		{
			for (int j = 0; j < roomSize; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		break;
	}
	case 1:
	{
		int third = roomSize / 3;
		int i = 0;
		int j = third;
		int k = (2 * third) + 1;
		for (i; i < third; ++i)
		{
			for (int l = j; l < k; ++l)
			{
				cords c{ i + temp[0].x,l + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
			--j;
			++k;
		}
		for (i; i < 2 * third; ++i)
		{
			for (int l = 0; l < roomSize + 1; ++l)
			{
				cords c{ i + temp[0].x,l + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		++j;
		--k;
		for (i; i < roomSize; ++i)
		{
			for (int l = j; l < k; ++l)
			{
				cords c{ i + temp[0].x,l + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
			++j;
			--k;
		}
		break;
	}
	case 2:
	{
		int third = roomSize / 3;
		int i = 0;
		for (i; i < third; ++i)
		{
			for (int j = third; j < 2 * third; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		for (i; i < 2 * third; ++i)
		{
			for (int j = 0; j < roomSize; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		for (i; i < roomSize; ++i)
		{
			for (int j = third; j < 2 * third; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < roomSize; ++i)
		{
			for (int j = 0; j < roomSize; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		for (int i = roomSize; i < roomSize + 3; ++i)
		{
			for (int j = (roomSize / 2) + 1; j < roomSize; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		for (int i = (roomSize / 2) + 1; i < roomSize; ++i)
		{
			for (int j = roomSize; j < roomSize + 3; ++j)
			{
				cords c{ i + temp[0].x,j + temp[0].y };
				std::shared_ptr<segment> ptr(new sRoom(c));
				addSegment(ptr);
			}
		}
		break;
	}
	default: break;
	}
	return getCords();
}

void myRoom::setChests()
{
	bool toEnd = false;
	do
	{
		int current = rng(0, this->getSize() - 1);
		if (this->getSegment(current)->getChests() == 0)
		{
			this->getSegment(current)->setChest();
			toEnd = true;
		}
			
	} while (!toEnd);
}

void myRoom::setEnemies()
{
	bool toEnd = false;
	do
	{
		int current = rng(0, this->getSize() - 1);
		if (this->getSegment(current)->getChests() == 0 && this->getSegment(current)->getEnemy() == 0)
		{
			this->getSegment(current)->setEnemy();
			toEnd = true;
		}

	} while (!toEnd);
}

cords myRoom::getMiddle() const noexcept
{
	return middle;
}

myRoom* myRoom::getPtr()
{
	return this;
}

cords myRoom::getBorder(cords toConnect) const noexcept
{
	int xDif = middle.x - toConnect.x;
	int yDif = middle.y - toConnect.y;
	int dif = roomSize / 2;
	int x;
	std::vector<int> ys;
	if (xDif < 0)
		x = middle.x - dif;
	else
	{
		std::vector<int> toChoose;
		toChoose.push_back(middle.x);
		toChoose.push_back(middle.x + 3);
		x = rngFrom(toChoose);
	}
	switch (plan)
	{
	case 0:
	{
		for (int i = middle.y - dif; i < middle.y + dif; ++i)
		{
			ys.push_back(i);
		}
		break;

	}
	case 1:
	{
		for (int i = middle.y - (roomSize / 6); i < middle.y + (roomSize / 6); ++i)
		{
			ys.push_back(i);
		}
		break;
	}
	case 2:
	{
		for (int i = middle.y - (roomSize / 6); i < middle.y + (roomSize / 6); ++i)
		{
			ys.push_back(i);
		}
		break;
	}
	case 3:
	{
		for (int i = middle.y - dif; i < middle.y + dif; ++i)
		{
			ys.push_back(i);
		}
		break;
	}
	default: break;
	}
	int y = rngFrom(ys);
	if (abs(xDif) > abs(yDif))
		return cords{ x,y };
	else
		return cords{ y,x };
}

bool myRoom::getWater() const noexcept
{
	return water;
}

void myRoom::rerollStart(const std::vector<cords>& taken)
{
	bool end = false;
	do
	{
		middle.x = rng(0,levelSize-1);
		middle.y = rng(0, levelSize - 1);
		for (int i = 0; i < taken.size(); ++i)
		{
			if (middle.x == taken[i].x && middle.y == taken[i].y)
				end = true;
			else
				end = false;
		}
	} while (end);
}

bool myRoom::checkFull(const std::vector<cords>& taken, const cords& cords0, const cords& cords1)
{
	for (int i = 0; i < taken.size(); ++i)
	{
		if (taken[i].x >= cords0.x - 1 && taken[i].x <= cords1.x + 1)
		{
			if (taken[i].y >= cords0.y - 1 && taken[i].y <= cords1.y + 1)
				return true;
		}
	}
	return false;
}

bool myRoom::searchByName(const std::string& toCheck)
{
	if (toCheck == getName())
		return true;
	else
		return false;
}
