#include <iostream>
#include "GameCommand.h"
using namespace std;

int main()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019 - Programming Assignment 3" << endl;
    cout << R"(
                                 ,'\
   _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
\.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
  \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
   \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
    \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
     \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
      \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
       \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                               `'                            '-._|
                               )"
            << '\n';
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
        unsigned int amt;
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

        case 'c':
            cin >> in_id >> obj_id;
            DoMoveToCenterCommand(*m, in_id, obj_id);
            m->Display(*v);
            break;

        case 's':
            cin >> in_id >> obj_id;
            DoStopCommand(*m, in_id); 
            m->Display(*v);
            break;

        case 'r':
            cin >> in_id >> amt;
            DoRecoverInCenterCommand(*m, in_id, amt);
            m->Display(*v);
            break;

        case 't':
            cin >> in_id >> amt;
            DoTrainInGymCommand(*m, in_id, amt);
            m->Display(*v);
            break;

        case 'v':
            DoGoCommand(*m, *v);
            m->ShowStatus();
            break;

        case 'x':
            DoRunCommand(*m, *v);
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