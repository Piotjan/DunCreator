#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/System/Vector2.hpp>
#include<SFML/Window/Mouse.hpp>

#include"button.h"

class scrButton
{
	std::vector<Button> buttons;
	int SCRWIDTH;
	int SCRHEIGHT;
public:
	scrButton();
	virtual ~scrButton() {};
	void addButton(Button newBut);
	Button& getButton(const int which);
	int getSCRW() const;
	int getSCRH() const;
	int getButAmount() const;
	//int checkChoose(sf::RenderWindow& window);
	int checkChoose(sf::Event event);

	virtual void drawIt(sf::RenderWindow& window) = 0;
};