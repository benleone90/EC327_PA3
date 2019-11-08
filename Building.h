#ifndef Building_H
#define Building_H
#include "GameObject.h"
using namespace std;

class Building:public GameObject
{
    public:
    Building(); //Default Constructor

    Building(Point2D, int, char); //Constructor

    void AddOnePokemon();

    void RemoveOnePokemon();

    void ShowStatus();

    bool ShouldBeVisible();

    private:
    unsigned int pokemon_count;
};

#endif //Building_H