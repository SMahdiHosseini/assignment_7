#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Publisher.h"
#include "Film.h"

using namespace std;

class Network
{
public:
    void signup();
    void login();
    User* find_logged_in_user();
    
private:
    vector<User*> users;
    vector<Film*> films;
    double cash;
};

#endif