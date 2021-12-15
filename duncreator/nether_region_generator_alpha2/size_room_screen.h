#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

#include"scr_with_butt.h"

class sizeRoomScr : public scrButton
{
public:
	sizeRoomScr();
	void drawIt(sf::RenderWindow& window);
};
