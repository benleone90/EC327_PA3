#include <iostream>
#include <string>
#include "Pokemon.h"
#include "GameObject.h"
using namespace std;

Pokemon::Pokemon():GameObject::GameObject('P') //Default constructor
{
    speed = 5.0;
    cout << "Pokemon default constructed" << endl;
}

Pokemon::Pokemon(char in_code):GameObject::GameObject(in_code)
{
    speed = 5.0;
    display_code = in_code;
    state = STOPPED;
    cout << "Pokemon constructed" << endl;
}

Pokemon::Pokemon(Point2D in_loc, int in_id, char in_code, unsigned int in_speed, string in_name):GameObject::GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    name = in_name;
    state = STOPPED;
    cout << "Pokemon constructed" << endl;
}

void Pokemon::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
    {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    } else if (state == EXHAUSTED)
    {
        cout << display_code << id_num << ": I am exhaused. I may move but you cannot see me." << endl;
    } else
    {
        state = MOVING;
        cout << display_code << id_num << ": I'm on my way." << endl;
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
    current_center = center;
    SetupDestination(center->GetLocation());
    if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
    {
        cout << display_code << id_num << ": I'm already at the Pokemon Center!" << endl;
    } else if (state == EXHAUSTED)
    {
        cout << display_code << id_num << ": I am exhaused so I can't move to recover stamina..." << endl;
    } else
    {
        state = MOVING_TO_CENTER;
        cout << display_code << id_num << ": on my way to center " << center->GetId() << endl;
    }
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
    current_gym = gym;
    SetupDestination(gym->GetLocation());
    if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
    {
        cout << display_code << id_num << ": I'm already at the Pokemon Gym!" << endl;
    } else if (state == EXHAUSTED)
    {
        cout << display_code << id_num << ": I am exhaused so I shouldn't be going to the gym..." << endl;
    } else
    {
        state = MOVING_TO_GYM;
        cout << display_code << id_num << ": on my way to gym " << gym->GetId() << endl;
    }
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
    if (state == EXHAUSTED)
    {
        cout << display_code << id_num << ": I am exhaused so no more training for me..." << endl;
    }
    else if (state != IN_GYM)
    {
        cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
    }
    else if (current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina) == false)
    {
        cout << display_code << id_num << ": Not enough stamina and/or money for training." << endl;
    }
    else if (current_gym->IsBeaten())
    {
        cout << display_code << id_num << ": Cannot train! This Pokemon Gym is alreay beaten!" << endl;
    } else if (current_gym->GetNumTrainingUnitsRemaining() > num_training_units)
    {
        training_units_to_buy = num_training_units;
    } else
    {
        training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining();
    }
}

void Pokemon::ShowStatus()
{
    cout << name << " status: ";
    GameObject::ShowStatus();
    switch (state)
    {
    case STOPPED:
        cout << " stopped" << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollar: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
        break;

    case MOVING:
        cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << "." << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollar: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
        break;

    case MOVING_TO_CENTER:
        cout << " heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollar: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
        break;

    case MOVING_TO_GYM:
        cout << " heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
        cout << "\tStamina: " << stamina << endl;
        cout << "\tPokemon Dollar: " << pokemon_dollars << endl;
        cout << "\tExperience Points: " << experience_points << endl;
        break;

    case IN_CENTER:
        cout << " inside Pokemon Center " << current_center->GetId() << endl;
        break;

    case IN_GYM:
        cout << " inside Pokemon Gym " << current_gym->GetId() << endl;
        break;

    case TRAINING_IN_GYM:
        cout << " training in Pokemon Gym " << current_gym->GetId() << endl;
        break;

    case RECOVERING_STAMINA:
        cout << " recovering stamina in Pokemon Center " << current_center->GetId() << endl;
        break;
    
    default:
        break;
    }
}

bool Pokemon::Update()
{
    switch (state)
    {
    case STOPPED:
        return 0;
        break;

    case MOVING:
        UpdateLocation();
        if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
        {
            state = STOPPED;
            return 1;
        } else
        {
            state = MOVING;
            return 0;
        }
        break;

    case MOVING_TO_CENTER:
        UpdateLocation();
        if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
        {
            state = IN_CENTER;
            return 1;
        } else
        {
            state = MOVING;
            return 0;
        }
        break;

    case MOVING_TO_GYM:
        UpdateLocation();
        if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
        {
            state = IN_GYM;
            return 1;
        } else
        {
            state = MOVING;
            return 0;
        }
        break;

    case IN_CENTER:
        return 0;
        break;

    case IN_GYM:
        return 0;
        break;

    case TRAINING_IN_GYM:
        state = IN_GYM;
        stamina = stamina - current_gym->GetStaminaCost(training_units_to_buy);
        pokemon_dollars = pokemon_dollars - current_gym->GetDollarCost(training_units_to_buy);
        experience_points = experience_points + current_gym->TrainPokemon(training_units_to_buy);
        cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;
        cout << "** " << name << " gained " << current_gym->TrainPokemon(training_units_to_buy) << " expereince point(s)! **" << endl;
        return IN_GYM;
        break;

    case RECOVERING_STAMINA:
        state = IN_CENTER;
        stamina = stamina + current_center->DistributeStamina(stamina_points_to_buy);
        pokemon_dollars = pokemon_dollars - current_center->GetDollarCost(stamina_points_to_buy);
        cout << "** " << name << " recovered " << current_center->DistributeStamina(stamina_points_to_buy) << " stamina point(s)! **" << endl;
        return IN_CENTER;
        break;
        
    default:
        return 0;
        break;
    }
}

bool Pokemon::UpdateLocation()
{
    if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
    {
        cout << display_code << id_num << ": I'm there!" << endl;
    } else
    {
        location = location + delta;
        cout << display_code << id_num << ": step..." << endl;
    }
    
    return 0;
}

void Pokemon::SetupDestination(Point2D dest)
{
    destination = dest;
    if (GetDistanceBetween(destination, location) == 0)
    {
        delta.x = 0;
        delta.y = 0;
    } else
    {    
        delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
    }
    //cout << delta << endl;
}

double GetRandomAmountOfPokemonDollars()
{
    srand(time(0));
    return 0.0 + (rand() / (RAND_MAX / 2.0 - 0.0));
}