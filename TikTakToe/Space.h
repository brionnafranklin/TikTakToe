#pragma once
#include "Point2D.h"
#include <vector> 
#include "GameDefines.h"

class Space
{
public:
	Space();
	~Space();

	void setPosition(Point2D position);
	void setType(int type);

	int getType();

	void draw();

private:
	Point2D m_mapPosition;

	int m_type;
};

