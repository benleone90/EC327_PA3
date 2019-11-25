#ifndef Pokemon_H
#define Pokemon_H
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <string>
#include <math.h>

class Pokemon: public GameObject
{
    public:
    Pokemon();

    Pokemon(char);

    Pokemon(Point2D, int, char, unsigned int, string);

    void StartMoving(Point2D);

    void StartMovingToCenter(PokemonCenter*);

    void StartMovingToGym(PokemonGym*);

    void StartTraining(unsigned int);

    void StartRecoveringStamina(unsigned int);

    void Stop();

    bool IsExhaused();

    bool ShouldBeVisible();

    void ShowStatus();

    bool Update();
    

    private:
    double speed;

    bool is_in_gym = false;

    bool is_in_center = false;

    unsigned int stamina = 20;

    unsigned int experience_points = 0;

    double pokemon_dollars = 0;

    unsigned int training_units_to_buy = 0;

    unsigned int stamina_points_to_buy = 0;

    string name;

    PokemonCenter* current_center = NULL;

    PokemonGym* current_gym = NULL;

    Point2D destination;

    Vector2D delta;


    protected:
    bool UpdateLocation();

    void SetupDestination(Point2D);
};

double GetRandomAmountOfPokemonDollars();

enum PokemonStates
{
    STOPPED =            '0',
    MOVING =             '1',
    EXHAUSTED =          '2',
    IN_GYM =             '3',
    IN_CENTER =          '4',
    MOVING_TO_GYM =      '5',
    MOVING_TO_CENTER =   '6',
    TRAINING_IN_GYM =    '7',
    RECOVERING_STAMINA = '8'
};

#endif //Pokemon_H