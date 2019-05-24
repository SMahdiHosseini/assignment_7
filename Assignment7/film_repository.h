#ifndef FILM_REPOS_H
#define FILM_REPOS_H

#include "film.h"
#include <iostream>

class FilmRepository
{
public:
    FilmRepository();
    ~FilmRepository();
    Film* add_new_film(int publisher_id, std::string name, int year, int length, int price, std::string summary, std::string director);
    void add_film(Film* film);
    void edit_film(int publisher_id, int film_id, std::map<std::string, std::string> edited_options);
    void delete_film(int film_id);
    void show_films(std::map<std::string, std::string> optiions);
    void show_film_details(int film_id);
    void show_recomend_film(std::vector<int> bought_films_id, int film_id);
    std::vector<std::pair<int, int>> sort_pairs_by_rate();
    std::vector<int> in_range_films_id(std::map<std::string, std::string> optiions);
    std::vector<int> get_films_id();
    bool in_range_film(std::map<std::string, std::string> optiions, Film* film);
    bool check_film_exists(int film_id);
    bool existed(std::vector<int> bought_films_id, int id);
    int find_user_id_with_comment_id(int film_id, int comment_id);
    Film* find_film_by_id(int film_id);
private:
    int last_id;
    std::vector<Film*> films;
};

#endif 