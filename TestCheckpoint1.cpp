#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;

int main()
{
    Point2D point1(10, 20);
    Point2D point2(5, 15);
    Vector2D vector1(3, 4);
    double d = 4;
    double test = 5;
    int q = 42;
    Vector2D hold = point1 - point2;

    cout << point1 << endl;
    cout << point2 << endl;
    cout << vector1 << endl;
    cout << point1 + vector1 << endl;
    cout << point1 - point2 << endl;
    cout << vector1 * d << endl;
    cout << vector1 / d << endl;
    cout << (hold) * (test / GetDistanceBetween(point1, point2)) << endl;

    cout << GetDistanceBetween(point1, point2) << endl;
    
    return 0;
}