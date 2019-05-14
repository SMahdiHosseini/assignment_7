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
    void follow_publisher(int publisher_id);
    void login(std::string username, std::string pasword);
    bool check_existed_user(std::string username);
    bool check_publisher();
    Publisher* find_publisher_by_id(int user_id);
    User* find_user(std::string username, std::string password);
    User* find_logged_in_user();
private:
    int last_id;
    std::vector<User*> users;    
};

#endif