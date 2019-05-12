#ifndef FILM_H
#define FILM_H

#include "publisher.h"
#include "comment.h"

class Film
{
public:
    Film(int _publisher_id, int _id, std::string _name, int _year, int _length, int price, std::string _suumary, std::string _director);
private:
    std::string name;
    std::string summary;
    std::string director;
    int year;
    int id;
    int publisher_id;
    int score;
    int length;
    int price;
    std::vector<Comment> comments;
};

#endif