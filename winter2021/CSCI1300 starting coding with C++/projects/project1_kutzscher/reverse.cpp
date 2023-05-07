//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 1 - Problem 1

//pseudo code:
/*

get user input
call reverse function

reverse:
take number and loop through indexing from the last didget
for each didget add each character to a new variable
when finished print the new variable


*/


#include <iostream>
using namespace std;

void reverse(string number){
    
    string revNumber = "";

    //this guy will be so we can move around one didget 
    string nChar = "";
    

    //lets loop though the number backwords, each didget
    //add to the end of the new string
    for(int i = number.length(); i--; i <= 0){
        //cout << number.substr(i, 1) << endl;

        nChar = number.substr(i, 1);

        revNumber.append(nChar);
    }

    cout << revNumber << endl;
}


int main(){
    
    

    string response = " ";
    cout << "gimmie ya numba lmao" <<endl;
    cin >> response;

    reverse(response);
    
    

    return 0;
}