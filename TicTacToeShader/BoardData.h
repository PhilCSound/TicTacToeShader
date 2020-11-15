#pragma once
#include <vector>
#include <string>
#include "Point.h"

class BoardData
{
public:
	BoardData(unsigned int _w = 3, unsigned int _h = 3)
		: width(_w), height(_h) {}
	void FloodMapWithTiles();
	void LoadFromFile(std::string _path); //TODO
	const unsigned int GetWidth() { return width; }
	const unsigned int GetHeight() { return height; }
	const std::vector<Point>& GetData() { return mapData; }
private:
	unsigned int width;
	unsigned int height;
	std::vector<Point> mapData;
};

