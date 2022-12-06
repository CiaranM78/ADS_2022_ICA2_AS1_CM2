#pragma once


#include <iostream>
#include <string>
#include "Date.h"
#include "TNode.h"
#include "BSTNode.h"


using namespace std;

class Student
{
private:

    string user_id;
    string current_ranking;
    string first_name;
    string surname;
    string gender;
    string DOB;
    string email;
    string phone;
    string postcode;
    string address;
    string country;
    string lastlogin;
    string lastlogintime;
    string joined_on;
    string account_credit;

    


public:

    Student(string user_id, string current_ranking, string first_name) :
        user_id(user_id), current_ranking(current_ranking), first_name(first_name), surname(""),
        gender(""), DOB(DOB), email(""),
        phone(""), postcode(""), address(""),
        country(""), lastlogin(""), lastlogintime(""),
        joined_on(""), account_credit("")
    {

    }

    Student(string user_id, string current_ranking, string first_name, string surname,
        string gender, string DOB, string email,
        string phone, string postcode, string address, string country, string lastlogin, string lastlogintime, 
        string joined_on, string account_credit) :
        user_id(user_id), current_ranking(current_ranking), first_name(first_name), surname(surname),
        gender(gender), DOB(DOB), email(email),
        phone(phone), postcode(postcode), address(address),
        country(country), lastlogin(lastlogin), lastlogintime(lastlogintime),
        joined_on(joined_on), account_credit(account_credit)
    {

    }

    string getuser_id() const { return this->user_id; }
    string getcurrent_ranking() const { return this->current_ranking; }
    string getfirst_name() const { return this->first_name; }
    string getsurname() const { return this->surname; }
    string getgender() const { return this->gender; }
    string getDOB() const { return this->DOB; }
    string getemail() const { return this->email; }
    string getphone() const { return this->phone; }
    string getpostcode() const { return this->postcode; }
    string getaddress() const { return this->address; }
    string getcountry() const { return this->country; }
    string getlastlogin() const { return this->lastlogin; }
    string getlastlogintime() const { return this->lastlogintime; }
    string getjoined_on() const { return this->joined_on; }
    string getaccount_credit() const { return this->account_credit; }





    bool operator==(const Student& student)
    {
        return this->user_id == student.user_id
            && this->current_ranking == student.current_ranking
            && this->first_name == student.first_name
            && this->surname == student.surname
            && this->gender == student.gender
            && this->DOB == student.DOB
            && this->email == student.email
            && this->postcode == student.postcode
            && this->address == student.address
            && this->lastlogintime == student.lastlogintime
            && this->joined_on == student.joined_on
            && this->account_credit == student.account_credit;
    }


    friend ostream& operator<<(ostream& output, Student& student) {
        output << student.user_id << ",";
        output << student.current_ranking << ",";
        output << student.first_name << ",";
        output << student.surname << ",";
        output << student.gender << ",";
        output << student.DOB << ",";
        output << student.email << ",";
        output << student.postcode << ",";
        output << student.address << ",";
        output << student.lastlogintime << ",";
        output << student.joined_on << ",";
        output << student.account_credit;

        return output;
    }









};