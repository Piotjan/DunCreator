#pragma once
#include<string>
#include<SFML/Graphics.hpp>


//dlaczego klasa? W przysz³oœci planujê wyœwietlaæ ró¿nego rodzaju tekst, co ³atwiej bêdzie realizowaæ w klasie
class loadScr
{
public:
	loadScr();
	void drawIt(sf::RenderWindow& window);
};