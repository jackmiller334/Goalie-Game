#ifndef AABB_H
#define AABB_H
#include "vector2D.h"

class AABB
{
public:
	AABB();
	~AABB();

	float minX;
	float maxX;
	float minY;
	float maxY;

	bool collidesWith(AABB &aabb);
};

#endif