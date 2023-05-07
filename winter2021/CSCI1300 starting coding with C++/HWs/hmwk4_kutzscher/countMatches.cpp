//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 4 - Problem 4

//pseudo code:
/*

get user input
have a loop looping through each letter
    and a loop inside that looping through every
    letter following that one
    if it matches then add one to a counter
return the count


*/


#include <iostream>
using namespace std;


int main(){
    //get user input
    string searchString = " ";
    cout << "Enter the search string:" << endl;
    cin >> searchString;

    string searchFor;
    cout << "Enter the substring to be searched:" << endl;
    cin >> searchFor;

    //have a loop looping through each letter
    int occurrences = 0;
    for(int i = 0; i < searchString.length(); i++){
        //cout << searchString.substr(i, 1) << endl;


        //cool, this loop will go through each letter
        //lets have another loop going through each following letters
        for(int k = 1; k < (searchString.length() - i + 1); k++){
            string testSubject = searchString.substr(i, k);
            //cout << testSubject << endl;
            if(testSubject == searchFor){
                occurrences++;
            }

        }

        

    }
        
    //return the count
    cout << "Number of occurrences: " << occurrences << endl;
    
    

    return 0;
}