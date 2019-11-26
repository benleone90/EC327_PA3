#include <iostream>
#include "model.h"
#include "Pokemon.h"
using namespace std;

Model::Model()
{
    time = 0;

    object_ptrs[0], pokemon_ptrs[0] = new Pokemon(Point2D(5,1), 1, 'P', 2, "Pikachu");

    object_ptrs[1], pokemon_ptrs[1] = new Pokemon(Point2D(10, 1), 2, 'P', 3, "Bulbasaur" );

    object_ptrs[2], center_ptrs[0] = new PokemonCenter(Point2D(1,20), 1, 2, 20);

    object_ptrs[3], center_ptrs[1] = new PokemonCenter(Point2D(10,20), 1, 2, 20);

    object_ptrs[4], gym_ptrs[0] = new PokemonGym(Point2D(9,5), 1, 20, 2, 1, 2);

    object_ptrs[5], gym_ptrs[1] = new PokemonGym(Point2D(5,5), 2, 20, 2, 1, 2);

    num_objects = 6;

    num_pokemon = 2;

    num_centers = 2;

    num_gyms = 2;

    cout << "Model default constructed" << endl;
}

Model::~Model()
{
    for (int i = 0; i <= 10; i++)
    {
        delete object_ptrs[i];
    }
    cout << "Model destructed" << endl;
}

bool Model::Update()
{
    time = time + 1;
    for (int i = 0; i <= 10; i++)
    {
        if (object_ptrs[i]->Update())
        {
            return 1;
        }
    }
}

//void Model::Display(View& view);

void Model::ShowStatus()
{
    for (int i = 0; i <= 10; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}