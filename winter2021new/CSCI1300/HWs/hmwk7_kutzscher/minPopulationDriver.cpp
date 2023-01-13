//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 7 - Problem 1

//pseudo code:
/*




*/


#include <iostream>
#include <cstring>

#include "State.h"
#include "State.cpp"

using namespace std;


int minPopulation(State states[], int SIZE){
    if(SIZE <= 0){
        return -1;
    }else{

    
    int indexMin = 0;
    //int smallestPop = states[0].getPopulation();

    for(int i = 0; i < SIZE; i++){

        if( states[i].getName() != ""){
            if( states[i].getPopulation() < states[indexMin].getPopulation() ){
                indexMin = i;
            }
        }
        
    }

    return indexMin;
    }
}





int main(){

    //name
    //pop
    //sq mileage
    State cali("California", 69000, 420000);
    State nevada("Nevada", 455, 667000);
    State utah("Fuck Utah",222333, 999666);
    int SIZE = 6;
    State states[SIZE] = {cali, nevada, utah};

    cout << "the min pop is: " << minPopulation(states, SIZE) << endl;

    for(int i = 0; i < SIZE; i++){
        cout << states[i].getPopulation() << endl;
    }
    
    return 0;
}
