#include "network.h"
#include "exceptions.h"

#define DEFAULT_CASH 0

using namespace std;

Network::Network() {}

User* Network::find_logged_in_user()
{
    return users.find_logged_in_user();
}

bool Network::check_existed_user(string username)
{
    return users.check_existed_user(username);
}

void Network::signup(string email, string username, string password, int age, bool publisher)
{
    users.signup(email, username, password, age, publisher);
}

User* Network::find_user(string username, string password)
{
    users.find_user(username, password);
}

void Network::login(string username, string password)
{
    find_logged_in_user()->logout();
    find_user(username, password)->login_user();
}
