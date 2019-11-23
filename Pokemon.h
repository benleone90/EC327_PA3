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

    bool is_in_gym;

    bool is_in_center;

    unsigned int stamina;

    unsigned int experience_points;

    double pokemon_dollars;

    unsigned int training_units_to_buy;

    unsigned int stamina_points_to_buy;

    string name;

    PokemonCenter* current_center;

    PokemonGym* current_gym;

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