#include"graphic_name.h"

graphicsName::graphicsName()
{
	std::ifstream file;
	file.open("graphic/graph_elements.txt");
	char buffer[2048];
	std::vector<std::vector<std::string>> toPush;
	int line = 0;
	while (file.getline(buffer, sizeof(buffer)))
	{
		std::stringstream stream(buffer);
		stream.getline(buffer, sizeof(buffer), ';');
		std::vector<std::string> v;
		while (stream.getline(buffer, sizeof(buffer), ';'))
		{
			v.push_back(buffer);
		}
		toPush.push_back(v);
		++line;
	}
	file.close();
	line = 0;
	resolution = std::stoi(toPush[line][0]);
	++line;
	ground = std::move(toPush[line]);
	++line;
	wallN = std::move(toPush[line]);
	++line;
	wallE = std::move(toPush[line]);
	++line;
	wallS = std::move(toPush[line]);
	++line;
	wallW = std::move(toPush[line]);
	++line;
	doubleNE = std::move(toPush[line]);
	++line;
	doubleSE = std::move(toPush[line]);
	++line;
	doubleSW = std::move(toPush[line]);
	++line;
	doubleNW = std::move(toPush[line]);
	++line;
	doubleNS = std::move(toPush[line]);
	++line;
	doubleEW = std::move(toPush[line]);
	++line;
	tripleNEW = std::move(toPush[line]);
	++line;
	tripleNSE = std::move(toPush[line]);
	++line;
	tripleNSW = std::move(toPush[line]);
	++line;
	tripleSEW = std::move(toPush[line]);
	++line;
	cornerNE = std::move(toPush[line]);
	++line;
	cornerSE = std::move(toPush[line]);
	++line;
	cornerSW = std::move(toPush[line]);
	++line;
	cornerNW = std::move(toPush[line]);
	++line;
	deep = std::move(toPush[line]);
	++line;
	puddle = std::move(toPush[line]);
	++line;
	decorations = std::move(toPush[line]);
	++line;
	enemies = std::move(toPush[line]);
	++line;
	chests = std::move(toPush[line]);
}

int graphicsName::getResolution() const
{
	return resolution;
}

std::string graphicsName::getGround(const int which) const
{
	return ground[which];
}

std::string graphicsName::getWallN(const int which) const
{
	return wallN[which];
}

std::string graphicsName::getWallE(const int which) const
{
	return wallE[which];
}

std::string graphicsName::getWallS(const int which) const
{
	return wallS[which];
}

std::string graphicsName::getWallW(const int which) const
{
	return wallW[which];
}

std::string graphicsName::getDoubleNE(const int which) const
{
	return doubleNE[which];
}

std::string graphicsName::getDoubleSE(const int which) const
{
	return doubleSE[which];
}

std::string graphicsName::getDoubleSW(const int which) const
{
	return doubleSW[which];
}

std::string graphicsName::getDoubleNW(const int which) const
{
	return doubleNW[which];
}

std::string graphicsName::getDoubleNS(const int which) const
{
	return doubleNS[which];
}

std::string graphicsName::getDoubleEW(const int which) const
{
	return doubleEW[which];
}

std::string graphicsName::getTripleNEW(const int which) const
{
	return tripleNEW[which];
}

std::string graphicsName::getTripleNSE(const int which) const
{
	return tripleNSE[which];
}

std::string graphicsName::getTripleNSW(const int which) const
{
	return tripleNSW[which];
}

std::string graphicsName::getTripleSEW(const int which) const
{
	return tripleSEW[which];
}

std::string graphicsName::getCornerNE(const int which) const
{
	return cornerNE[which];
}

std::string graphicsName::getCornerSE(const int which) const
{
	return cornerSE[which];
}

std::string graphicsName::getCornerSW(const int which) const
{
	return cornerSW[which];
}

std::string graphicsName::getCornerNW(const int which) const
{
	return cornerNW[which];
}

std::string graphicsName::getDeep(const int which) const
{
	return deep[which];
}

std::string graphicsName::getPuddle(const int which) const
{
	return puddle[which];
}

std::string graphicsName::getDecoration(const int which) const
{
	return decorations[which];
}

std::string graphicsName::getChest(const int which) const
{
	return chests[which];
}

std::string graphicsName::getEnemy(const int which) const
{
	return enemies[which];
}
