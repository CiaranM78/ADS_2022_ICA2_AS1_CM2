#include "CSV.h"




CSV::CSV(string user_id, string surname, string postcode)
{
    this->user_id = user_id;
    this->surname = surname;
    this->postcode = postcode;
}


string CSV::getID()
{
    return user_id;
}
string CSV::getName()
{
    return surname;
}
string CSV::getEmail()
{
    return postcode;
}

string CSV::to_string()
{
    return this->user_id + " - " + this->surname + " - " + this->postcode;
}