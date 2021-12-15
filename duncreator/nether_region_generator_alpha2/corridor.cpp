#include"corridor.h"

corridor::corridor(const std::string& name, const std::string& firstName, const std::string& secondName, cords first, cords second) :
	chamber::chamber(name),
	first(firstName),
	second(secondName),
	possible1(first),
	possible2(second)
{
}


std::vector<cords> corridor::create()
{
	std::vector<cords> result;
	int y = possible1.y;
	int x = possible1.x;
	if (possible1.x > possible2.x)
	{
		for (x; x > possible2.x+1; --x)
		{
			std::shared_ptr<segment> ptr(new sCorridor(cords{ y,x }));
			this->addSegment(ptr);
			result.push_back(cords{ y,x });
		}
	}
	else
	{
		for (x; x < possible2.x-1; ++x)
		{
			std::shared_ptr<segment> ptr(new sCorridor(cords{ y,x }));
			this->addSegment(ptr);
			result.push_back(cords{ y,x });
		}
	}
	if (possible1.y > possible2.y)
	{
		for (y; y > possible2.y+1; --y)
		{
			std::shared_ptr<segment> ptr(new sCorridor(cords{ y,x }));
			this->addSegment(ptr);
			result.push_back(cords{ y,x });
		}
	}
	else
	{
		for (y; y < possible2.y-1; ++y)
		{
			std::shared_ptr<segment> ptr(new sCorridor(cords{ y,x }));
			this->addSegment(ptr);
			result.push_back(cords{ y,x });
		}
	}
	return result;
}

void corridor::rerollStart(const std::vector<cords>& taken)
{
}
