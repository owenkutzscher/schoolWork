//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 4

//pseudo code:
/*

function
    go through each  row
        for each row, find the largest int and store it
    
    multiply the largest ints and return it


*/


#include <iostream>
using namespace std;

int maxProd(int arr[][10], int rowsNUM){

    //we will initilaize the product to 1 becuase it will
    // be getting multiplied by numbers
    int product = 1;

    

    //lets loop through the rows
    for(int i = 0; i < rowsNUM; i++){
        
        //this guy we will use to find th elargest number in a row
        int largestInTheRow = arr[i][0];

        //now that we are in a row, lets loop through the columns
        // and find the largest number
        for(int k = 0; k < 10; k++){
            if(arr[i][k] > largestInTheRow){
                largestInTheRow = arr[i][k];
            }
        }

        //now that we found the largest in the row, multiply it to
        // the product
        product = product * largestInTheRow;
    }




    return product;
}

int main(){
    int arr[2][10] = {
        {9,2,2,3,5,7,9,7,6,8},
        {6,8,3,9,0,2,3,3,10,6}
    };

    maxProd(arr, 2);

    return 0;
}