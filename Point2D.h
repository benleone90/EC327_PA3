#ifndef Point2D_H
#define Point2D_H
#include <cmath>

class Point2D
{
    public:
    double x, y;

    Point2D()
    {
        x = 0.0;
        y = 0.0;
    }

    Point2D(double in_x, double in_y)
    {
        x = in_x;
        y = in_y;
    }
};

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

ostream& operator <<(ostream& out, const Point2D& Point2D)
{
    out << (Point2D.x, Point2D.y) << endl;
    return out;
}

#endif