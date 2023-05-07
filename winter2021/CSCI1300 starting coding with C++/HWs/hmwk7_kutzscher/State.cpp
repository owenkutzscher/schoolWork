//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 7 - Problem 1

//pseudo code:
/*

*/



#include <iomanip>
#include <fstream>
#include <cstring>



#include <iostream>
#include "State.h"

using namespace std;

//ok lets define all the shit from State.h
//llike all the functions and stuff



//class definition
//public interface




State::State(){
    //define some things and variables
    stateName = "";
    population = 0;
    squareMileage = 0;
}
State :: State(string stateName1, int population1, int squareMileage1){
    stateName = stateName1;
    population = population1;
    squareMileage = squareMileage1;
}





//setters 
void State :: setName(string newName){
    stateName = newName;
}

void State :: setPopulation(int population1){
    population = population1;
}
void State :: setSquareMileage(int squareMileage1){
    squareMileage = squareMileage1;
}






//getters
string State :: getName(){
    return stateName;
}

int State :: getPopulation(){
    return population;
}

int State :: getSquareMileage(){
    return squareMileage;
}

double State :: getPopulationDensity(){
    if(squareMileage <= 0 ){
        return 0;
    }else{
        return (1.0*population)/(1.0*squareMileage);
    }
    
}
