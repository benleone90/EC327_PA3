#include <iostream>
#include <string>
#include "Pokemon.h"

int main()
{
    Pokemon test(Point2D(3,4), 69, 'P', 2, "PIKACHU");
    // test.StartMoving(Point2D(6,4));
    // test.ShowStatus();

    PokemonGym gym1(Point2D(2,3), 9, 2, 5, 10, 4);
    test.StartMovingToGym(&gym1);
    test.ShowStatus();
    test.Update();
    cout << test.GetState() << endl;
    cout << test.GetLocation() << endl;

    cout << GetRandomAmountOfPokemonDollars() << endl;

    return 0;
}