#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Publisher.h"
#include "Film.h"

class Network
{
public:
    void signup(std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string pasword);
    User* find_logged_in_user();
private:
    std::vector<User*> users;
    std::vector<Film*> films;
    int cash;
};

#endif