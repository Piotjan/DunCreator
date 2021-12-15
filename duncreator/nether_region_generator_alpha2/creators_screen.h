#pragma once
#include<string>
#include<SFML/Graphics.hpp>

#include"scr_with_butt.h"

class creatorsScr : public scrButton
{
public:
	creatorsScr();
	void drawIt(sf::RenderWindow& window);
};