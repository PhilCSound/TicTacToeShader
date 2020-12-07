#pragma once
#include <vector>
#include <string>
#include "SFML/System.hpp"
#include "Point.h"

class BoardData
{
public:
	BoardData(unsigned int _w = 3, unsigned int _h = 3)
		: mapSize(_w, _h) {}
	void FloodMapWithTiles();
	void LoadFromFile(std::string _path); //TODO
	const unsigned int &GetWidth() { return mapSize.x; }
	const unsigned int &GetHeight() { return mapSize.y; }
	sf::Vector2i GetMapSize() { return mapSize; }
	const std::vector<Point> &GetData() { return mapData; }

private:
	sf::Vector2i mapSize;
	std::vector<Point> mapData;
};