#ifndef USER_REPOS_H
#define USER_REPOS_H

#include "user.h"
#include <vector>

class UserRepository
{
public:
    UserRepository();
    void signup(std::string email, std::string username, std::string password, int age, bool publisher);
    void add_publisher(std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string pasword);
    bool check_existed_user(std::string username);
    User* find_user(std::string username, std::string password);
    User* find_logged_in_user();
private:
    int last_id;
    std::vector<User*> users;    
};

#endif