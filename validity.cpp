#include "validity.h"

using namespace std;

bool Validity::signup_validity(string age, string email, string publisher)
{
    return check_integer(age) && check_email(email) && check_publisher(publisher);
}