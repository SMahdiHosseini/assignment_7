#include "publisher.h"

#define DEFAULT_CASH 0

using namespace std;

Publisher::Publisher(int _id, std::string _email, std::string _username, std::string _password, int _age, bool _publisher)
 : User(_id, _email, _username, _password, _age, _publisher) 
{
}

void Publisher::add_film(Film* new_film)
{
    publishered_films.push_back(new_film);
}

