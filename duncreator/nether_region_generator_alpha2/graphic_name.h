#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

class graphicsName
{
	int resolution;
	std::vector<std::string> ground;
	std::vector<std::string> wallN;
	std::vector<std::string> wallE;
	std::vector<std::string> wallS;
	std::vector<std::string> wallW;
	std::vector<std::string> doubleNE;
	std::vector<std::string> doubleSE;
	std::vector<std::string> doubleSW;
	std::vector<std::string> doubleNW;
	std::vector<std::string> doubleNS;
	std::vector<std::string> doubleEW;
	std::vector<std::string> tripleNEW;
	std::vector<std::string> tripleNSE;
	std::vector<std::string> tripleNSW;
	std::vector<std::string> tripleSEW;
	std::vector<std::string> cornerNE;
	std::vector<std::string> cornerSE;
	std::vector<std::string> cornerSW;
	std::vector<std::string> cornerNW;
	std::vector<std::string> deep;
	std::vector<std::string> puddle;
	std::vector<std::string> decorations;
	std::vector<std::string> enemies;
	std::vector<std::string> chests;
public:
	graphicsName();
	virtual ~graphicsName() {};
	int getResolution() const;
	std::string getGround(const int which) const;
	std::string getWallN(const int which) const;
	std::string getWallE(const int which) const;
	std::string getWallS(const int which) const;
	std::string getWallW(const int which) const;
	std::string getDoubleNE(const int which) const;
	std::string getDoubleSE(const int which) const;
	std::string getDoubleSW(const int which) const;
	std::string getDoubleNW(const int which) const;
	std::string getDoubleNS(const int which) const;
	std::string getDoubleEW(const int which) const;
	std::string getTripleNEW(const int which) const;
	std::string getTripleNSE(const int which) const;
	std::string getTripleNSW(const int which) const;
	std::string getTripleSEW(const int which) const;
	std::string getCornerNE(const int which) const;
	std::string getCornerSE(const int which) const;
	std::string getCornerSW(const int which) const;
	std::string getCornerNW(const int which) const;
	std::string getDeep(const int which) const;
	std::string getPuddle(const int which) const;
	std::string getDecoration(const int which) const;
	std::string getChest(const int which) const;
	std::string getEnemy(const int which) const;
};