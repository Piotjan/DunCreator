#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<random>
#include<memory>
#include<algorithm>

#include"structures.h"
#include"segment.h"


class chamber
{
	std::vector<std::shared_ptr<segment>> groundPlan;
	std::string name;
public:
	chamber(const std::string& name);
	virtual ~chamber() {};
	virtual void rerollStart(const std::vector<cords>& taken) = 0;
	std::string getName() const;
	std::vector<cords> getCords() const;
	std::vector<std::shared_ptr<segment>> getSegments() const;
	void addSegment(std::weak_ptr<segment> a);
	bool setWalls(const cords toSet, std::vector<side> walls);
	int getSize() const noexcept;
	std::shared_ptr<segment> getSegment(const int i) const;
};





