#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "user.h"
#include "publisher.h"
#include "film.h"

class Network
{
public:
    Network();  
    void signup(int id, std::string email, std::string username, std::string password, int age, bool publisher);
    void add_publisher(int id, std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string pasword);
    User* find_logged_in_user();
private:
    std::vector<User*> users;
    std::vector<Film*> films;
    int cash;
};

#endif