#include "validity.h"

using namespace std;

bool Validity::signup_validity(string age, string email, string publisher)
{
    return check_integer(age) && check_email(email) && check_publisher(publisher);
}

bool Validity::check_integer(string integer)
{
    for (int i = 0; i < integer.size(); i++)
        if(integer[i] > '9' || integer[i] < '0')
            return false;
    return true;
}

bool Validity::check_email(string email)
{
    int seperator_count = 0;
    for (int i = 0; i < email.size(); i++)
        if(email[i] == '@')
            seperator_count++;
    if(seperator_count != 1)
        return false;
    return true;
}