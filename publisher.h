#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "user.h"
#include "film.h"
#include "film_repository.h"

class Publisher : public User
{
public:
    Publisher(int _id, std::string _email, std::string _username, std::string _password, int _age, bool _publisher) 
    : User(_id, _email, _username, _password, _age, _publisher);
    virtual void sent_reply_comment_notif(int film_id, int comment_id);
    virtual int find_film_index(int film_id);
    virtual void add_film(Film* new_film);
    virtual void delete_film(int film_id);
    virtual void show_followers();
    virtual void show_films();
    virtual void get_money(int money);
    virtual void delete_comment(int film_id, int comment_id);
    virtual void reply_commemt(int film_id, int comment_id, std::string content);
    virtual void delete_comment(int film_id, int comment_id);
private:
    std::vector<User*> follower_user;
    std::vector<Film*> published_films;
};

#endif