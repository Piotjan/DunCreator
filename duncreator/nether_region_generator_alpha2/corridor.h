#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<random>
#include<memory>

#include"structures.h"
#include"sCorridor.h"
#include"chamber.h"

class corridor : public chamber
{
	std::string first;
	std::string second;
	cords possible1;
	cords possible2;
public:
	corridor(const std::string& name, const std::string& firstName, const std::string& secondName, cords first, cords second);
	std::vector<cords> create();
	void rerollStart(const std::vector<cords>& taken);
};