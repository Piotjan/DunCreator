#pragma once
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/System/Vector2.hpp>
#include<SFML/Graphics/Text.hpp>

class Button
{
	sf::Vector2i position;
	sf::Vector2i size;
	sf::Vector2i end;
	std::string text;
	sf::Text myText;
	std::string fontName;
	double yPos;
public:
	Button(sf::Vector2i _position, std::string _text);
	Button(const float _yPos, std::string _text, int SCRWIDTH, int SCRHEIGHT);
	sf::Vector2i getPosition() const noexcept;
	sf::Vector2i getEnd() const noexcept;
	void draw(sf::RenderWindow& window);
	bool isClicked(sf::Vector2f mouse) const noexcept;
};