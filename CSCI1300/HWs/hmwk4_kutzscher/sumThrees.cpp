//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 4 - Problem 1

//pseudo code:
/*

ask for input
check if valid
loop through all numbers between 0 and the number
if its divisible by 3 add to sum
return sum

*/


#include <iostream>

using namespace std;


int main(){

    
    int number = 0;
    int sum = 0;
    
    cout << "Enter a positive integer:" << endl;
    cin >> number;

    if(number < 0){
        cout << "Invalid input." << endl;
    }else{
        int i = 0;
        while(i <= number){
            if(i % 3 == 0){
                sum += i;
            }
            ++i;
        }
        cout << "Sum: " << sum << endl;
    }

    return 0;
}