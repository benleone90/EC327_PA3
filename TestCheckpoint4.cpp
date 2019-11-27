#include <iostream>
#include "Model.h"
#include "GameCommand.h"
using namespace std;

int main()
{
    Model test;
    bool run = 1;
    char command;
    int in_id;
    int obj_id;
    Point2D m;
    
    while (run)
    {
        cout << "Enter command: ";
        cin >> command;

        switch (command)
        {
        case 'm':
            cin >> in_id >> m.x >> m.y;
            DoMoveCommand(test, in_id, m);
            break;

        case 'g':
            cin >> in_id >> obj_id;
            DoMoveToGymCommand(test, in_id, obj_id);
            break;
            
        case 'q':
            exit(0);
        
        default:
            break;
        }
    }
    

    return 0;
}