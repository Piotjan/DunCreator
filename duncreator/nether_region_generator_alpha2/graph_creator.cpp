#include"graph_creator.h"

graphCreator::graphCreator(level* _level) :
	graphicsName::graphicsName(),
	levelToCreate(_level),
	SCRWIDTH(sf::VideoMode::getDesktopMode().width),
	SCRHEIGHT(sf::VideoMode::getDesktopMode().height)
{
}

bool graphCreator::createMap(sf::RenderWindow& window) noexcept
{
	window.clear();
	std::vector<cords> taken = levelToCreate->getTaken();
	pixelRatio = this->getResolution();
	int smaller = std::min(SCRWIDTH, SCRHEIGHT);
	while (smaller / pixelRatio < levelToCreate->getSize())
	{
		--pixelRatio;
	}
	--pixelRatio;

	sf::Texture texture;
	texture.loadFromFile(this->getGround(0));
	sf::Vector2i segmentSize(pixelRatio, pixelRatio);
	sf::Vector2i segmentLocation(0, 0);
	sf::IntRect toCut(segmentLocation, segmentSize);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(toCut);
	std::vector<cords> toDraw(levelToCreate->getTaken());
	for (int i = 0; i < toDraw.size(); ++i)
	{
		sf::Vector2f position (toDraw[i].x * pixelRatio, toDraw[i].y * pixelRatio);
		sprite.setPosition(position);
		window.draw(sprite);
	}
	auto forNext = this->drawWater(window);
	this->drawDecorations(window, forNext);
	this->drawChests(window);
	this->drawEnemies(window);

	this->drawWallsCor(window);
	this->drawWallsRom(window);

	return true;
}

void graphCreator::drawFloorRoom(const sf::RenderWindow& window, const std::vector<cords>& taken) noexcept
{
	for (int i = 0; i < taken.size(); ++i)
	{
	}
}

std::vector<cords> graphCreator::drawWater(sf::RenderWindow& window)
{
	std::vector<cords> positions;
	auto rooms = levelToCreate->getRooms();
	for (int i = 0; i < rooms.getSize(); ++i)
	{
		if (rooms.getRoom(i).getWater())
		{
			int start = rng(0, rooms.getRoom(i).getCords().size() - 1);
			positions = this->setDeepWater(rooms.getRoom(i).getCords()[start]);

			sf::Texture tDeepWater;
			tDeepWater.loadFromFile(this->getDeep(0));
			sf::Sprite sDeepWater;
			sDeepWater.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
			sDeepWater.setTexture(tDeepWater);
			for (int j = 0; j < positions.size(); ++j)
			{
				sDeepWater.setPosition(sf::Vector2f(positions[j].x * pixelRatio, positions[j].y * pixelRatio));
				window.draw(sDeepWater);
			}

			sf::Texture tPuddleWater;
			tPuddleWater.loadFromFile(this->getPuddle(0));
			sf::Sprite sPuddleWater;
			sPuddleWater.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
			sPuddleWater.setTexture(tPuddleWater);
			auto pudPositions = this->setPuddleWater(positions);
			for (int j = 0; j < pudPositions.size(); ++j)
			{
				sPuddleWater.setPosition(sf::Vector2f(pudPositions[j].x * pixelRatio, pudPositions[j].y * pixelRatio));
				window.draw(sPuddleWater);
			}
		}
	}
	return positions;
}

void graphCreator::drawWallsCor(sf::RenderWindow& window)
{
	for (int i = 0; i < levelToCreate->getCorridors().getSize(); ++i)
	{
		for (int j = 0; j < levelToCreate->getCorridors().getCorridor(i).getSize(); ++j)
		{
			cords current = levelToCreate->getCorridors().getCorridor(i).getSegment(j)->getCords();
			std::vector<side> whereWalls(levelToCreate->getCorridors().getCorridor(i).getSegment(j)->getWalls());
			if (whereWalls.size() != 0)
			{
				sf::Vector2f position(current.x * pixelRatio, current.y * pixelRatio);
				sf::Texture tWall;
				sf::Sprite sWall;
				sWall.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
				sWall.setPosition(position);
				if (this->wallSetGraphic(tWall, whereWalls, 0))
				{
					sWall.setTexture(tWall);
					window.draw(sWall);
				}
			}
		}
	}
}

void graphCreator::drawWallsRom(sf::RenderWindow& window)
{
	for (int i = 0; i < levelToCreate->getRooms().getSize(); ++i)
	{
		for (int j = 0; j < levelToCreate->getRooms().getRoom(i).getSize(); ++j)
		{
			cords current = levelToCreate->getRooms().getRoom(i).getSegment(j)->getCords();
			std::vector<side> whereWalls(levelToCreate->getRooms().getRoom(i).getSegment(j)->getWalls());
			if (whereWalls.size() != 0)
			{
				sf::Vector2f position(current.x * pixelRatio, current.y * pixelRatio);
				sf::Texture tWall;
				sf::Sprite sWall;
				sWall.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
				sWall.setPosition(position);
				if (this->wallSetGraphic(tWall, whereWalls, 0))
				{
					sWall.setTexture(tWall);
					window.draw(sWall);
				}
			}
		}
	}
}

sf::Vector2f graphCreator::setResize() const noexcept
{
	float scaler = 0.9;
	int screenX = sf::VideoMode::getDesktopMode().width;
	int screenY = sf::VideoMode::getDesktopMode().height;
	bool toEnd = true;
	do
	{
		if (this->getResolution() * scaler * levelToCreate->getSize() > screenX || this->getResolution() * scaler * levelToCreate->getSize() > screenY)
			scaler -= 0.1;
		else
			toEnd = false;
	} while (scaler > 0.1 && toEnd);
	sf::Vector2f result(scaler, scaler);
	return result;
}

bool graphCreator::wallSetGraphic(sf::Texture& tWall, const std::vector<side>& whereWalls, const int whichTexture)
{
	bool ifDraw = true;
	switch (whereWalls[0])
	{
	case 0: //N
	{
		switch (whereWalls[1])
		{
		case 0: break; //NN
		case 1: //NE
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: break;
			case 2: tWall.loadFromFile(this->getTripleNSE(whichTexture)); break; //testura NSE
			case 3: tWall.loadFromFile(this->getTripleNEW(whichTexture)); break; //tesktura NEW
			case 4: tWall.loadFromFile(this->getDoubleNE(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 2: //NS
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: tWall.loadFromFile(this->getTripleNSE(whichTexture)); break; //tesktura NSE
			case 2: break;
			case 3: tWall.loadFromFile(this->getTripleNSW(whichTexture)); break; //tekstura NSW
			case 4: tWall.loadFromFile(this->getDoubleNS(whichTexture));  break; //tekstura NS
			default: break;
			}
			break;
		}
		case 3: //NW
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: tWall.loadFromFile(this->getTripleNEW(whichTexture)); break; //tekstura NEW
			case 2:  tWall.loadFromFile(this->getTripleNSW(whichTexture)); break; //tekstura NSW
			case 3: break;
			case 4: tWall.loadFromFile(this->getDoubleNW(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 4: //N
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: tWall.loadFromFile(this->getDoubleNE(whichTexture)); break;
			case 2: tWall.loadFromFile(this->getDoubleNS(whichTexture)); break; //tesktura NS
			case 3: tWall.loadFromFile(this->getDoubleNW(whichTexture)); break;
			case 4: tWall.loadFromFile(this->getWallN(whichTexture)); break;
			default: break;
			}
			break;
		}
		default: break;
		}
		break;
	}
	case 1: //E
	{
		switch (whereWalls[1])
		{
		case 0: //EN
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: break;
			case 2: tWall.loadFromFile(this->getTripleNSE(whichTexture)); break; //tekstura NES
			case 3: tWall.loadFromFile(this->getTripleNEW(whichTexture)); break; //tekstura ENW
			case 4: tWall.loadFromFile(this->getDoubleNE(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 1: break; //EE
		case 2: //ES
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getTripleNSE(whichTexture)); break; //tekstura ESN
			case 1: break;
			case 2: break;
			case 3: tWall.loadFromFile(this->getTripleSEW(whichTexture)); break; //tekstura ESW
			case 4: tWall.loadFromFile(this->getDoubleSE(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 3: //EW
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getTripleNEW(whichTexture)); break; //tekstura EWN
			case 1: break;
			case 2: tWall.loadFromFile(this->getTripleSEW(whichTexture)); break; //tekstura EWS
			case 3: break;
			case 4: tWall.loadFromFile(this->getDoubleEW(whichTexture)); break; //tekstura EW
			default: break;
			}
			break;
		}
		case 4: //E
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getDoubleNE(whichTexture)); break;
			case 1: break;
			case 2: tWall.loadFromFile(this->getDoubleSE(whichTexture)); break;
			case 3: tWall.loadFromFile(this->getDoubleEW(whichTexture)); break; //tekstura EW
			case 4: tWall.loadFromFile(this->getWallE(whichTexture)); break;
			default: break;
			}
			break;
		}
		default: break;
		}
		break;
	}
	case 2: //S
	{
		switch (whereWalls[1])
		{
		case 0: //SN
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: tWall.loadFromFile(this->getTripleNSE(whichTexture)); break; //tekstura SNE
			case 2: break;
			case 3: tWall.loadFromFile(this->getTripleNSW(whichTexture)); break; //tekstura SNW
			case 4: tWall.loadFromFile(this->getDoubleNS(whichTexture)); break; //tekstura SN
			default: break;
			}
			break;
		}
		case 1: //SE
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getTripleNSE(whichTexture)); break; //tekstura SEN
			case 1: break;
			case 2: break;
			case 3: tWall.loadFromFile(this->getTripleSEW(whichTexture)); break; //tekstura SEW
			case 4: tWall.loadFromFile(this->getDoubleSE(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 2: break;
		case 3: //SW
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getTripleNSW(whichTexture)); break; //telstura SWN
			case 1: tWall.loadFromFile(this->getTripleSEW(whichTexture)); break; //texture SWE
			case 2: break;
			case 3: break;
			case 4: tWall.loadFromFile(this->getDoubleSW(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 4: //S
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getDoubleNS(whichTexture)); break; //texture SN
			case 1: tWall.loadFromFile(this->getDoubleSE(whichTexture)); break;
			case 2: break;
			case 3: tWall.loadFromFile(this->getDoubleSW(whichTexture)); break;
			case 4: tWall.loadFromFile(this->getWallS(whichTexture)); break;
			default: break;
			}
			break;
		}
		default: break;
		}
		break;
	}
	case 3: //W
	{
		switch (whereWalls[1])
		{
		case 0: //WN
		{
			switch (whereWalls[2])
			{
			case 0: break;
			case 1: tWall.loadFromFile(this->getTripleNEW(whichTexture)); break; //tekstura WNE
			case 2: tWall.loadFromFile(this->getTripleNSW(whichTexture)); break; //tekstura WNS
			case 3: break;
			case 4: tWall.loadFromFile(this->getDoubleNW(whichTexture));
			default: break;
			}
			break;
		}
		case 1: //WE
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getTripleNEW(whichTexture)); break; //tekstura WEN
			case 1: break;
			case 2: tWall.loadFromFile(this->getTripleSEW(whichTexture)); break; //tekstura WES
			case 3: break;
			case 4: tWall.loadFromFile(this->getDoubleEW(whichTexture)); break; //tekstura WE
			default: break;
			}
			break;
		}
		case 2: //WS
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getTripleNSW(whichTexture)); break; //tekstura WSN
			case 1: tWall.loadFromFile(this->getTripleSEW(whichTexture)); break; //tekstura WSE
			case 2: break;
			case 3: break;
			case 4: tWall.loadFromFile(this->getDoubleSW(whichTexture)); break;
			default: break;
			}
			break;
		}
		case 3: break;
		case 4: //W
		{
			switch (whereWalls[2])
			{
			case 0: tWall.loadFromFile(this->getDoubleNW(whichTexture)); break;
			case 1: tWall.loadFromFile(this->getDoubleEW(whichTexture)); break; // tekstura WE
			case 2: tWall.loadFromFile(this->getDoubleSW(whichTexture)); break;
			case 3: break;
			case 4: tWall.loadFromFile(this->getWallW(whichTexture)); break;
			default: break;
			}
			break;
		}
		default: break;
		}
		break;
	}
	case 4:
	{
		if (whereWalls[1] == none && whereWalls[2] == none)
			ifDraw = false;
		break;
	}
	default: break;
	}

	return ifDraw;
}

std::vector<cords> graphCreator::setDeepWater(const cords startCords)
{
	std::vector<cords> used;
	auto current = startCords;
	used.push_back(current);
	bool toEnd = true;
	std::vector<cords> possible;
	auto taken = levelToCreate->getTaken();
	for (int i = 0; i < taken.size(); ++i)
	{
		if (isItNeigh(taken[i], current))
		{
			bool isUsed = true;
			for (int j = 0; j < used.size(); ++j)
			{
				if (taken[i].x == used[j].x && taken[i].y == used[j].y)
					isUsed = false;
			}
			if (isUsed)
				possible.push_back(taken[i]);
		}
	}
	for (int i = 0; i < possible.size(); ++i)
	{
		if (rngProb(0.5))
			used.push_back(possible[i]);
	}
	possible.clear();
	for (int k = 0; k < used.size(); ++k)
	{
		current = used[k];
		for (int i = 0; i < taken.size(); ++i)
		{
			if (isItNeigh(taken[i], current))
			{
				bool isUsed = true;
				for (int j = 0; j < used.size(); ++j)
				{
					if (taken[i].x == used[j].x && taken[i].y == used[j].y)
						isUsed = false;
				}
				if (isUsed)
					possible.push_back(taken[i]);
			}
		}
	}
	for (int i = 0; i < possible.size(); ++i)
	{
		if (rngProb(0.25))
			used.push_back(possible[i]);
	}
	return used;
}

std::vector<cords> graphCreator::setPuddleWater(const std::vector<cords>& deep)
{
	std::vector<cords> used(deep);
	std::vector<cords> result;
	std::vector<cords> news(deep);
	std::vector<cords> current;
	auto taken = levelToCreate->getTaken();
	do
	{
		current = std::move(news);
		for (int i = 0; i < current.size(); ++i)
		{
			for (int j = 0; j < taken.size(); ++j)
			{
				if (isItNeigh(current[i], taken[j]))
				{
					bool add = true;
					for (int k = 0; k < used.size(); ++k)
					{
						if (taken[j].x == used[k].x && taken[j].y == used[k].y)
							add = false;
					}
					if (add)
					{
						if (rngProb(0.5))
						{
							used.push_back(taken[j]);
							result.push_back(taken[j]);
							news.push_back(taken[j]);
						}
					}
				}
			}
		}
	} while (news.size());
	return result;
}

std::vector<cords> graphCreator::drawChests(sf::RenderWindow& window)
{
	std::vector<cords> result;
	for (int i = 0; i < levelToCreate->getRoomsAmount(); ++i)
	{
		for (int j = 0; j < levelToCreate->getRooms().getRoom(i).getSize(); ++j)
		{
			auto chest = levelToCreate->getRooms().getRoom(i).getSegment(j)->getChests();
			if (chest)
			{
				sf::Texture tChest;
				tChest.loadFromFile(this->getChest(chest - 1));
				sf::Sprite sChest;
				sChest.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
				sChest.setTexture(tChest);
				auto position = levelToCreate->getRooms().getRoom(i).getSegment(j)->getCords();
				sChest.setPosition(sf::Vector2f(position.x * pixelRatio, position.y * pixelRatio));
				window.draw(sChest);
				result.push_back(position);
			}
		}
	}
	return result;
}

void graphCreator::drawEnemies(sf::RenderWindow& window)
{
	for (int i = 0; i < levelToCreate->getRoomsAmount(); ++i)
	{
		for (int j = 0; j < levelToCreate->getRooms().getRoom(i).getSize(); ++j)
		{
			auto enemies = levelToCreate->getRooms().getRoom(i).getSegment(j)->getEnemy();
			if (enemies)
			{
				sf::Texture tEnemy;
				tEnemy.loadFromFile(this->getEnemy(enemies - 1));
				sf::Sprite sEnemy;
				sEnemy.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
				sEnemy.setTexture(tEnemy);
				auto position = levelToCreate->getRooms().getRoom(i).getSegment(j)->getCords();
				sEnemy.setPosition(sf::Vector2f(position.x * pixelRatio, position.y * pixelRatio));
				window.draw(sEnemy);
			}
		}
	}
}

void graphCreator::drawDecorations(sf::RenderWindow& window, const std::vector<cords>& water)
{
	for (int i = 0; i < levelToCreate->getRoomsAmount(); ++i)
	{
		auto current = levelToCreate->getRooms().getRoom(i).getCords();
		for (int j = 0; j < current.size(); ++j)
		{
			bool add = true;
			for (int k = 0; k < water.size(); ++k)
			{
				if (current[j].x == water[k].x && current[j].y == water[k].y)
					add = false;
			}
			auto taken = levelToCreate->getTaken();
			if (add)
			{
				add = false;
				for (int k = 0; k < taken.size(); ++k)
				{
					if (current[j].x == taken[k].x && current[j].y == taken[k].y)
						add = true;
				}
				if (add)
				{
					if (rngProb(0.01))
					{
						sf::Texture tDecoration;
						tDecoration.loadFromFile(this->getDecoration(0));
						sf::Sprite sDecoration;
						sDecoration.setScale(pixelRatio * 1.0 / 64, pixelRatio * 1.0 / 64);
						sDecoration.setTexture(tDecoration);
						sf::Vector2f position(current[j].x * pixelRatio, current[j].y * pixelRatio);
						if (rngProb(0.5))
						{
							sDecoration.setRotation(90);
							position.x += pixelRatio;
						}
						sDecoration.setPosition(position);
						window.draw(sDecoration);
					}
				}
			}
		}
	}
}

bool graphCreator::isItNeigh(const cords& a, const cords& b)
{
	if (a.x + 1 == b.x && a.y == b.y)
		return true;
	else if (a.x - 1 == b.x && a.y == b.y)
		return true;
	else if (a.x == b.x && a.y + 1 == b.y)
		return true;
	else if (a.x == b.x && a.y - 1 == b.y)
		return true;
	else
		return false;
}
