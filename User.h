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
	void give_notification(string notification); 
	void show_unread_notifications();
	void show_notifications();
	void show_bought_films();
	void folow_publisher(int publisher_id);
	void increas_money(double amount);
	void search_film(Film* film);
	void buy_film(int film_id);
	void rate_film(int film_id, double score);
	void comment_on_film(int film_id, string content);
protected:
	string username;
	string password;
	string email;
	int id;
	bool login;
	bool publisher;
	double cash;
	vector<Film*> bought_films;
	vector<Notification> notifications; 
	vector<Publisher*> following_publishers;
};

#endif