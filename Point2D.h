#ifndef Point2D_H
#define Point2D_H
#include "Vector2D.h"
using namespace std;

class Point2D
{
    public:
    double x, y;
    
    Point2D(); //Default Constructor Prototype

    Point2D(double in_x, double in_y); //Constructor Prototype
};

double GetDistanceBetween(Point2D, Point2D); //GetDistanceBetween prototype

ostream& operator<< (ostream&, const Point2D&); //Overloaded insertion prototype

Point2D operator+ (const Point2D&, const Vector2D&); //Overloading addition prototype

Vector2D operator- (const Point2D&, const Point2D&); //Overloading subtraction prototype

#endif //Point2D_H