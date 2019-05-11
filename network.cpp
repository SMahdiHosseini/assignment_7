#include "network.h"
#include "exceptions.h"

#define DEFAULT_CASH 0

using namespace std;

Network::Network()
{
    cash = DEFAULT_CASH;
}

User* Network::find_logged_in_user()
{
    for (int i = 0; i < users.size(); i++)
        if (users[i]->check_login())
            return users[i];
}

bool Network::check_existed_user(string username)
{
    for (int i = 0; i < users.size(); i++)
        if(users[i]->get_username() == username)
            return true;
    return false;
}

void Network::signup(int id, string email, string username, string password, int age, bool publisher)
{
    if(check_existed_user(username))
        throw BadRequest();
    find_logged_in_user()->logout();
    if(publisher)        
        add_publisher(id, email, username, password, age, publisher);
    User* new_user = new User(id,email, username, password, age, publisher);
    users.push_back(new_user);
}

void Network::add_publisher(int id, std::string email, std::string username, std::string password, int age, bool publisher)
{
    Publisher* new_publisher = new Publisher(id, email, username, password, age, publisher);
    users.push_back(new_publisher);
}

User* Network::find_user(string username, string password)
{
    for (int i = 0; i < users.size(); i++)
        if(users[i]->get_username() == username && users[i]->get_password() == password)
            return users[i];
    throw BadRequest();
}

void Network::login(string username, string password)
{
    find_logged_in_user()->logout();
    find_user(username, password)->login_user();
}
