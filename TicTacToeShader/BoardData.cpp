#include "BoardData.h"

void BoardData::FloodMapWithTiles()
{
	mapData.clear();
	for (int _y = 0; _y < mapSize.Y; _y++)
	{
		for (int _x = 0; _x < mapSize.X; _x++)
		{
			mapData.push_back(Point(_x, _y));
		}
	}
}

void BoardData::LoadFromFile(std::string _path)
{
	//TODO!!!!
}
