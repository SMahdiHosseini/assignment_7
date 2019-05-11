#ifndef FILM_H
#define FILM_H

#include "Publisher.h"
#include "Comment.h"

class Film
{
public:
    Film();
private:
    std::string name;
    std::string summary;
    std::string director;
    int year;
    int id;
    int publihser_id;
    int score;
    int length;
    int price;
    std::vector<Comment> comments;
};

#endif