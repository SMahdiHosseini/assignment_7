#include "film_repository.h"

using namespace std;

FilmRepository::FilmRepository()
{
    last_id = 0;
}

Film* FilmRepository::add_film(int publisher_id, std::string name, int year, int length, int price, std::string summary, std::string director)
{
    // Film* new_film = new Film()
}
