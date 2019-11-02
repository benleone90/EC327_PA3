#include <iostream>
#include "Vector2D.h"
using namespace std;

ostream& operator<< (ostream& out, const Vector2D& obj) //Overloaded insertion operator
{
    out << "<" << obj.x << ", " << obj.y << ">" << endl;
    return out;
}

Vector2D operator* (Vector2D& v1, double d) //Overloaded multiplication operator
{
    Vector2D p3;
    p3.x = v1.x * d;
    p3.y = v1.y * d;
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
        p3.x = v1.x / d;
        p3.y = v1.y / d;
        return p3;
    }
}