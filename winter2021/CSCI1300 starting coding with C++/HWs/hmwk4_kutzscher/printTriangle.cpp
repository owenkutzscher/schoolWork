//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 4 - Problem 5

//pseudo code:

    //get user input
    //make sure its not negative
    //print triangle looping thorugh alphabet
        //remember where you left off and continue looping thorugh,
        //subtracting 1 each time from the # of letters getting
        //put down in a row




#include <iostream>
using namespace std;


int main(){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    //get user input
    int height = 0;
    cout << "Enter the height:" << endl;
    cin >> height;

    //make sure its not negative
    if(height < 0){
        cout << "Invalid input." << endl;
    }else{
        int whereWeLeftOff = 0;
        //print triangle looping thorugh alphabet
        for(int i = height; i > 0; i--){
            //this is the loop for each row going down
            //remember where you left off and continue looping thorugh,
            //subtracting 1 each time from the # of letters getting
            //put down in a row
                
                
                
                
                /*
                if(whereWeLeftOff > alphabet.length()){
                    whereWeLeftOff -= alphabet.length();
                }
                */



            //now lets print the row going out to the right
            for(int k = i; k > 0; k--){
                string triLetter = alphabet.substr(whereWeLeftOff, 1);
                cout << triLetter;

                whereWeLeftOff += 1;
                if(whereWeLeftOff >= (int)alphabet.length()){
                    whereWeLeftOff = 0;
                }
            }
            cout << endl;
            
        }
            
    }
    
    
    

    return 0;
}