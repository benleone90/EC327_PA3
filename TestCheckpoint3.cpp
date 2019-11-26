#include <iostream>
#include <string>
#include "Pokemon.h"
using namespace std;

int main()
{
    Pokemon test(Point2D(3,4), 69, 'P', 2, "PIKACHU");
    PokemonGym gym1(Point2D(2,3), 9, 2, 5, 10, 4);
    PokemonCenter center1(Point2D(6,10), 12, 5, 20);
    test.ShowStatus();
    test.StartMovingToCenter(&center1);
    test.Update();
    test.ShowStatus();
    test.Update();
    test.ShowStatus();
    test.Update();
    test.ShowStatus();
    test.Update();
    test.ShowStatus();
    cout << test.GetState() << endl;
    test.StartRecoveringStamina(2);
    test.ShowStatus();
    

    //cout << GetRandomAmountOfPokemonDollars() << endl;

    return 0;
}