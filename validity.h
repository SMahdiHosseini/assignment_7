#ifndef VALID_H
#define VALID_H

#include <iostream>

class Validity
{
public:
    bool check_integer(std::string integer);
    bool check_email(std::string email);
    bool check_publisher(std::string input);
    bool signup_validity(std::string age, std::string email, std::string publisher);
private:  
};

#endif