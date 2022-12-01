// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TNode.h"
#include "CSV.h"


using namespace std;



void display(CSV& Pinfo)
{
    cout << Pinfo.to_string() << endl;
}



struct Personalinfo
{
    string user_id;
    string surname;
    string postcode;
    

};



void readCsv()
{
    string line;
    ifstream fin("Text.txt");
        if (fin)
        {
            while (!fin.eof())
            {
                getline(fin, line);
                //cout << line << endl;
                Personalinfo Pinfo;
                vector<string> items;
                string field = "";
                bool openData = false;
                for (int i = 0; i < line.length(); i++)
                {
                    if (line[i] == '"')
                    {
                        openData = !openData;
                    }

                    else if (!openData && line[i] == ',')
                    {
                        items.push_back(field);
                        field = "";
                    }


                    /*
                    else if (!openData && line[i] == '-')
                    {
                        items.push_back(field);
                    }
                    */


                    else {
                        field += line[i];
                    }
                }

                if (field != "")
                {
                    items.push_back(field);

                    

                }


                
                Pinfo.user_id = items[0];
                Pinfo.surname = items[1];
                Pinfo.postcode = items[2];
                cout << "=====================================" << endl;
                



                //--------------------------------------------------------------------------
                /*string line;
                ifstream fin("data_1000.txt");
                if (fin)
                {
                    while (!fin.eof())
                    {
                        getline(fin, line);
                        Personalinfo Pinfo;
                vector<string> CSVrow = splitString("WBC88XPE6LP", 70, "Colby, Burks", "Male"	10 / 07 / 1983, "rutrum.non@aol.org", 1 - 704 - 685 - 7028, 6723 EV	460 - 8248, "Tempor Rd.Peru", 11 / 11 / 2023, 03:23, 29 / 11 / 2018, $121; .31, ",");
                if (CSVrow.size() = 15)
                {
                    string make CSVrow[0];
                    string user_id CSVrow[1];
                    string current_ranking CSVrow[2];
                    string first_name CSVrow[3];


                }*/

                



            }



                }

            }
                
        

     

int main()
{
    std::cout << "bitmoji test!\n";

    readCsv();
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file




