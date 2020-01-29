#include "pch.h"
#include "Space.h"
#include <iostream>

Space::Space() : m_type{EMPTY}, m_mapPosition{ 0, 0 }
{
}

Space::~Space()
{
}

void Space::setPosition(Point2D position)
{
	m_mapPosition = position;
}

void Space::setType(int type)
{
	m_type = type;
}

int Space::getType()
{
	return m_type;
}

void Space::draw()
{
	switch (m_type)
	{
	case EMPTY:
		std::cout << EMPTY_TILE;
		break;
	case PLAYER1:
		std::cout << PLAYER1_TILE;
		break;
	case PLAYER2:
		std::cout << PLAYER2_TILE;
		break;
	}
}
