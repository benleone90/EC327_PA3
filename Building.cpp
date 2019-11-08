#include <iostream>
#include "Building.h"
#include "GameObject.h"
using namespace std;

Building::Building()
{
    display_code = 'B';
    pokemon_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(Point2D in_loc, int in_id, char in_code)
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    pokemon_count = 0;
    state = '0';
}

void Building::AddOnePokemon()
{
    pokemon_count++;
}

void Building::RemoveOnePokemon()
{
    pokemon_count--;
}

void Building::ShowStatus()
{
    if (pokemon_count < 1 || pokemon_count > 1)
    {
        cout << pokemon_count << " Pokémon are in this building" << endl;
    } else
    {
        cout << pokemon_count << " Pokémon is in this building" << endl;
    }   
}

bool Building::ShouldBeVisible()
{
    return true;
}