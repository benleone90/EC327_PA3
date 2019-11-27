#include <iostream>
#include "Model.h"
#include "Pokemon.h"
using namespace std;

Model::Model()
{
    time = 0;

    Pokemon* p1 = new Pokemon(Point2D(5,1), 1, 'P', 2, "Pikachu");
    object_ptrs[0] = p1;
    pokemon_ptrs[0] = p1;

    Pokemon* p2 = new Pokemon(Point2D(10, 1), 2, 'P', 1, "Bulbasaur");
    object_ptrs[1] = p2;
    pokemon_ptrs[1] = p2;

    PokemonCenter* c1 = new PokemonCenter(Point2D(1, 20), 1, 1, 100);
    object_ptrs[2] = c1;
    center_ptrs[0] = c1;

    PokemonCenter* c2 = new PokemonCenter(Point2D(10, 20), 2, 2, 200);
    object_ptrs[3] = c2;
    center_ptrs[1] = c2;

    PokemonGym* g1 = new PokemonGym(Point2D(0, 0), 1, 10, 1, 2, 10);
    object_ptrs[4] = g1;
    gym_ptrs[0] = g1;

    PokemonGym* g2 = new PokemonGym(Point2D(5, 5), 2, 20, 5, 7.5, 8);
    object_ptrs[5] = g2;
    gym_ptrs[1] = g2;

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
        if (pokemon_ptrs[i]->GetId() == id)
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
        if (center_ptrs[i]->GetId() == id)
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
        if (gym_ptrs[i]->GetId() == id)
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

void Model::Display(View& view)
{
    view.Clear();
    for (int i = 0; i < num_objects; i++)
    {
        view.Plot(object_ptrs[i]);
    }
    view.Draw();
}

void Model::ShowStatus()
{
    cout << "Time: "<< time << endl;
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}