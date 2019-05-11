#include "network.h"

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

void Network::signup(int id, string email, string username, string password, int age, bool publisher)
{
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

