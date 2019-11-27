#include <iostream>
#include "Model.h"
#include "Pokemon.h"
using namespace std;

Model::Model()
{
    time = 0;

    object_ptrs[0] = new Pokemon(Point2D(5,1), 1, 'P', 2, "Pikachu");
    pokemon_ptrs[0] = new Pokemon(Point2D(5,1), 1, 'P', 2, "Pikachu");

    object_ptrs[1] = new Pokemon(Point2D(10, 1), 2, 'P', 1, "Bulbasaur");
    pokemon_ptrs[1] = new Pokemon(Point2D(10, 1), 2, 'P', 1, "Bulbasaur");

    object_ptrs[2] = new PokemonCenter(Point2D(1,20), 1, 1, 100);
    center_ptrs[0] = new PokemonCenter(Point2D(1,20), 1, 1, 100);

    object_ptrs[3] = new PokemonCenter(Point2D(10,20), 2, 2, 200);
    center_ptrs[1] = new PokemonCenter(Point2D(10,20), 2, 2, 200);

    object_ptrs[4] = new PokemonGym(Point2D(0,0), 1, 10, 1, 2, 10);
    gym_ptrs[0] = new PokemonGym(Point2D(0,0), 1, 10, 1, 2, 10);

    object_ptrs[5] = new PokemonGym(Point2D(5,5), 2, 20, 5, 7.5, 8);
    gym_ptrs[1] = new PokemonGym(Point2D(5,5), 2, 20, 5, 7.5, 8);

    num_objects = 6;

    num_pokemon = 2;

    num_centers = 2;

    num_gyms = 2;

    cout << "Model default constructed" << endl;
}

Model::~Model()
{
    for (int i = 0; i < num_objects; i++)
    {
        delete object_ptrs[i];
    }
    cout << "Model destructed" << endl;
}

Pokemon* Model::GetPokemonPtr(int id)
{
    for (int i = 0; i < num_pokemon; i++)
    {
        if (id == pokemon_ptrs[i]->GetId())
        {
            return pokemon_ptrs[i];
        }
    }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    for (int i = 0; i < num_centers; i++)
    {
        if (id == center_ptrs[i]->GetId())
        {
            return center_ptrs[i];
        }    
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
    for (int i = 0; i < num_gyms; i++)
    {
        if (id == gym_ptrs[i]->GetId())
        {
            return gym_ptrs[i];
        }   
    }
    return 0;
}

bool Model::Update()
{
    time = time + 1;

    for (int i = 0; i < num_objects; i++)
    {
        if (object_ptrs[i]->Update())
        {
            return 1;
        }
    }

    if (num_gyms == 0)
    {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit(0);
    }
    else if (num_pokemon == 0)
    {
        cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
        exit(0);
    }
    return 0;
}

//void Model::Display(View& view);

void Model::ShowStatus()
{
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}