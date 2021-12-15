#pragma once
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include"scr_with_butt.h"

class withMapScr : public scrButton
{
public:
	withMapScr();
	void drawIt(sf::RenderWindow& window);
};