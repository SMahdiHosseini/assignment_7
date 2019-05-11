#include "User.h"

#define DEFAULT_CASH 0
using namespace std;

User::User(int _id, std::string _email, std::string _username, std::string _password, int _age, bool _publisher)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    id = _id;
    publisher = _publisher;
    login = true;
    cash = DEFAULT_CASH;
}

string User::get_username()
{
    return username;
}

string User::get_password()
{
    return password;
}

int User::get_id()
{
    return id;
}

bool User::check_login()
{
    return login;
}

bool User::check_publsher()
{
    return publisher;
}