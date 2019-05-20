#include "film_repository.h"
#include "exceptions.h"
#include "definitions.h"

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

void FilmRepository::delete_film(int film_id)
{
    for (int i = 0; i < films.size(); i++)
        if(films[i]->get_id() == film_id)
            films.erase(films.begin() + i);
}

int FilmRepository::find_user_id_width_comment_id(int film_id, int comment_id)
{
    return find_film_by_id(film_id)->find_user_id_width_comment_id(comment_id);
}

bool FilmRepository::in_range_film(map<string, string> options, Film* film)
{
    if(options.size() == 0)
        return true;
    bool flag = true;
    for (auto &&option : options)
    {
        if(option.first == NAME && film->get_name() != option.second)
            flag = false;
        if(option.first == "min_rate" && film->get_rate() >= stoi(option.second))
            flag = false;
        if(option.first == "min_year" && film->get_year() >= stoi(option.second))
            flag = false;
        if(option.first == PRICE && film->get_price() >= stoi(option.second))
            flag = false;
        if(option.first == "max_year" && film->get_year() <= stoi(option.second))
            flag = false;
        if(option.first == DIRECTOR && film->get_director() != option.second)
            flag = false;
    } 
    return flag;
}

void FilmRepository::show_films(map<string, string> options)
{
    cout << "#. Film Id | Film Name | Film Length | Film price | rate | Production Year | Film Director\n";
    for (int i = 0; i < films.size(); i++)
        if(in_range_film(options, films[i]))
            cout << i << "." << films[i]->show() << endl;
}