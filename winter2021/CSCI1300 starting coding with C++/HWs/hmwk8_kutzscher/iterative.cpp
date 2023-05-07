//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

/*

pseudo code

fillCumulativeSumIterative

if the input is less than 0 print invalid input
    idk what they mean by "invalid input" so we'll figure 
    that one out later

find sum of guys in the vector rn
    make that its own funciton
if the cumulative sum is less than N
    insert sum into the end of the vector
    repeat finding the sum
else, stop

print out the vector

*/




#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

void fillCumulativeSumIterative();
int cumSum();


//this just returns the cumulative sum of all the stuff
// in the vector passed into the fucntion
int cumSum(vector<int> v1){
    int returnVal = 0;

    for(int i = 0; i < v1.size(); i++){
        returnVal += v1.at(i);
    }

    return returnVal;
}





void fillCumulativeSumIterative(int N){
    

    // if the input is less than 0 print invalid input
    //     idk what they mean by "invalid input" so we'll figure 
    //     that one out later
    if(N < 0){
        cout << "Invalid input." << endl;
    }else{
        
        //when we make this a 1, stop looping
        bool stopLooping = 0;

        //this is where we will temporarily store the current sum after
        // we calculate it
        int currentSum = 0;

        //this is the vector where we will store our numbers
        //we will print this at the end
        vector<int> v = {1};

        //keep looping until the contitions are met to stop adding things
        // to the vector
        while(stopLooping == 0){
            
            // find sum of guys in the vector rn
            //     make that its own funciton
            currentSum = cumSum(v);


            // if the cumulative sum is less than N
            if(currentSum < N){
                //littie, add the sum to the end
                v.push_back(currentSum);
                //     insert sum into the end of the vector
                //     repeat finding the sum
            }else{
                // else, stop
                stopLooping = 1;
            } 
        }

        //when we're all done looping, print the vector weve created
        for(int i = 0; i < v.size(); i++){
            cout << v.at(i) << " ";
        }
        cout << endl;






    }
}


int main(){

    int N = 4;
    fillCumulativeSumIterative(999);
    

    return 0;
}