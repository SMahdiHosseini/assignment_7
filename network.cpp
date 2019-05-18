#include "network.h"
#include "exceptions.h"
#include "publisher.h"

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
    cout << "OK\n";
}

void Network::login(string username, string password)
{
    users->login(username, password);
    cout << "OK\n";
}

void Network::add_film(string name, int year, int length, int price, string summary, string director)
{
    find_logged_in_user()->add_film(films->add_new_film(find_logged_in_user()->get_id(), name, year, length, price, summary, director));
    cout << "OK\n";
}

void Network::edit_film(int film_id, map<string, string> edited_options)
{
    if(users->check_publisher())
    {
        films->edit_film(find_logged_in_user()->get_id(), film_id, edited_options);
        cout << "OK\n";
        return;
    }
    throw Inaccessibility();
}

void Network::delete_film(int film_id)
{
    if(films->find_film_by_id(film_id) == nullptr)
        throw NotFound();
    find_logged_in_user()->delete_film(film_id);
    cout << "OK\n";
}

void Network::show_followers()
{
    find_logged_in_user()->show_followers();
}

void Network::get_money()
{
    find_logged_in_user()->get_money(cash[find_logged_in_user()->get_username()]);
    cout << "OK\n";
}

void Network::reply_comment(int film_id, int comment_id, std::string content)
{
    find_logged_in_user()->reply_commemt(users->find_user_by_id(films->find_user_id_width_comment_id(film_id, comment_id)), 
        film_id, comment_id, content);
    cout << "OK\n";
}

void Network::delete_comment(int film_id, int comment_id)
{
    find_logged_in_user()->delete_comment(film_id, comment_id);
    cout << "OK\n";
}

void Network::follow(int publisher_id)
{
    users->follow_publisher(publisher_id);
    cout << "OK\n";
}

void Network::increase_money(int amount)
{
    find_logged_in_user()->increase_money(amount);
}

void Network::buy_film(int film_id)
{
    Film* film = films->find_film_by_id(film_id);
    find_logged_in_user()->buy_film(film, users->find_publisher_by_id(film->get_publisher_id()));
    cash[users->find_publisher_by_id(film->get_publisher_id())->get_username()] += compute_cash(film_id);
    cout << "OK\n";
}

int Network::compute_cash(int film_id)
{
    int rate = films->find_film_by_id(film_id)->get_rate();
    int price = films->find_film_by_id(film_id)->get_price();
    if(rate < 5)
        return price * 0.8;
    if(rate >= 5 && rate < 8)
        return price * 0.9;
    if(rate >= 8)
        return price * 0.95;
}

void Network::rate_film(int film_id, int score)
{
    find_logged_in_user()->rate_film(film_id, score);
    cout << "OK\n";
}