#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/ShowsList.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

    // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
    // DO NOT MODIFY ABOVE.

    // TODO

    // freopen in read mode asociates standard input with argv[1]
    // basically if you enter in a .txt file itll enter it in for
    //  us



    ////////// variables /////////
    string userInput = " "; // stores user input
    int whileLoopcounter = 100; // prevents user from entering > 100 inputs

    ShowsList aListOfShows; // contains the shows


    // for user enters 3 "add show"
    string newShow;
    string previousShow;

    // for user enters 4 "add rating"
    string showNeedsRating;
    string stringUpdateRating;
    double updatedRating;


    while( (whileLoopcounter > 0) )
    {

        // display menu and get user inputs
        displayMenu();
        getline(cin,userInput);

        if(userInput == "1") // build schedule
        {
            aListOfShows.buildShowsList();
            aListOfShows.displayShows();
        }
        else if(userInput == "2") // display shows
        {
            aListOfShows.displayShows();
        }
        else if(userInput == "3") // add show
        {
            
            cout << "Enter a new show name: " << endl;
            getline(cin,newShow);

            /*
            // check if the show is in the showList
            while(aListOfShows.searchShow(newShow) == nullptr) 
            {
                cout << "INVALID(new show name)... Please enter a VALID previous show name!" << endl;
                cin >> newShow;
            }
            */

            
            cout << "Enter the previous show name (or First): " << endl;
            getline(cin,previousShow);

            // check if the show is in the showList
            while(aListOfShows.searchShow(previousShow) == nullptr 
            && previousShow != "First") 
            {
                cout << "INVALID(previous show name)... Please enter a VALID previous show name!" << endl;
                getline(cin,previousShow);
            }

            if(previousShow == "First")
            {
                aListOfShows.addShow(nullptr, newShow);
            }
            else
            {
                aListOfShows.addShow(aListOfShows.searchShow(previousShow), newShow);

            }

            aListOfShows.displayShows();
        }
        else if(userInput == "4") // add rating
        {
            cout << "Enter name of the show to add the rating: " << endl;
            getline(cin, showNeedsRating);

            cout << "Enter the rating: " << endl;
            getline(cin, stringUpdateRating);

            updatedRating = stod(stringUpdateRating);
            aListOfShows.addRating(showNeedsRating, updatedRating);
            



        }
        else if(userInput == "5") // quit
        {
            cout << "Quitting..." << endl;
            whileLoopcounter = 0;
        }
        else // invalid input
        {

        }
        


        whileLoopcounter--;
    }
    cout << "Goodbye!" << endl;
    
    return 0;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build schedule " << endl;
    cout << " 2. Display Shows " << endl;
    cout << " 3. Add Show " << endl;
    cout << " 4. Add rating" << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
