#ifndef Model_H
#define Model_H
#include <iostream>
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "View.h"
using namespace std;

class Model
{
    public:
    Model();

    ~Model();

    Pokemon* GetPokemonPtr(int);

    PokemonCenter* GetPokemonCenterPtr(int);

    PokemonGym* GetPokemonGymPtr(int);

    bool Update();

    void Display(View&);

    void ShowStatus();

    private:
    int time;

    GameObject* object_ptrs[10];

    int num_objects;

    Pokemon* pokemon_ptrs[10];

    int num_pokemon;

    PokemonCenter* center_ptrs[10];

    int num_centers;

    PokemonGym* gym_ptrs[10];

    int num_gyms;
};

#endif //Model_H