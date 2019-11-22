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

void Pokemon::ShowStatus()
{
    cout << name << " status:" << endl;
    GameObject::ShowStatus();

}