#include "film.h"

#define NAME "name"
#define YEAR "year"
#define LENGTH "length"
#define SUMMATY "summary"
#define DIRECTOR "director"

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

int Film::get_id()
{
    return id;
}

int Film::get_publisher_id()
{
    return publisher_id;
}

void Film::edit_fields(string key, string value)
{
    if(key == NAME)
        name = value;
    if(key == YEAR)
        year = stoi(value);
    if(key == LENGTH)
        length = stoi(value);
    if(key == SUMMATY)
        summary = value;
    if(key == DIRECTOR)
        director = value;
}

void Film::edit(map<string, string> edited_options)
{
    for(auto& option : edited_options)
        edit_fields(option.first, option.second);
}

