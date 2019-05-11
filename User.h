#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Notification.h"
#include "Network.h"
#include "Publisher.h"
#include "Film.h"

class User
{
public:
	User() {};
	std::string get_username() {return username;}
	std::string get_password() {return password;}
	int get_id() {return id;}
	bool check_login() {return login;}
	bool check_publsher() {return publisher;}
	void give_notification(Notification notification); 
	void show_unread_notifications();
	void show_notifications();
	void show_bought_films();
	void folow_publisher(int publisher_id);
	void increas_money(double amount);
	void search_film(Film* film);
	void buy_film(Film* new_film);
	void rate_film(Film* film, double score);
	void comment_on_film(int film_id, std::string content);
	virtual void add_film(Film* new_film);
    virtual void edit_film(int film_id, Film* edited_film);
    virtual void delete_film(int film_id);
    virtual void show_followers();
    virtual void show_films();
    virtual void post_money();
    virtual void reply_commemt(int film_id, int comment_id, std::string content);
    virtual void delete_comment(int film_id, int comment_id);
protected:
	std::string username;
	std::string password;
	std::string email;
	int id;
	bool login;
	bool publisher;
	int cash;
	int age;
	std::vector<Film*> bought_films;
	std::vector<Notification> notifications; 
	std::vector<Publisher*> following_publishers;
};

#endif