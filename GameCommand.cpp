#include <iostream>
#include "GameCommand.h"
#include "Model.h"
using namespace std;

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to " << p1 << endl;
        model.GetPokemonPtr(pokemon_id)->StartMoving(p1);
    }
    else
    {
        cout << "Error: Please enter valid command" << endl;
    }    
}

void DoMoveToCenter(Model& model, int pokemon_id, int center_id)
{
    if ((model.GetPokemonCenterPtr(center_id)) && (model.GetPokemonPtr(pokemon_id)))
    {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to center " << center_id << endl;
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }    
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
    if ((model.GetPokemonGymPtr(gym_id)) && (model.GetPokemonPtr(pokemon_id)))
    {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to gym " << gym_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model& model, int pokemon_id)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        cout << "Stopping " << model.GetPokemonPtr(pokemon_id)->GetName() << endl; 
    }
    else
    {
        cout << "Error: Please enter valid command" << endl;
    } 
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
    if ((model.GetPokemonPtr(pokemon_id)) && model.GetPokemonPtr(pokemon_id)->GetState() == IN_GYM)
    {
        model.GetPokemonPtr(pokemon_id)->StartTraining(training_units);
        cout << "Training " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
    }
    else
    {
        cout << "Error: Please enter valid command!" << endl;
    }
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned stamina_points)
{
    if ((model.GetPokemonPtr(pokemon_id)) && model.GetPokemonPtr(pokemon_id)->GetState() == IN_CENTER)
    {
        model.GetPokemonPtr(pokemon_id)->StartRecoveringStamina(stamina_points);
        cout << "Recovering " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
    }
    else
    {
        cout << "Error: Please enter valid command!" << endl;
    }
}

void DoGoCommand(Model& model, View& view)
{
    model.Update();
    model.Display(view);
    cout << "Advancing one tick." << endl;
}

void DoRunCommand(Model& model, View& view)
{
    model.Update();
    model.Display(view);
    cout << "Advancing to next event." << endl;
}