#ifndef GameCommand_H
#define GameCommand_H
#include <iostream>
#include "model.h"
using namespace std;

void DoMoveCommand(Model&, int, Point2D);

void DoMoveToCenter(Model&, int, int);

void DoMoveToGymCommand(Model&, int, int);

void DoStopCommand(Model&, int);

void DoTrainInGymCommand(Model&, int, unsigned int);

void DoRecoverInCenterCommand(Model&, int, unsigned int);

//void DoGoCommand(Model&, View&);

//void DoRunCommand(Model&, View&);


#endif //GameCommand_H