#include "publisher.h"
#include "exceptions.h"

#define DEFAULT_CASH 0

using namespace std;

Publisher::Publisher(int _id, std::string _email, std::string _username, std::string _password, int _age, bool _publisher)
 : User(_id, _email, _username, _password, _age, _publisher) 
{
}

void Publisher::add_film(Film* new_film)
{
    published_films.push_back(new_film);
}

void Publisher::delete_film(int film_id)
{
    published_films.erase(published_films.begin() + find_film_index(film_id));
}

void Publisher::show_followers()
{
    cout << "List of Followers\n";
    cout << "#. User Id | User Username | User Email\n";
    for (int i = 0; i < follower_user.size(); i++)
    {
        cout << 1 << ". " << follower_user[i]->get_id() << " | ";
        cout << follower_user[i]->get_username() << " | ";
        cout << follower_user[i]->get_email() << endl;
    }
}

void Publisher::get_money(int money)
{
    cash += money;
}

void Publisher::reply_commemt(int film_id, int comment_id, string content)
{
    Notification new_notif("Publisher " + username + " width id " + to_string(id) + " reply to your comment.");
    published_films[find_film_index(film_id)]->reply_comment(comment_id, content, new_notif);
}

int Publisher::find_film_index(int film_id)
{
    for (int i = 0; i < published_films.size(); i++)
        if(published_films[i]->get_id() == film_id)
            return i;
    throw Inaccessibility();
}

void Publisher::delete_comment(int film_id, int comment_id)
{
    published_films[find_film_index(film_id)]->delete_comment(comment_id);
}
