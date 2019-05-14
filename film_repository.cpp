#include "film_repository.h"
#include "exceptions.h"

using namespace std;

FilmRepository::FilmRepository()
{
    last_id = 0;
}

Film* FilmRepository::add_new_film(int publisher_id, std::string name, int year, int length, int price, std::string summary, std::string director)
{
    last_id++;
    Film* new_film = new Film(publisher_id, last_id, name, year, length, price, summary, director);
    films.push_back(new_film);
    return new_film;
}

Film* FilmRepository::find_film_by_id(int film_id)
{
    for (int i = 0; i < films.size(); i++)
        if(films[i]->get_id() == film_id)
            return films[i];
    throw BadRequest();
}

void FilmRepository::edit_film(int publisher_id, int film_id, std::map<std::string, std::string> edited_options)
{
    if(find_film_by_id(film_id)->get_publisher_id() == publisher_id)
    {
        find_film_by_id(film_id)->edit(edited_options);
        return;
    }
    throw Inaccessibility();
}

void FilmRepository::add_film(Film* film)
{
    if(!check_film_exists(film->get_id()))
        films.push_back(film);
}

bool FilmRepository::check_film_exists(int film_id)
{
    for (int i = 0; i < films.size(); i++)
        if(films[i]->get_id() == film_id)
            return true;
    return false;
}