#include "Point.h"

const Point Point::North = Point(0, 1);
const Point Point::NorthEast = Point(1, 1);
const Point Point::East = Point(1, 0);
const Point Point::SouthEast = Point(1, -1);
const Point Point::South = Point(0, -1);
const Point Point::SouthWest = Point(-1, -1);
const Point Point::West = Point(-1, 0);
const Point Point::NorthWest = Point(-1, 1);

Point::Point()
	: X(0), Y(0)
{
}

Point::Point(int _x, int _y)
	: X(_x), Y(_y)
{
}

Point Point::operator+(const Point & rhs)
{
	return Point((this->X + rhs.X), (this->Y + rhs.Y));
}

Point & Point::operator+=(const Point & rhs)
{
	this->X = this->X + rhs.X;
	this->Y = this->Y + rhs.Y;
	return *this;
}

Point Point::operator-(const Point & rhs)
{
	return Point((this->X - rhs.X), (this->Y - rhs.Y));
}

Point & Point::operator-=(const Point & rhs)
{
	this->X = this->X - rhs.X;
	this->Y = this->Y - rhs.Y;
	return *this;
}

Point Point::operator*(const int & _scale)
{
	return Point((this->X * _scale), (this->Y * _scale));

}

Point & Point::operator*=(const int & _scale)
{
	this->X = this->X * _scale;
	this->Y = this->Y * _scale;
	return *this;
}

Point Point::operator*(const Point & rhs)
{
	return Point((this->X * rhs.X), (this->Y * rhs.Y));

}

Point & Point::operator*=(const Point & rhs)
{
	this->X = this->X * rhs.X;
	this->Y = this->Y * rhs.Y;
	return *this;
}

bool Point::operator==(const Point & rhs)
{
	if ((this->X == rhs.X) && (this->Y == rhs.Y))
		return true;
	return false;
}


//TODO: REFRESH ON OVERLOADING OPERATORS WHY DO I MAKE THIS A FRIEND CLASS AGAIN?
bool operator<(const Point & lhs ,const Point & rhs)
{
	if (lhs.X < rhs.X)
		return true;
	else if (lhs.X == rhs.X)
		return (lhs.Y < rhs.Y);
	return false;
}

bool Point::operator>(const Point & rhs)
{
	return !(*this < rhs);
}

bool Point::operator<=(const Point & rhs)
{
	return ((*this < rhs) && (*this == rhs));
}

bool Point::operator>=(const Point & rhs)
{
	return !(*this <= rhs);
}

