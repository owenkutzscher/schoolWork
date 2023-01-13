//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 3

//pseudo code:
/*

function
    //get input
    //traverse array
        //if vowell is found, check if there is space
        //then move all letters down and add a 
        //capitalized version of the vowel behind th ecurrent vowel
    //return the num characters

*/


#include <iostream>
#include <cstring>
using namespace std;


int insert(char arr[], int numChar, int arrSIZE, int numVowels){

    //firt, if the number of characters + numvowels is greater than arrSIZE
    // then dont do anything
    if((numChar + numVowels) > arrSIZE){
        //literally do nothing
    }else{

    //first lets go through the list and if we find a vowel, we will
    //start moving around some letters
    for(int i = 0; i < arrSIZE; i++){
        
        //now lets see if the letter we are on is a vowel
        if((arr[i] == 'a')||(arr[i]=='e')||(arr[i]=='i')||(arr[i]=='o')||(arr[i]=='u')){
            //cout <<"we caught a vowel, in the act: " << arr[i] << endl;

            //killer, we caught a vowel
            //now we need to slide all the letters down 1 space, IFFF there is room
            //first lets check if theres room in the array, it could be all filled up with letters
            if(numChar < arrSIZE){

                //sick, weve got room to shove a letter in
                //now were going to move all the letters down
                //the simplest way to do this is to start from the end, and set the
                //  next value equal to the previous
                for(int r = arrSIZE-1; r > i; r--){
                    
                    //make the value on the end = to the previous and go to the left
                    arr[r] = arr[r-1];
                }

                //sick we made room, lets add a capitol letter
                // after where the og vowel is
                arr[i+1] = arr[i] - 32;





                //now that weve added a letter in, we need to correctly ajust the number of chars
                numChar++;

                //we also now are indexing past where we started since we moved everythng over, so
                i++;
            }
        }
    }
    
    }

    
    
    
    
    //return the current number of characters
    return numChar;
}

int main(){


    int arrTotalSIZE = 9;                      //3
    char arr[arrTotalSIZE] = "boulder";     //1
    int numCharCurrentInArr = 7;               //2
    
    int arrNumVowels = 3;                       //4

    cout << "running the function..." << endl;
    insert(arr, numCharCurrentInArr, arrTotalSIZE, arrNumVowels);

    cout << "new arr printed below:" << endl;
    for(int i = 0; i < arrTotalSIZE; i++){
        cout << arr[i] << endl;
    }

    return 0;
}