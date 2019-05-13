#include "user_repository.h"
#include "exceptions.h"

using namespace std;

UserRepository::UserRepository()
{
    last_id = 0;
}

bool UserRepository::check_existed_user(string username)
{
    for (int i = 0; i < users.size(); i++)
        if(users[i]->get_username() == username)
            return true;
    return false;
}

User* UserRepository::find_user(string username, string password)
{
    for (int i = 0; i < users.size(); i++)
        if(users[i]->get_username() == username && users[i]->get_password() == password)
            return users[i];
    throw BadRequest();
}

User* UserRepository::find_logged_in_user()
{
    for (int i = 0; i < users.size(); i++)
        if (users[i]->check_login())
            return users[i];
}

void UserRepository::signup(string email, string username, string password, int age, bool publisher)
{
    if(check_existed_user(username))
        throw BadRequest();
    last_id++;
    find_logged_in_user()->logout();
    if(publisher)        
        add_publisher(email, username, password, age, publisher);
    User* new_user = new User(last_id,email, username, password, age, publisher);
    users.push_back(new_user);
}
void UserRepository::add_publisher(string email, string username, string password, int age, bool publisher)
{
    Publisher* new_publisher = new Publisher(last_id, email, username, password, age, publisher);
    users.push_back(new_publisher);
}

bool UserRepository::check_publisher()
{
    if (find_logged_in_user()->check_publsher())
        return true;
    return false;
}