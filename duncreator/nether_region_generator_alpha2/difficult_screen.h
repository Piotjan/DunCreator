#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

#include"scr_with_butt.h"

class difficultScr : public scrButton
{
public:
	difficultScr();
	void drawIt(sf::RenderWindow& window);
};