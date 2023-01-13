//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: main.cpp
//-----------------------------------------------------------------------------

#include "HashOpenAddressing.h"
#include "HashChaining.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


/**********************************************************
 * COMMENTING SECTION
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *********************************************************
 */
 















/**
 * displayMenu - prints menu to terminal
 */
void displayMenu()
{
    cout << "========Main Menu=======" << endl;
    cout << "1. Populate hash tables" << endl;
    cout << "2. Search for a course" << endl;
    cout << "3. Search for a professor" << endl;
    cout << "4. Display all courses" << endl;
    cout << "5. Exit" << endl;
}







/**
 * main - runs the program and organizes output and operations
 * 
 * @param argc
 * @param argv
 * @return int
 */
int main (int argc, char* argv[])
{

    string programName = argv[0];
    string fileName = argv[1];
    int hashTableSize = stoi(argv[2]);

    int loopCounter = 0;      // breaks loop after 100 menu accesses
    string userInput = " ";      // you guesses it. It takes in user input

    bool validInput = false;    // keeps looping when a user enters invalid input inside an option

    // option 2 - search for a course
    int courseYear = 0;
    int courseNumber = 0;
    string profId = " ";

    if(argc != 3)    // if incorrect number arguments passed, print this and exit
    {
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: ./<program name> <csv file> <hashTable size>" << endl;
        return 0;
    }








    // this way of declaring puts "" on the stack. Using "new" puts it on the heap
    // HashOpenAddressing hashOpen = HashOpenAddressing(hashTableSize);      // create hash tables with user entered size
    HashOpenAddressing hashOpen(hashTableSize);
    HashChaining hashChain(hashTableSize);







    
    while(loopCounter < 100)
    {
        loopCounter++;
        displayMenu();
        getline(cin, userInput);

        //11111111111111111111111111111111111111111111111111111
        if(userInput == "1") // build schedule
        {
            cout << "[OPEN ADDRESSING] Hash table populated" << endl;
            cout << "-------------------------------------" << endl;
            hashOpen.bulkInsert(fileName);   // populate hash table with entered csv file
            // print statments with collisions and search built into the bulk insert functions

            cout << "[CHAINING] Hash table populated" << endl;
            cout << "-------------------------------------" << endl;
            hashChain.bulkInsert(fileName);   // populate hash table with entered csv file
            // print statments with collisions and search built into the bulk insert functions








        }
        //22222222222222222222222222222222222222222222222
        else if(userInput == "2") // search for a course
        {
            cout << "Enter the course year (e.g. 2021)" << endl;
            getline(cin, userInput);
            int courseYear = stoi(userInput);
            cout << "Enter the course number (e.g. 2270)" << endl;
            getline(cin, userInput);
            int courseNumber = stoi(userInput);
            cout << "Enter a professors ID (e.g. llytellf)" << endl;
            getline(cin, userInput);
            string profId = userInput;

            // all other print statments in search()
            hashOpen.search(courseYear, courseNumber, profId);

            // all other print statments in search()
            hashChain.search(courseYear, courseNumber, profId);








        }
        //33333333333333333333333333333333333333333333333333
        else if(userInput == "3") // search for a professor
        {
            cout << "Enter a Professor's ID (e.g. nscollan0" << endl;
            getline(cin, userInput);

            cout << "[OPEN ADDRESSING] Search for a professor" << endl;
            cout << "------------------------------------" << endl;
            hashOpen.profDb.publicSearchProfessor(userInput);    // before we do this, lets make sure 
            cout << endl;

            cout << "[CHAINING] Search for a professor" << endl;
            cout << "-----------------------------------------" << endl;
            hashChain.profDb.publicSearchProfessor(userInput);    // before we do this, lets make sure 
            cout << endl;







        }
        //44444444444444444444444444444444444444444444444
        else if(userInput == "4") // display all courses
        {
            

            while(validInput == false)
            {
                cout << "Which hash table would you like to display the courses for (O = Open Addressing, C = Chaining?" << endl;
                getline(cin, userInput);
                if(userInput == "O")
                {
                    validInput = true;
                    cout << "[OPEN ADDRESSING] displayAllCourses()" << endl;
                    cout << "-------------------------------------" << endl;
                    hashOpen.displayAllCourses();
                }
                else if(userInput == "C")
                {
                    validInput = true;
                    cout << "[CHAINING] displayAllCourses()" << endl;
                    cout << "-------------------------------------" << endl;
                    hashChain.displayAllCourses();
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }








            
            
        }
        //55555555555555555555555555555555555555555555555555
        else if(userInput == "5") // exit
        {
            cout << "Exiting..." << endl;
            return 0;






        }
        else // invalid input
        {

        }

        validInput = false;     // set this for out loops for valid input
    }
    return 0;
}