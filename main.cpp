#include <iostream>
#include "GameCommand.h"
using namespace std;

int main()
{
    Model* m = new Model();
    View* v  = new View();

    bool run = 1;
    char command = ' ';

    m->ShowStatus();
    m->Display(*v);
    
    while (run)
    {   
        cout << "Enter command: ";
        cin >> command;
        int in_id;
        int obj_id;
        Point2D move;
    

        switch (command)
        {
        case 'm':
            cin >> in_id >> move.x >> move.y;
            DoMoveCommand(*m, in_id, move);
            m->Display(*v);
            break;

        case 'g':
            cin >> in_id >> obj_id;
            DoMoveToGymCommand(*m, in_id, obj_id);
            m->Display(*v);
            break;

        case 'v':
            DoGoCommand(*m, *v);
            m->ShowStatus();
            break;
            
        case 'q':
            exit(0);
        
        default:
            break;
        }
    }
    

    return 0;
}