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
    void delete_film(int film_id);
    void show_films(std::map<std::string, std::string> optiions);
    bool in_range_film(std::map<std::string, std::string> optiions, Film* film);
    bool check_film_exists(int film_id);
    int find_user_id_width_comment_id(int film_id, int comment_id);
    Film* find_film_by_id(int film_id);
private:
    int last_id;
    std::vector<Film*> films;
};

#endif