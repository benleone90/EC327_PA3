#ifndef GameObject_H
#define GameObject_H
#include "Point2D.h"
using namespace std;

class GameObject
{
    public:
    GameObject(char);

    GameObject(Point2D, int, char);

    Point2D GetLocation();

    int GetId();

    bool GetState();

    void ShowStatus();

    protected:
    Point2D location;

    int id_num;

    char display_code;

    char state;
};

#endif //GameObject_H