#pragma once
#include "Point2D.h"
#include <vector> 

class Space
{
public:
	Space();
	~Space();

	void setPosition(Point2D position);
	void setType(int type);

	int getType();

private:
	Point2D m_mapPosition;
};

