#pragma once

class Point
{
public:
	Point();
	Point(int _x, int _y);
	int X;
	int Y;

	//TODO: Define Operators..
	Point operator+(const Point &rhs);
	Point& operator+=(const Point &rhs);
	Point operator-(const Point &rhs);
	Point& operator-=(const Point &rhs);
	Point operator*(const int &_scale);
	Point& operator*=(const int &_scale);
	Point operator*(const Point &rhs);
	Point& operator*=(const Point &rhs);
	bool operator==(const Point &rhs);
	friend bool operator<(const Point &lhs, const Point &rhs);
	bool operator>(const Point &rhs);
	bool operator<=(const Point &rhs);
	bool operator>=(const Point &rhs);

	//Defined Constants below.
	static const Point North;
	static const Point NorthEast;
	static const Point East;
	static const Point SouthEast;
	static const Point South;
	static const Point SouthWest;
	static const Point West;
	static const Point NorthWest;
};

const Point North(0,1);
const Point NorthEast(1,1);
const Point East(1,0);
const Point SouthEast(1,-1);
const Point South(0,-1);
const Point SouthWest(-1,-1);
const Point West(-1,0);
const Point NorthWest(-1,1);