#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
using namespace std;

int main()
{

    GameObject test(Point2D(3,2), 3, 'c');
    
    cout << test.GetLocation()<< endl;
    return 0;
}