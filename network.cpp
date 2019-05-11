#include "network.h"

using namespace std;

User* Network::find_logged_in_user()
{
    for (int i = 0; i < users.size(); i++)
        if (users[i]->check_login())
            return users[i];
}

void Network::signup(string email, string username, string password, int age, bool publisher)
{
    
}