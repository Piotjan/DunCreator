#pragma once
#include<iostream>

enum side
{
	north,
	east,
	south,
	west,
	none,
};

enum shape
{
	square,
	circle,
	cross,
	room
};

struct cords
{
	int x;
	int y;
};