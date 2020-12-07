#pragma once
#include <vector>
#include <string>
#include "Point.h"

class BoardData
{
public:
	BoardData(unsigned int _w = 3, unsigned int _h = 3)
		: mapSize(_w, _h) {}
	void FloodMapWithTiles();
	void LoadFromFile(std::string _path); //TODO
	const unsigned int GetWidth() { return mapSize.X; }
	const unsigned int GetHeight() { return mapSize.Y; }
	Point GetSize() { return mapSize; }
	bool IsEmpty() { return mapData.empty(); };
	const std::vector<Point>& GetData() { return mapData; }

private:
	Point mapSize;
	std::vector<Point> mapData;
};

