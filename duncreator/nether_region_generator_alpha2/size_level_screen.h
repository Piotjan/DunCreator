#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

#include"scr_with_butt.h"

class sizeLeveScr : public scrButton
{
public:
	sizeLeveScr();
	void drawIt(sf::RenderWindow& window);
};