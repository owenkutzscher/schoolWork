//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 7 - Problem 2

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
#ifndef SONG_H
#define SONG_H

#include <cstring>
#include <iostream>
using namespace std;


class Song{

    public: 

    //default constructor +paramaterized one
    Song();

    Song(string title, string artist, string genre);

    //mutators/setters
    void setTitle(string);

    
    void setArtist(string);
    void setGenre(string);
    

    //accessors/getters
    string getTitle();

    string getArtist();
    string getGenre();


    private:
    //atributes, like variable declarations
    string title;
    string artist;
    string genre;

    

};


//endif
#endif