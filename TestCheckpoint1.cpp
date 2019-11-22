#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;

int main()
{
    Point2D point1;
    Point2D point2;
    Vector2D vector1;
    double d = 4;
    int q = 42;

    point1.x = 10;
    point1.y = 20;

    point2.x = 5;
    point2.y = 15;

    vector1.x = 3;
    vector1.y = 4;

    cout << point1 << endl;
    cout << point2 << endl;
    cout << vector1 << endl;
    cout << point1 + vector1 << endl;
    cout << point1 - point2 << endl;
    cout << vector1 * d << endl;
    cout << vector1 / d << endl;

    cout << GetDistanceBetween(point1, point2) << endl;
    
    return 0;
}