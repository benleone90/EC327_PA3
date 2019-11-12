#ifndef PokemonCenter_H
#define PokemonCenter_H
#include "Building.h"
using namespace std;

class PokemonCenter: public Building
{

};

enum PokemonCenterStates
{
    STAMINA_POINTS_AVAILABLE = 0,
    NO_STAMINA_POINTS_AVAILABLE = 1
};

#endif //PokemonCenter