#include "publisher.h"
#include "exceptions.h"

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

void Publisher::delete_film(int film_id)
{
    for (int i = 0; i < publishered_films.size(); i++)
        if(publishered_films[i]->get_id() == film_id)
            publishered_films.erase(publishered_films.begin() + i);
    throw Inaccessibility();
}

