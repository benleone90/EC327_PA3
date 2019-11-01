#ifndef Point2D_H
#define Point2D_H

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

#endif