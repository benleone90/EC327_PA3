#include <iostream>
#include <string>
#include "Pokemon.h"

int main()
{
    Pokemon test(Point2D(3,4), 69, 'P', 2, "PIKACHU");
    PokemonGym gym1(Point2D(2,3), 9, 2, 5, 10, 4);
    PokemonCenter center1(Point2D(6,9), 12, 5, 20);
    test.ShowStatus();
    test.StartMoving(Point2D(10,19));
    test.Update();
    test.ShowStatus();
    test.Update();
    test.ShowStatus();
    test.Update();
    test.ShowStatus();
    test.Update();
    test.ShowStatus();
    

    //cout << GetRandomAmountOfPokemonDollars() << endl;

    return 0;
}