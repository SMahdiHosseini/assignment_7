#include "Network.h"

User* Network::find_logged_in_user()
{
    for (int i = 0; i < users.size(); i++)
        if (users[i]->check_login())
            return users[i];
}

