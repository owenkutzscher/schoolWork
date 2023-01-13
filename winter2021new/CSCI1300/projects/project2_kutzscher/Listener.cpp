//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2 - problem 6

//pseudo code:
/*

*/



#include <iomanip>
#include <fstream>
#include <cstring>



#include <iostream>
#include "Listener.h"

using namespace std;

//ok lets define all the shit from State.h
//llike all the functions and stuff



//class definition
//public interface



//deafult guys +paramaterized boi

Listener::Listener(){
    listenerName = "";
    size;
    playCount[size]; //if errors pop up then ajust these guys

    for(int i = 0; i < size; i++){
        playCount[i] = 0;
        //cout << "initialized element: " << i << " to " << playCount[i] << endl;
    }

    

}

//so this guy fills the rest of the array with zeros. after the guy passed in

Listener::Listener(string s, int a[], int numSongs){
    listenerName = s;
    size;

    playCount[size];

    
    

    if(numSongs <= 50){
        
        for(int i = 0; i < numSongs; i++)
        playCount[i] = a[i];

        for(int i = numSongs; i < 50; i++)
        playCount[i] = 0;
    
    }else{
        for(int i = 0; i < 50; i++)
        playCount[i] = a[i];
    }
}




//setters 



//mutators/setters
    void Listener::setListenerName(string s){
        listenerName = s;
    }

    bool Listener::setPlayCountAt(int index, int value){

        bool returnV = 0;

        if((index >= 0) && (index < 50)){
            playCount[index] = value;
            returnV = 1;
        }

        return returnV;
        
    }



/**/


//getters

//accessors/getters
string Listener::getListenerName(){
    return listenerName;
}
int Listener::getSize(){
    return size;
}
int Listener::getPlayCountAt(int index){
    if((index >= 0) && (index < 50)){
        return playCount[index];
    }else{
        return -1;
    }
    
}

//ngl pretty easy to figure out what this one does
int Listener::totalPlayCount(){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += playCount[i];
    }
    return total;
}

//any song that's got more than 1 play counts
//check for duplicate songs? no
int Listener::getNumUniqueSongs(){
    int numUniqueSongs = 0;
    for(int i = 0; i < size; i++){
        if(playCount[i] >= 1){
            numUniqueSongs++;
        }
    }

    return numUniqueSongs;

}


