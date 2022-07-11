//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 4 - Problem 2

//pseudo code:
/*

get user input
test if valid

have a loop going, stop once n is 1, if its 0 dont print
    if even next val is floor of sqrt(n)
    else, its odd, next val is floor of sqrt(n) ^3


*/


#include <iostream>
#include <cmath>

using namespace std;


int main(){

    //get user input
    long int n = 0;
    cout << "Enter a positive integer:" << endl;
    cin >> n;

    //test if valid
    if(n <= 0){
        cout << "Invalid input." << endl;
    }else{

        //valid input


        //have a loop going, stop once n is 1, if its 0 dont print
        while(n >= 1){

            //print whatever n is
            cout << n << endl;

            //saftet statment, this will make it so if it gets to 1, 
            // then it will break the loop
            if(n == 1){
                n = 0;
            }

            
            if(n%2 == 0){
                //if even next val is floor of sqrt(n)
                n = sqrt(n);
                n = floor(n);
            }else{
                //else, its odd, next val is floor of sqrt(n) ^3
                n = pow( sqrt(n) , 3);
                n = floor(n);
            }
            
        }
            
    }

    
    

    return 0;
}