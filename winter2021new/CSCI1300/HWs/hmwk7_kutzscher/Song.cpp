//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 7 - Problem 2

//pseudo code:
/*

*/



#include <iomanip>
#include <fstream>
#include <cstring>



#include <iostream>
#include "Song.h"

using namespace std;

//ok lets define all the shit from State.h
//llike all the functions and stuff



//class definition
//public interface


//deafult guys +paramaterized boi

Song::Song(){
    //define some things and variables
    title = "";
    artist = "";
    genre = "";
}


Song :: Song(string title1, string artist1, string genre1){
    title = title1;
    artist = artist1;
    genre = genre1;
}


//setters 

void Song :: setTitle(string title1){
    title = title1;
}

void Song :: setArtist(string artist1){
    artist = artist1;
}
void Song :: setGenre(string genre1){
    genre = genre1;
}


//getters

string Song :: getTitle(){
    return title;
}

string Song :: getArtist(){
    return artist;
}
string Song :: getGenre(){
    return genre;
}


