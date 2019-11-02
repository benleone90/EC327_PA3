#ifndef GameObject_H
#define GameObject_H
#include "Point2D.h"
using namespace std;

class GameObject
{
    public:
    GameObject(char in_code)
    {
        display_code = in_code;
        id_num = 1;
        state = 0;
        cout << "GameObject constructed" << endl;
    }

    GameObject(Point2D in_loc, int in_id, char in_code);

    Point2D GetLocation()
    {
        return location;
    }

    int GetId()
    {
        return id_num;
    }

    char GetState()
    {
        return state;
    }

    void ShowStatus()
    {
        cout << display_code << id_num << "at " << location << endl;
    }

    protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
};

#endif //GameObject_H