#pragma once
#include <string>

using namespace std;



class CSV
{

	string user_id;
	string surname;
	string postcode;
public:

	CSV(string user_id, string surname, string postcode);

	string getID();
	string getName();
	string getEmail();

	string to_string();

};