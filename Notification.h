#ifndef NOTIF_H
#define NOTIF_H

#include <iostream>

using namespace std;

class Notification
{
public:
    Notification();
    void show_massage();
private:
    string massage;
    bool read;
};

#endif