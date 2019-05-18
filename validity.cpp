#include "definitions.h"
#include "validity.h"

using namespace std;

Validity::Validity()
{

}

bool Validity::check_correct_input(map<string, string> elements)
{
    for(auto& element: elements)
        if(element.second == SEPERATOR && element.first != PUBLISHER)
            return false;
    return true;
}

bool Validity::signup_validity(map<string, string> elements)
{
    return check_correct_input(elements) && check_integer(elements[AGE]) && check_email(elements[EMAIL]) && check_publisher(elements[PUBLISHER]);
}

bool Validity::add_film_validity(map<string, string> elements)
{
    return check_correct_input(elements) && check_integer(elements[YEAR]) && check_integer(elements[LENGTH]) && check_integer(elements[PRICE]);
}

bool Validity::login_validity(map<string, string> elements)
{
    return check_correct_input(elements);
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

bool Validity::check_publisher(string publisher)
{
    if(publisher == "true" || publisher == "false" || publisher == "?")
        return true;
    return false;
}