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

    GameObject test('f');
    Building build;
    PokemonCenter center(Point2D(4,5), 7, 2.0, 25);
    PokemonGym gym(Point2D(9,4), 3, 20, 5, 2.0, 6);
    
    cout << test.GetLocation()<< endl;
    cout << "---------------------------------" << endl;
    center.AddOnePokemon();
    center.AddOnePokemon();
    center.ShowStatus();
    center.RemoveOnePokemon();
    center.ShowStatus();
    cout << center.GetNumStaminaPointsRemaing() << endl;
    cout << center.HasStaminaPoints() << endl;
    cout << "---------------------------------" << endl;
    center.GameObject::ShowStatus();
    test.ShowStatus();
    cout << "---------------------------------" << endl;
    cout << gym.GetState() << endl;
    
    // gym.AddOnePokemon();
    // gym.ShowStatus();
    // cout << gym.GetDollarCost(5) << endl;
    // cout << gym.GetStaminaCost(5) << endl;
    // cout << gym.IsAbleToTrain(2, 100, 50) << endl;

    return 0;
}