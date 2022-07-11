//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 2

//pseudo code:
/*

function
    take inputs
    loop through, find the min value, print it
    loop through, make product, print it
    loop thorugh, find avg, print it


*/


#include <iostream>
#include <iomanip>
using namespace std;

void stats(double arr[], int numElements){
    //cout << "stats funciton activated" << endl;
    //take inputs


    //loop through, find the min value, print it
    double minVal = 0.00;
    for(int i = 0; i < numElements; i++){
        if(i == 0){
            minVal = arr[i];
        }else if(arr[i] < minVal){
            minVal = arr[i];
        }
    }
    //pirnt
    cout << "Min: ";
    cout << fixed;
    cout << setprecision(3);
    cout << minVal << endl;


    //loop through, make the product, print it
    double prod = arr[0];
    for(int i = 1; i < numElements; i++){
        prod *= arr[i];
    }
    //pirnt
    cout << "Product: ";
    cout << fixed;
    cout << setprecision(3);
    cout << prod << endl;



    //loop through, make avg, print it
    double sum = 0.00;
    for(int i = 0; i < numElements; i++){
        sum += arr[i];
    }
    double avg = sum/numElements;
    //pirnt
    cout << "Avg: ";
    cout << fixed;
    cout << setprecision(3);
    cout << avg << endl;

    
}

int main(){

    cout << "lets try.. an array cheese and length of 5" << endl;
    double cheese[] = {1.00, 3.00, 5.69, 4.20, 6.333};
    int lengthE = 5;
    stats(cheese, lengthE);

    return 0;
}