#include <iostream>
#include "PokemonCenter.h"
using namespace std;

PokemonCenter::PokemonCenter()
{
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5.00;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(Point2D in_loc, int in_id, double stamina_cost, unsigned int stamina_cap) //Constructor
{
    display_code = 'C';
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_stamina_point = stamina_cost;
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter destructed" << endl;
}

bool PokemonCenter::HasStaminaPoints()
{
    if (num_stamina_points_remaining >= 1)
    {
        return true;
    } else
    {
        return false;
    }
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaing()
{
    return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if (budget >= (stamina_points * dollar_cost_per_stamina_point))
    {
        return true;
    } else
    {
        return false;
    }
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return stamina_points * dollar_cost_per_stamina_point;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    if (num_stamina_points_remaining >= points_needed)
    {
        return points_needed = num_stamina_points_remaining - points_needed;
    } else
    {
        return num_stamina_points_remaining;
        stamina_capacity = 0;
    }
}

bool PokemonCenter::Update()
{
    if ((stamina_capacity == 0) && (state == STAMINA_POINTS_AVAILABLE))
    {
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl;
        return true;
    } else 
    {
        return false;
    }
}

void PokemonCenter::ShowStatus()
{
    cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    cout << "\tPokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout << "\tHas " << num_stamina_points_remaining << " stamina point(s) remaining" << endl;
}