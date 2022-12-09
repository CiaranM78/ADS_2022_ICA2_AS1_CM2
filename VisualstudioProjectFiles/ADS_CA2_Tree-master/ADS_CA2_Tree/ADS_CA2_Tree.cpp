// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "TNode.h"

#include "Util.h"
//#include "BinaryTree.h"
#include "String"
#include "Date.h"
#include "Student.h"
#include "StudentKey.h"
#include <random>
#include "Benchmark.h"

using namespace std;


void demoBenchmarkVectorFindLast();
void readCsv()
{
    TNode<StudentKey, Student*> tree;
    //size_t key;
    string line;
    ifstream fin("Data_1000.txt");
    if (fin)


    {

        while (!fin.eof())
        {
            getline(fin, line);
            //cout << line << endl;
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
            // storing all of the value within the tree
            Student *Pinfo = new Student(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12], data[13], data[14]);
            StudentKey key(data[0], data[3], data[8]);
           
            
            // adding the values to the tree
            tree.add(key, Pinfo);
            
           
            // searching the tree to see if the key i am looking for exists - would have to modify the search method so that i can use a custom key when searching
            // this would then locate the key and give back the data associated with the key
            tree.search(key);
            
     
        }
        // printing the entire tree after storing values
        printBT(tree.root);

        //checking how many nodes in the tree
        cout << tree.count() << endl;
       
        
    }
    
}
        
        
      

        int main()
        {
            
            // reading the CSV file
            readCsv();
            
            demoBenchmarkVectorFindLast();


        }















        /*********************************** Benchmarking ***********************************/

        // create a linked list from all of the values in the binary tree then plug that list instead of the vector to check the search speed
        // compare the speed between searching in a linked list and the binary tree





/// <summary>
/// Search for a T in a vector of T objects
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="value"></param>
/// <returns></returns>
/// 
/// 
/// 

        string getRandomString(size_t length)
        {
            const string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

            random_device random_device;
            mt19937 generator(random_device());
            uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

            std::string random_string;

            for (std::size_t i = 0; i < length; ++i)
            {
                random_string += CHARACTERS[distribution(generator)];
            }

            return random_string;
        }



        template <typename T>
        int linearSearch(vector<T> data, T value)
        {
            for (int i = 0; i < data.size(); i++)
                if (data[i] == value) return i;
            return -1;
        }

        /// <summary>
        /// A functor that we make to test the linearSearch in a vector - we need a functor because that's what measureTime takes!
        /// </summary>
        class LinearStringSearchFunctor {
            vector<string> data;
            string target;
        public:
            LinearStringSearchFunctor(vector<string> data, string target) : data(data), target(target) {};

            int operator()() {
                return linearSearch(data, target);
            }
        };

        vector<string> loadData(int N)
        {
            vector<string> data;

            //load data (e.g., random strings) into a vector (this is like your tree or linked list)
            int stringLength = 4;

            for (int i = 0; i < N; i++)
                data.push_back(getRandomString(stringLength));

            return data;
        }

        //lets benchmark how long it takes to find the last string in a vector
        //we should repeat the test below and run multiple tests on finding last string in a vector and get average run time
        void demoBenchmarkVectorFindLast() {
            //number of strings in the vector (like your CSV where N=1000,10000,100000)
            int N = 1000;

            //get some data (yours would be data from CSV in a list/vector vs your BinaryTree)
            vector<string> data = loadData(N);

            //pick the last string in the structure
            string searchString = data[data.size() - 1];

            /******************************* IMPORTANT PART > *******************************/
            int numberOfTests = 100;
            double totalTestTimeInNS = 0;
            for (int i = 0; i < numberOfTests; i++)
            {
                //make up the functor
                LinearStringSearchFunctor searchFunc(data, searchString);

                //pass the functor into measureTime
                totalTestTimeInNS += measureTime(searchFunc);
            }

            //get average across all tests
            double averageSearchTimeInMS = totalTestTimeInNS / numberOfTests;

            //convert ns to ms
            averageSearchTimeInMS /= 1000;

            //see how long it takes to find the string
            cout << "Vector - Average last element search time [Nr = " << N << ",Tests = " << numberOfTests << "]: " << averageSearchTimeInMS << "ms" << endl;

            /******************************* < IMPORTANT PART *******************************/
        }


   