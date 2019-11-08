#ifndef Vector2D_H
#define Vector2D_H
using namespace std;

class Vector2D
{
    public:
    double x, y;

    Vector2D(); //Default Constructor

    Vector2D(double in_x, double in_y); //Constructor  
};

ostream& operator<< (ostream&, const Vector2D&); //Overloaded insertion prototype

Vector2D operator* (Vector2D&, double); //Overloaded multiplication prototype

Vector2D operator/ (Vector2D&, double); //Overloaded division prototype

#endif //Vector2D_H