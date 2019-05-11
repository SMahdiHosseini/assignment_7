#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Notification.h"
#include "Network.h"
#include "Publisher.h"
#include "Film.h"

using namespace std;

class User
{
public:
	User();
	string get_username() {return username;}
	string get_password() {return password;}
	int get_id() {return id;}
	bool check_login() {return login;}
	bool check_publsher() {return publisher;}
	void give_notification(string notification); 
	void show_unread_notifications();
	void show_notifications();
	void show_bought_films();
	void folow_publisher(int publisher_id);
	void increas_money(double amount);
	void search_film(Film* film);
	void buy_film(Film* new_film);
	void rate_film(Film* film, double score);
	void comment_on_film(int film_id, string content);
protected:
	string username;
	string password;
	string email;
	int id;
	bool login;
	bool publisher;
	int cash;
	int age;
	vector<Film*> bought_films;
	vector<Notification> notifications; 
	vector<Publisher*> following_publishers;
};

#endif