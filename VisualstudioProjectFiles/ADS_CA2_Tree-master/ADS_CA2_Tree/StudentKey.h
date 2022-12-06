#pragma once
#pragma once


#include <iostream>
#include <string>
#include "Date.h"
#include "TNode.h"
#include "BSTNode.h"


using namespace std;

class StudentKey
{
private:

    string user_id;
 
    string surname;

    string postcode;
  
  


public:


    StudentKey(string user_id, string surname,
          string postcode) :
        user_id(user_id), surname(surname),postcode(postcode)
        
   
    {

    }

    StudentKey() {}

    string getuser_id() const { return this->user_id; }
   
    string getsurname() const { return this->surname; }
   
    
    string getpostcode() const { return this->postcode; }
    

  


    friend ostream& operator<<(ostream& output, StudentKey& student) {
        output << student.user_id << ",";
  
        output << student.surname << ",";

        output << student.postcode;
        
 
        return output;
    }





    std::size_t hash() const
    {
        //What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
        //What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
        size_t hash = std::hash<string>()(this->user_id)
            + 31 * std::hash<string>()(this->surname)
            + 57 * std::hash<string>()(this->postcode);
        return hash;
    }


};