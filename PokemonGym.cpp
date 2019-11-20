#include <iostream>
#include "PokemonGym.h"
#include "PokemonCenter.h"
using namespace std;

PokemonGym::PokemonGym() //Default Constructor
{
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(Point2D in_loc, int in_id, unsigned int max_training_units, unsigned int stamina_cost,
double dollar_cost, unsigned int exp_points_per_unit)
{
    display_code = 'G';
    state = NOT_BEATEN;
    id_num = in_id;
    max_number_of_training_units = max_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    dollar_cost_per_training_unit = dollar_cost;
    location = in_loc;
    cout << "PokemonGym constructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
    return dollar_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
    return stamina_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
    return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
    if ((stamina >= GetStaminaCost(unit_qty)) && (budget >= GetDollarCost(unit_qty)))
    {
        return true;
    }
    else
    {
        return false;
    }   
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
    if (num_training_units_remaining >= training_units)
    {
        num_training_units_remaining = num_training_units_remaining - training_units;
        return training_units * experience_points_per_training_unit;
    } else
    {
        num_training_units_remaining = 0;
        return num_training_units_remaining * experience_points_per_training_unit;
    }   
}

bool PokemonGym::Update()
{
    if ((num_training_units_remaining == 0) && (state == NOT_BEATEN))
    {
        state = BEATEN;
        display_code = 'g';
        cout << display_code << id_num << " has been beaten" << endl;
        return true;
    } else
    {
        return false;
    }
}

bool PokemonGym::IsBeaten()
{
    if (num_training_units_remaining == 0)
    {
        return true;
    } else
    {
        return false;
    }
    
}

void PokemonGym::ShowStatus()
{
    cout << "Pokemon Gym Status: " << endl;
    Building::ShowStatus();
    cout << "Max number of training units: " << max_number_of_training_units << endl;
    cout << "stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
    cout << "Pokemon dollars per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "Experience points per traingin unit: " << experience_points_per_training_unit << endl;
    cout << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl;
}