#ifndef FILM_REPOS_H
#define FILM_REPOS_H

#include "film.h"

class FilmRepository
{
public:
    FilmRepository();
    Film* add_new_film(int publisher_id, std::string name, int year, int length, int price, std::string summary, std::string director);
    void add_film(Film* film);
    void edit_film(int publisher_id, int film_id, std::map<std::string, std::string> edited_options);
    bool check_film_exists(int film_id);
    Film* find_film_by_id(int film_id);
private:
    int last_id;
    std::vector<Film*> films;
};

#endif