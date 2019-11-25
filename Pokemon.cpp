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
    cout << "Pokemon constructed" << endl;
}

void Pokemon::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    cout << destination.x - location.x << endl;
    state = MOVING;
    if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y - location.y) <= delta.y))
    {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    } else if (state == EXHAUSTED)
    {
        cout << display_code << id_num << ": I am exhaused. I may move but you cannont see me." << endl;
    } else
    {
        cout << display_code << id_num << ": I'm on my way." << endl;
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


    default:
        return 0;
        break;
    }
}

bool Pokemon::UpdateLocation()
{
    if (state == MOVING)
    {
        location = location + delta;
        cout << display_code << id_num << ": step..." << endl;
    } else if ((fabs(destination.x - location.x) <= delta.x) && (fabs(destination.y -location.y) <= delta.y))
    {
        cout << display_code << id_num << ": I'm there!" << endl;
    }
    return 0;
}

void Pokemon::SetupDestination(Point2D dest)
{
    destination = dest;
    Vector2D dest_hold = destination - location;
    delta = (dest_hold) * (speed / GetDistanceBetween(destination, location));
    cout << delta.x << endl;
}