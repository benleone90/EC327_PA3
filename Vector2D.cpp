#include <iostream>
#include "Vector2D.h"
using namespace std;

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y) //Constructor Definition
{
    x = in_x;
    y = in_y;
} 

ostream& operator<< (ostream& out, const Vector2D& obj) //Overloaded insertion operator
{
    out << "<" << obj.x << ", " << obj.y << ">";
    return out;
}

Vector2D operator* (Vector2D& v1, double d) //Overloaded multiplication operator
{
    Vector2D p3;
    p3.x = (v1.x * d);
    p3.y = (v1.y * d);
    return p3;
}

Vector2D operator/ (Vector2D& v1, double d) //Overloaded division operator
{
    if (d == 0)
    {
        return v1;
    } else
    {
        Vector2D p3;
        p3.x = (v1.x / d);
        p3.y = (v1.y / d);
        return p3;
    }
}