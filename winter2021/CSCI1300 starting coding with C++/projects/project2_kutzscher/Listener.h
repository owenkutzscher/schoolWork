//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2 - problem 6

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
#ifndef LISTENER_H
#define LISTENER_H

#include <cstring>
#include <iostream>
using namespace std;


class Listener{
    public: 

    //default constructor +paramaterized one
    Listener();

    Listener(string, int[], int);

    

    //mutators/setters
    void setListenerName(string);
    bool setPlayCountAt(int, int);

    //accessors/getters
    string getListenerName();
    int getPlayCountAt(int);
    int totalPlayCount();
    int getNumUniqueSongs();
    int getSize();

    private:
    //atributes, like variable declarations


    string listenerName;
    static const int size = 50;
    //int playCount[size];
    int playCount[50]; //if errors pop up then ajust these guys


};


//endif
#endif