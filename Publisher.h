#ifndef PUBLISHER_H
#define PUBLISHER_H
    
#include "User.h"
#include "Film.h"

class Publisher : public User
{
public:
    Publisher();
    void post_film(Film* new_film);
    void edit_film(int film_id, Film* edited_film);
    void delete_film(int film_id);
    void show_followers();
    void show_films();
    void post_money();
    void reply_commemt(int film_id, int comment_id, string content);
    void delete_comment(int film_id, int comment_id);
private:
    vector<User*> follower_user;
    vector<Film*> published_films;
};

#endif