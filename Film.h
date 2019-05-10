#ifndef FILM_H
#define FILM_H

#include "Publisher.h"
#include "Comment.h"

using namespace std;

class Film
{
public:
    Film();
private:
    string name;
    string summary;
    string director;
    int year;
    int id;
    int publihser_id;
    double score;
    double length;
    double price;
    vector<Comment> comments;
};

#endif