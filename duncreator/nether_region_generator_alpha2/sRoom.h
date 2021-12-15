#pragma once
#include<iostream>
#include<vector>
#include<string>

#include"structures.h"
#include"segment.h"
#include"rand.hpp"

class sRoom : public segment
{
public:
	sRoom(cords cords);
	//void setDoor(side door);
};