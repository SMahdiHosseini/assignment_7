#ifndef NOTIF_H
#define NOTIF_H

#include <iostream>

class Notification
{
public:
    Notification(std::string _massage);
    void show_massage();
    void read_massage();
private:
    std::string massage;
    bool read;
};

#endif