#ifndef Pokemon_H
#define Pokemon_H

class Pokemon: public GameObject
{
    public:
    Pokemon();

    private:
    double speed;

    bool is_in_gym;

    bool is_in_center;

    unsigned int stamina;

    unsigned int experience_points;

    double pokemon_dollars;

    unsigned int training_units_to_buy;

    

    protected:


};

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
}

#endif //Pokemon_H