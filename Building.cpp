#include <iostream>
#include "Building.h"
#include "GameObject.h"
using namespace std;

Building::Building():GameObject::GameObject('B') //Default Constructor
{
    display_code = 'B';
    pokemon_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(Point2D in_loc, int in_id, char in_code):GameObject::GameObject(in_loc, in_id, in_code) //Constructor
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    pokemon_count = 0;
    state = '0';
    cout << "Building constructed" << endl;
}

void Building::AddOnePokemon()
{
    pokemon_count++;
}

void Building::RemoveOnePokemon()
{
    if (pokemon_count > 0)
    {
        pokemon_count--;
    } else
    {
        cout << "There are no Pokemon to remove" << endl;
    }
}

void Building::ShowStatus()
{
    cout << display_code << id_num << " at " << location << endl;
    if (pokemon_count < 1 || pokemon_count > 1)
    {
        cout << "\t" << pokemon_count << " Pokemon are in this building" << endl;
    } else
    {
        cout << "\t" << pokemon_count << " Pokemon is in this building" << endl;
    }   
}

bool Building::ShouldBeVisible()
{
    return true;
}