#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System/Vector2.hpp>
#include<SFML/Graphics/Color.hpp>
#include<SFML/Window/Mouse.hpp>

#include"structures.h"
#include"button.h"
#include"scr_with_butt.h"

class startScreen : public scrButton
{
public:
	startScreen();
	void drawIt(sf::RenderWindow& window);
};