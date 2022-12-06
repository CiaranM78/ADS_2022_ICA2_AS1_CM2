// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "TNode.h"
#include "CSV.h"
#include "Util.h"
#include "BinaryTree.h"
#include "String"
#include "Customer.h"
#include "Date.h"
#include "Student.h"
#include "StudentKey.h"

using namespace std;



void display(CSV& Pinfo)
{
    cout << Pinfo.to_string() << endl;
}









void demoSimpleHash() {
    //hasher for strings
    hash<string> hasherStr;
    string email = "john.smith@hotmail.com";
    cout << "hash[" << email << "]: " << hasherStr(email) << endl;

    //hasher for doubles
    hash<double> hasherDbl;
    double price = 123123.322;
    cout << "hash[" << price << "]: " << hasherDbl(price) << endl;

    //we can re-use a hasher
    double weight = 12345.9897;
    cout << "hash[" << weight << "]: " << hasherDbl(weight) << endl;

    //we can store the hash value using size_t (basically an unsigned int)
    size_t myHash = hasherStr("this is a hash value store in a uint");
    cout << myHash << endl;
}






void readCsv()
{
    BinaryTree<Student, Student> tree;
    size_t key;
    string line;
    ifstream fin("Text.txt");
    if (fin)


    {

        while (!fin.eof())
        {
            getline(fin, line);
            //cout << line << endl;
            Student Pinfo;
            vector<string> data;
            string field = "";
            bool quoteOpen = false;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '"')
                {
                    quoteOpen = !quoteOpen;
                }
                else if (!quoteOpen && line[i]
                    == ',')
                {
                    data.push_back(field);
                    field = "";
                }

                else
                {
                    field += line[i];
                }
            }
            if (field != "")
            {
                data.push_back(field);
            }
            
            
            // Hashing the variables stored
            // Hashing the user_id
            hash<string> hasherStr;
            string user_id = data[0];
            //cout << "hash[" << user_id << "]: " << hasherStr(user_id) << endl;

            //Hashing the surname
            string surname = data[3];
            //cout << "hash[" << surname << "]: " << hasherStr(surname) << endl;

            //Hashing the postcode
            string postcode = data[8];
            //cout << "hash[" << postcode << "]: " << hasherStr(postcode) << endl;



            

       
            key = hasherStr(user_id);
               + hasherStr(surname) + hasherStr(postcode);

          
            //cout << "key is" << " " << key << endl;

            

            
            Pinfo.user_id = data[0];
            Pinfo.surname = data[3];
            Pinfo.postcode = data[8];
            Pinfo.key = key;
            //cout << user_id << endl;
            //cout << items[3] << endl;
           // cout << items[8] << endl;
            //cout << "=====================================" << endl;
            
            
            
            tree.add(key, Pinfo);
            
           // tree.add(50);
           // tree.add(514789);
            //tree.add(627891);
            

            //tree.remove(2146364441);
            //tree.remove(2137056470);

            
     
        }
        
        printBT(tree.root);
      //  cout << tree.count() << endl;

     
        
    }
    
}
        
        
        


        int main()
        {
            
            
            readCsv();
            
            


        }








        /*
        vector<vector<string>> readDelimitedRows(string fileName)
        {
            ifstream fin(fileName);
            if (!fin)
                throw runtime_error(fileName + " was not found! Is file in the correct sub-folder with main CPP file?");

            string rowStr;
            string field = "";
            vector<vector<string>> allRows;
            vector<string> rowFields;

            while (!fin.eof())
            {
                getline(fin, rowStr);

                bool quoteOpen = false;
                for (int i = 0; i < rowStr.length(); i++)
                {
                    if (rowStr[i] == '"')
                    {
                        quoteOpen = !quoteOpen;
                    }
                    else if (!quoteOpen && rowStr[i] == ',')
                    {
                        rowFields.push_back(field);
                        field = "";
                    }
                    else
                    {
                        field += rowStr[i];
                    }
                }
                if (field != "")
                {
                    rowFields.push_back(field);
                }
                field = "";

                if (rowFields.size() != 0)
                    allRows.push_back(rowFields);

                rowFields.clear();
            }
            return allRows;
        }



        vector<string> splitString(string str, string delimiter)
        {
            vector<string> words;
            size_t pos = 0;
            std::string subString;
            while ((pos = str.find(delimiter)) != std::string::npos) {
                words.push_back(str.substr(0, pos));
                str.erase(0, pos + delimiter.length());
            }
            words.push_back(str);

            return words;
        }


        /*

        void demoCSVToObject()
        {
            //note: data is a sub-folder under the folder with main CPP file
            string fileName = "Text.Txt";
            vector<vector<string>> allData = readDelimitedRows(fileName);

            for (vector<string> row : allData) {
                for (string field : row) {
                    cout << field << ",";
                }
                cout << endl;
            }
        }

        /*
        void demoParseString()
        {
            string str = "ford, 2012, 1299.55, 25/12/2022";
            string delimiter = ",";

            vector<string> rowFromCSV = splitString(str, delimiter);

            if (rowFromCSV.size() == 4)
            {
                string make = rowFromCSV[0];
                int year = stoi(rowFromCSV[1]);
                double price = stod(rowFromCSV[2]);
                vector<string> dateWords = splitString(rowFromCSV[3], "/");

                if (dateWords.size() == 3)
                {
                    string user_id = dateWords[0];
                    string surname = dateWords[1];
                    string postcode = dateWords[2];


                    CSV registrationDate(user_id, surname, postcode);
                    cout << "Car: " << registrationDate << endl;
                }
            }
        }
        */

       

        // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
        // Debug program: F5 or Debug > Start Debugging menu

        // Tips for Getting Started: 
        //   1. Use the Solution Explorer window to add/manage files
        //   2. Use the Team Explorer window to connect to source control
        //   3. Use the Output window to see build output and other messages
        //   4. Use the Error List window to view errors
        //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
        //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


            /*

            void readCsv()
            {
                string line;
                ifstream fin("Text.txt");
                if (fin)
                {

                    while (!fin.eof())
                    {
                        getline(fin, line);
                        cout << line << endl;
                        Personalinfo Pinfo;
                        vector<string> items;
                        string field = "";
                        bool quoteOpen = false;
                        for (int i = 0; i < line.length(); i++)
                        {
                            if (line[i] == '"')
                            {
                                quoteOpen = !quoteOpen;
                            }
                            else if (!quoteOpen && line[i]
                                == ',')
                            {
                                items.push_back(field);
                                field = "";
                            }

                            else
                            {
                                field += line[i];
                            }
                        }
                        if (field != "")
                        {
                            items.push_back(field);
                        }


                        /*
                        Pinfo.user_id = stoi(items[0]);
                        Pinfo.surname = items[1];
                        Pinfo.postcode = items[2];
                        cout << "=====================================" << endl;
                        */


   