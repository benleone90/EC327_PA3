#include <iostream>
#include <string>
#include "Pokemon.h"

int main()
{
    Pokemon test(Point2D(4,3), 3, 'R', 2, "Bob");
    test.ShowStatus();

    Pokemon hello;
    hello.ShowStatus();

    Pokemon newguy('Q');
    newguy.ShowStatus();
    test.StartMoving(Point2D(5,7));

    return 0;
}