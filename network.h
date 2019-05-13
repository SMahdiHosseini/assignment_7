#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <map>
#include "user.h"
#include "publisher.h"
#include "film.h"
#include "user_repository.h"

class Network
{
public:
    Network();  
    void signup(std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string pasword);
    bool check_existed_user(std::string username);
    User* find_user(std::string username, std::string password);
    User* find_logged_in_user();
private:
    UserRepository users;    
    std::vector<Film*> films;
    std::map<std::string, int> cash;
};

#endif