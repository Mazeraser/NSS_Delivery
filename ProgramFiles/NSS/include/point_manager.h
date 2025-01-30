#pragma once
#include "point.h"

struct PointManager {
	static double get_distance(abstracts::Point& a, abstracts::Point& b);
	static bool equal(Point& a, abstracts::Point& b);
	static Point new_point(abstracts::Point& a, abstracts::Point& b, double speed_kmh); 
}