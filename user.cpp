#include "user.h"
#include "exceptions.h"

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

string User::get_email()
{
    return email;
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

void User::logout()
{
    login = false;
}

void User::login_user()
{
    login = true;
}

void User::add_film(Film* new_film)
{
    throw Inaccessibility() ;
}

void User::delete_film(int film_id)
{
    throw Inaccessibility();
}

void User::show_followers()
{
    throw Inaccessibility();
}

void User::get_money(int money)
{
    throw Inaccessibility();
}

void User::reply_commemt(int film_id, int comment_id, string comtent)
{
    throw Inaccessibility();
}

int User::find_film_index(int film_id)
{
    throw Inaccessibility();
}

void User::delete_comment(int film_id, int comment_id)
{
    throw Inaccessibility();
}