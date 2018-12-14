#pragma once
#include "utils.h"

class Waypoint
{
public:
	MathX::Vector2 Point;

	void Debug()
	{
		DrawCircleLines(Point.X, Point.Y, 10, GREEN);
	};

	Waypoint();
	Waypoint(float a, float b);
	~Waypoint();
};

Waypoint::Waypoint() { }
Waypoint::Waypoint(float a, float b) { Point.X = a; Point.Y = b; }
Waypoint::~Waypoint() { }