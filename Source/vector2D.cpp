#include "Vector2D.h"

Vector2D::Vector2D(float x , float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::~Vector2D()
{
}

float Vector2D::getMagnitude() const
{
	return sqrtf((x*x) + (y*y));
}

float Vector2D::distanceToPoint(Vector2D &point) const
{
	point.y -= y;
	point.x -= x;
	cout << point.x;
	cout << point.y;

	return point.getMagnitude();
}

float Vector2D::dotProduct(Vector2D &vector) const
{
	//vector 1 and vector 2. Times both X and Y together from each and add them together.
	return (x * vector.x) + (y * vector.y);

}