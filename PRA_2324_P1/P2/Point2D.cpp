#include "Point2D.h"
#include <cmath>

using namespace std;

Point2D::Point2D(double x, double y){
	this->x = x;
	this->y = y;
}

static double Point2D::distance(const Point2D &a, const Point2D &b){
	return sqrt( pow( (a.x - b.x) , 2) + pow( (a.y - b.y) , 2) );
}

bool Point2D::operator==(const Point2D &other) const{
	
}

bool Point2D::operator!=(const Point2D &other) const{
	
}

ostream& operator<<(ostream &out, const Point2D &p){
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

