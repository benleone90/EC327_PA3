#include <iostream>
#include <cmath>
#include "Point2D.h"
using namespace std;

double GetDistanceBetween(Point2D p1, Point2D p2) //GetDistanceBetween function
{
    double distance = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    return distance;    
}

ostream& operator<< (ostream& out, const Point2D& obj) //Overloaded insertion operator
{
    out << "(" << obj.x << ", " << obj.y << ")" << endl;
    return out;
}

Point2D operator+ (Point2D& p1, Vector2D& v1) //Overloading addition operator
{
    Point2D p2;
    p2.x = (p1.x + v1.x);
    p2.y = (p1.y + v1.y);
    return p2;
}

Vector2D operator- (Point2D& p1, Point2D& p2) //Overloading subtraction operator
{
    Vector2D p3;
    p3.x = (p1.x - p2.x);
    p3.y = (p1.y - p2.y);
    return p3;
}