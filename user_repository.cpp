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
    return nullptr;
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

void UserRepository::login(string username, string password)
{
    if(find_user(username, password) == nullptr)
        throw BadRequest();
    find_logged_in_user()->logout();
    find_user(username, password)->login_user();
}

void UserRepository::follow_publisher(int publisher_id)
{
    Publisher* publisher = find_publisher_by_id(publisher_id);
    publisher->add_follower(find_logged_in_user());
    find_logged_in_user()->follow_publisher(publisher);
}

Publisher* UserRepository::find_publisher_by_id(int publisher_id)
{
    for (int i = 0; i < users.size(); i++)
        if(users[i]->get_id() == publisher_id && users[i]->check_publsher())
            return (Publisher*)users[i];
    throw BadRequest();
}

void UserRepository::buy_film(Film* film, Publisher* publisher)
{
    find_logged_in_user()->buy_film(film, publisher);
}

void UserRepository::add_existed_publisher(Publisher* publisher)
{
    if(check_existed_user(publisher->get_username()))
        users.push_back(publisher); 
}