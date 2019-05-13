#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <map>
#include "user.h"
#include "user_repository.h"
#include "film_repository.h"

class Network
{
public:
    Network();  
    void signup(std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string pasword);
    void add_film(std::string name, int year, int length, int price, std::string summary, std::string director);
    void edit_film(int film_id, std::map<std::string, std::string> edited_options);
    bool check_existed_user(std::string username);
    User* find_user(std::string username, std::string password);
    User* find_logged_in_user();
private:
    UserRepository* users;    
    FilmRepository* films;
    std::map<std::string, int> cash;
};

#endif