#include "network.h"
#include "exceptions.h"

#define DEFAULT_CASH 0

using namespace std;

Network::Network()
{
    users = new UserRepository(); 
    films = new FilmRepository();
}

User* Network::find_logged_in_user()
{
    return users->find_logged_in_user();
}

bool Network::check_existed_user(string username)
{
    return users->check_existed_user(username);
}

void Network::signup(string email, string username, string password, int age, bool publisher)
{
    users->signup(email, username, password, age, publisher);
    cout << "OK";
}

User* Network::find_user(string username, string password)
{
    users->find_user(username, password);
}

void Network::login(string username, string password)
{
    users->login(username, password);
    cout << "OK";
}

void Network::add_film(string name, int year, int length, int price, string summary, string director)
{
    if(users->check_publisher())
    {
        find_logged_in_user()->add_film(films->add_new_film(find_logged_in_user()->get_id(), name, year, length, price, summary, director));
        cout << "Ok";
        return;
    }
    throw Inaccessibility();
}

void Network::edit_film(int film_id, map<string, string> edited_options)
{
    if(users->check_publisher())
    {
        films->edit_film(find_logged_in_user()->get_id(), film_id, edited_options);
        cout << "Ok";
        return;
    }
    throw Inaccessibility();
}

void Network::delete_film(int film_id)
{
    if(films->find_film_by_id(film_id) == nullptr)
        throw NotFound();
    find_logged_in_user()->delete_film(film_id);
    cout << "Ok";
}

void Network::show_followers()
{
    find_logged_in_user()->show_followers();
}

void Network::get_money()
{
    find_logged_in_user()->get_money(cash[find_logged_in_user()->get_username]);
    cout << "Ok";
}

void Network::reply_comment(int film_id, int comment_id, std::string content)
{
    find_logged_in_user()->reply_commemt(film_id, comment_id, content);
    cout << "Ok";
}

void Network::delete_comment(int film_id, int comment_id)
{
    find_logged_in_user()->delete_comment(film_id, comment_id);
    cout << "Ok";
}