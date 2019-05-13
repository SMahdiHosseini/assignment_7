#ifndef FILM_REPOS_H
#define FILM_REPOS_H

#include "film.h"

class FilmRepository
{
public:
    FilmRepository();
    Film* add_film(int publisher_id, std::string name, int year, int length, int price, std::string summary, std::string director);
private:
    int last_id;
    std::vector<Film*> films;
};

#endif