#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
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

    cout << point1;
    cout << point2;
    cout << vector1;
    cout << point1 + vector1;
    cout << point1 - point2;
    cout << vector1 * d;
    cout << vector1 / d;

    cout << GetDistanceBetween(point1, point2) << endl;
    
    GameObject test(point1, q, 'h');
    cout << test.GetId() << endl;
    cout << test.GetLocation() << endl;
    cout << test.GetState() << endl;
    test.ShowStatus();
    return 0;
}