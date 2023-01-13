//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 7 - Problem 1

//pseudo code:
/*

class State{
    public: 
    
    //mutators/setters

    //accessors/getters

    private:

    //atributes, like variable declarations
}

*/


//pre proscessor
#ifndef STATE_H
#define STATE_H

#include <cstring>
#include <iostream>
using namespace std;


class State{
    public: 

    //default constructor
    State();

    //paramarized constructor
    State(string stateName, int population, int squareMileage);

    

    //mutators/setters
    void setName(string);
    void setPopulation(int);
    void setSquareMileage(int);


    //accessors/getters
    string getName();
    int getPopulation();
    int getSquareMileage();
    double getPopulationDensity();






    private:
    //atributes, like variable declarations

    string stateName;
    int population;
    int squareMileage;

};


//endif
#endif