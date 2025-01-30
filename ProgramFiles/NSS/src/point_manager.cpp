#include "point_manager.h"
#include  <cmath>

double PointManager::get_distance(Point& a, Point& b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool PointManager::equal(Point& a, Point& b) {
	return a.x == b.x and a.y == b.y;
}