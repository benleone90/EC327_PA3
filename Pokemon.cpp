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
    state = MOVING;
    if ((fabs(dest.x - location.x) <= delta.x) && (fabs(dest.y -location.y) <= delta.y))
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
    cout << name << " status:" << endl;
    GameObject::ShowStatus();
}

// bool Pokemon::Update()
// {

// }

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

void Pokemon::SetupDestination(Point2D)
{
    Vector2D distance_hold = destination - location;
    delta = (distance_hold) * (speed / GetDistanceBetween(destination, location));
}