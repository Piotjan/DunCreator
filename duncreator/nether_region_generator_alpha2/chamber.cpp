#include"chamber.h"

chamber::chamber(const std::string& name) : name(name)
{
}

std::string chamber::getName() const
{
	return name;
}

std::vector<cords> chamber::getCords() const
{
	std::vector<cords> result;
	for (int i = 0; i < groundPlan.size(); ++i)
	{
		result.push_back(groundPlan[i]->getCords());
	}
	return result;
}

std::vector<std::shared_ptr<segment>> chamber::getSegments() const
{
	return groundPlan;
}

void chamber::addSegment(std::weak_ptr<segment> a)
{
	groundPlan.push_back(std::shared_ptr<segment>(a));
}

bool chamber::setWalls(const cords toSet, std::vector<side> walls)
{
	for (int i = 0; i < groundPlan.size(); ++i)
	{
		if (toSet.x == groundPlan[i]->getCords().x && toSet.y == groundPlan[i]->getCords().y)
		{
			groundPlan[i]->setWalls(walls);
			return true;
		}
	}
	return false;
}

int chamber::getSize() const noexcept
{
	return groundPlan.size();
}

std::shared_ptr<segment> chamber::getSegment(const int i) const
{
	return groundPlan[i];
}