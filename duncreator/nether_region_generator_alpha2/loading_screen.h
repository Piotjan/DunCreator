#pragma once
#include<string>
#include<SFML/Graphics.hpp>


//dlaczego klasa? W przysz�o�ci planuj� wy�wietla� r�nego rodzaju tekst, co �atwiej b�dzie realizowa� w klasie
class loadScr
{
public:
	loadScr();
	void drawIt(sf::RenderWindow& window);
};