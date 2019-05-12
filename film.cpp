#include "film.h"

using namespace std;

Film::Film(int _publisher_id, int _id, string _name, int _year, int _length, int price, string _suumary, string _director)
{
    name = _name;
    summary = _suumary;
    director = _director;
    year = _year;
    id = _id;
    publisher_id = _publisher_id;
}