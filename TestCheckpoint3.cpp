#include <iostream>
#include <string>
#include "Pokemon.h"

int main()
{
    Pokemon test(Point2D(3,4), 3, 'P', 2, "PIKACHU");
    test.StartMoving(Point2D(3,4));
    //test.ShowStatus();

    return 0;
}