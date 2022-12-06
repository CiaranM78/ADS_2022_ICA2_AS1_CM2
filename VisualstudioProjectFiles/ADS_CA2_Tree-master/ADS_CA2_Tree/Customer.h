#pragma once
#include <ostream>
#include <string>
#include "Date.h"
using namespace std;

/// <summary>
/// Represents a row of data in a CSV file of Car records
/// </summary>
class Car {
#pragma region Fields
		string user_id;
	string current_ranking;
	string first_name;
	string surname;
	string gender;
	string date_of_birth;
	string email;
	string phone;
	string postcode;
	string address;
	string country;
	string last_log_on_date;
	string last_log_on_time;
	string joined_on;
	string account_credit;
#pragma endregion

public:

#pragma region Constructors
	Car( string user_id, string current_ranking, string first_name, string surname, string gender, string date_of_birth, string email, string phone, string postcode, string address, string country, string last_log_on_date, string last_log_on_time, string joined_on, string account_credit)
		:  user_id(user_id), current_ranking(current_ranking), first_name(first_name), surname(surname), gender(gender), date_of_birth(date_of_birth), email(email), phone(phone), postcode(postcode), address(address), country(country), last_log_on_date(last_log_on_date), joined_on(joined_on), account_credit(account_credit)
	{
	}
#pragma endregion


#pragma region Operators & Hash

	bool operator==(const Car& student)
	{
		return this->user_id == student.user_id
			&& this->current_ranking == student.current_ranking
			&& this->first_name == student.first_name
			&& this->surname == student.surname
		&& this->gender == student.gender
		&& this->date_of_birth == student.date_of_birth
		&& this->email == student.email
		&& this->phone == student.phone
		&& this->postcode == student.postcode
		&& this->address == student.address
		&& this->country == student.country
		&& this->last_log_on_date == student.last_log_on_date
		&& this->last_log_on_time == student.last_log_on_time
		&& this->joined_on == student.joined_on
		&& this->account_credit == student.account_credit;
	}
	}

	}

	friend ostream& operator<<(ostream& output, Car& student) {
		output << student.user_id << ",";
		output << student.current_ranking << ",";
		output << student.first_name << ",";
		output << student.surname
		output << student.gender << ",";
		output << student.date_of_birth << ",";
		output << student.email << ",";
		output << student.phone;
		output << student.postcode << ",";
		output << student.address << ",";
		output << student.country << ",";
		output << student.last_log_on_date;
		output << student.last_log_on_time;
		output << student.joined_on;
		output << student.account_credit;
		return output;
	}

	friend istream& operator>>(istream& input, Car& student) {
		string studentAsStr;
		input >> studentAsStr;

		return input;
	}

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<string>()(this->make)
			+ 31 * std::hash<int>()(this->year)
			+ 57 * std::hash<double>()(this->price)
			+ 349 * date.hash();
	}

#pragma endregion
};
















































//#pragma once
//#include <string>
//
//using namespace std;
//
//////struct customer {
////
////	string user_id;
////	string current_ranking;
////	string first_name;
////	string surname;
////	string gender;
////	string date_of_birth;
////	string email;
////	string phone;
////	string postcode;
////	string address;
////	string country;
////	string last_log_on_date;
////	string last_log_on_time;
////	string joined_on;
////	string account_credit;
////
////public:
////
////	customer();
////	customer(string user_id, string current_ranking, string first_name, string surname, string gender, string date_of_birth, string email, string phone, string postcode, string address, string country, string last_log_on_date, string last_log_on_time, string joined_on, string account_credit);
//	
//
//
//
//
//
//
//};