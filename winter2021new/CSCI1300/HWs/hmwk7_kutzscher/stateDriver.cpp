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


//aight I guess this is just where we'll test stuff out
//g++ -std=c++11 stateDriver.cpp State.cpp
// ^ yoooo no need for do the join compilation it makes it freak out
//just do g++ stateDriver

int main(){

    //name
    //pop
    //sq mileage
    State cali("California", 69000, 420000);

    cout << "aight I hope it works" << endl;
    cali.setName("San Fransisco and up is Nor cal");
    cali.setPopulation(555555);
    cali.setSquareMileage(99999);
    cout << "our states name is: " << cali.getName() << endl;
    cout << "our states pop is: " << cali.getPopulation() << endl;
    cout << "our states sq milage is: " << cali.getSquareMileage() << endl;
    cout << "our states pop density is: " << cali.getPopulationDensity() << endl;

    return 0;
}
