#ifndef FILM_H
#define FILM_H

#include "publisher.h"
#include "comment.h"
#include "notification.h"
#include "comment_repository.h"

class Film
{
public:
    Film(int _publisher_id, int _id, std::string _name, int _year, int _length, int price, std::string _suumary, std::string _director);
    int get_id();
    std::string get_name();
    std::string get_summary();
    std::string get_director();
    int get_year();
    int get_id();
    int get_length();
    int get_price();
    int get_publisher_id();
    int get_rate();
    void set_rate(int score);
    void delete_comment(int comment_id);
    void reply_comment(int comment_id, std::string content, Notification notification);
    void edit(std::map<std::string, std::string> edited_options);
    void edit_fields(std::string key, std::string value);
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
    CommentRepository comments;
};

#endif