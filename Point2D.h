#ifndef Point2D_H
#define Point2D_H
#include "Vector2D.h"
using namespace std;

class Point2D
{
    public:
    double x, y;
    
    Point2D() //Default Constructor
    {
        x = 0.0;
        y = 0.0;
    }

    Point2D(double in_x, double in_y) //Constructor
    {
        x = in_x;
        y = in_y;
    }
};

double GetDistanceBetween(Point2D, Point2D); //GetDistanceBetween prototype

ostream& operator<< (ostream&, const Point2D&); //Overloaded insertion prototype

Point2D operator+ (Point2D&, Vector2D&); //Overloading addition operator

Vector2D operator- (Point2D&, Point2D&); //Overloading subtraction operator

#endif //Point2D_H