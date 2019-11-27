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

        // switch (command)
        // {
        // case 'm':
        //     cin >> in_id >> m.x >> m.y;
        //     DoMoveCommand(test, in_id, m);
        //     break;

        // case 'g':
        //     cin >> in_id >> obj_id;
        //     DoMoveToGymCommand(test, in_id, obj_id);
        //     break;
            
        // case 'q':
        //     exit(0);
        
        // default:
        //     break;
        // }
    }
    

    return 0;
}