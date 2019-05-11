#ifndef NOTIF_H
#define NOTIF_H

#include <iostream>

class Notification
{
public:
    Notification();
    void show_massage();
private:
    std::string massage;
    bool read;
};

#endif