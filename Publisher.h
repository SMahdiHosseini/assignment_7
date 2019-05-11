#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "User.h"
#include "Film.h"

class Publisher : public User
{
public:
    Publisher();
    virtual void add_film(Film* new_film);
    virtual void edit_film(int film_id, Film* edited_film);
    virtual void delete_film(int film_id);
    virtual void show_followers();
    virtual void show_films();
    virtual void post_money();
    virtual void reply_commemt(int film_id, int comment_id, std::string content);
    virtual void delete_comment(int film_id, int comment_id);
private:
    std::vector<User*> follower_user;
    std::vector<Film*> published_films;
};

#endif