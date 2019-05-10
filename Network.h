#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Publisher.h"
#include "Film.h"

using namespace std;

class Network
{
public:
	
private:
    vector<Publisher*> publishers;
    vector<Film*> films;
    double cash;
};

#endif