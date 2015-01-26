#ifndef _VECTOR2D_
#define _VECTOR2D_

#include <math.h>
#include <iostream>
using namespace std;
class Vector2D
{
public:

	Vector2D(float x = 0, float y  = 0);
	~Vector2D();

	void reset();
	//X co-ordinate of Vector
	float x;

	//Y co-ordinate of Vector
	float y;


	float getMagnitude() const;

	//finds the distance between two points in cartesian space. 
	float distanceToPoint(Vector2D &point) const;

	//dot
	float dotProduct(Vector2D &vector) const;
	//cross
	//operator overloads
	//getters and setters
private:

	

protected:

};

#endif