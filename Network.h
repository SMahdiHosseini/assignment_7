#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Publisher.h"
#include "Film.h"

using namespace std;

class Network
{
public:
    void signup(string email, string username, string password, int age, bool publisher);
    void login(string username, string pasword);
    User* find_logged_in_user();
    
private:
    vector<User*> users;
    vector<Film*> films;
    int cash;
};

#endif