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