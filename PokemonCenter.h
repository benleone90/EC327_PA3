#ifndef PokemonCenter_H
#define PokemonCenter_H
#include "Building.h"
using namespace std;

class PokemonCenter: public Building
{
    public:
    PokemonCenter(); //Default Constructor

    PokemonCenter(Point2D, int, double, unsigned int); //Constructor

    ~PokemonCenter();

    bool HasStaminaPoints();

    unsigned int GetNumStaminaPointsRemaing();

    bool CanAffordStaminaPoints(unsigned int, double);

    double GetDollarCost(unsigned int);

    unsigned int DistributeStamina(unsigned int);

    bool Update();

    void ShowStatus();

    private:
    unsigned int stamina_capacity;

    unsigned int num_stamina_points_remaining;

    double dollar_cost_per_stamina_point;
};

enum PokemonCenterStates
{
    STAMINA_POINTS_AVAILABLE    = '0',
    NO_STAMINA_POINTS_AVAILABLE = '1'
};

#endif //PokemonCenter