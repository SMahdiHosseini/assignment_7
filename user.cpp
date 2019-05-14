#include "user.h"
#include "exceptions.h"

#define DEFAULT_CASH 0

using namespace std;

User::User(int _id, std::string _email, std::string _username, std::string _password, int _age, bool _publisher)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    id = _id;
    publisher = _publisher;
    login = true;
    cash = DEFAULT_CASH;
}

void User::follow_publisher(Publisher* new_publisher)
{
    following_publishers.add_existed_publisher(new_publisher);
    send_follow_notification(new_publisher);
}

void User::send_follow_notification(Publisher* publisher)
{
    Notification new_notif("User " + username + " width id " + to_string(id) + " follow you");
    publisher->give_notification(new_notif);
}

void User::give_notification(Notification notification)
{
    notifications.push_back(notification);
}

void User::buy_film(Film* new_film, Publisher* publisher)
{
    bought_films.add_film(new_film);
    send_buy_notification(publisher, new_film);
}

void User::send_buy_notification(Publisher* publisher, Film* film)
{
    Notification new_notif("User " + username + " width id " + to_string(id) + 
        " buy your film " + film->get_name() + " width id " + to_string(film->get_id()) + ".");
    publisher->give_notification(new_notif);
}

void User::rate_film(int film_id, int score)
{
    if(bought_films.check_film_exists(film_id))
    {
        Film* film = bought_films.find_film_by_id(film_id); 
        film->set_rate(score);
        send_rate_notification(following_publishers.find_publisher_by_id(film->get_publisher_id) , film);
    }
    throw BadRequest();
}

void User::send_rate_notification(Publisher* publisher, Film* film)
{
    Notification new_notif("User " + username + " width id " + to_string(id) + 
        " rate your film " + film->get_name() + " width id " + to_string(film->get_id()) + ".");
    publisher->give_notification(new_notif);
}

void User::increase_money(int amount)
{
    cash += amount;
}

string User::get_username()
{
    return username;
}

string User::get_password()
{
    return password;
}

string User::get_email()
{
    return email;
}

int User::get_id()
{
    return id;
}

bool User::check_login()
{
    return login;
}

bool User::check_publsher()
{
    return publisher;
}

void User::logout()
{
    login = false;
}

void User::login_user()
{
    login = true;
}

void User::add_film(Film* new_film)
{
    throw Inaccessibility() ;
}

void User::delete_film(int film_id)
{
    throw Inaccessibility();
}

void User::show_followers()
{
    throw Inaccessibility();
}

void User::get_money(int money)
{
    throw Inaccessibility();
}

void User::reply_commemt(int film_id, int comment_id, string comtent)
{
    throw Inaccessibility();
}

int User::find_film_index(int film_id)
{
    throw Inaccessibility();
}

void User::delete_comment(int film_id, int comment_id)
{
    throw Inaccessibility();
}

void User::add_follower(User* new_follower)
{
    throw Inaccessibility();
}