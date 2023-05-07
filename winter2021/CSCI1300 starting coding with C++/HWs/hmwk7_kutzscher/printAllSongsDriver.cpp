//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2 - problem 3

//pseudo code:
/*

int readSongs(string fileName, Song songs[], int numSongsStored, int songArrSize){
    //fills an array of Song objects with title, artist and genre info

    //string fileName, name of the file to be read
    //Song songs[], array of song objects, this will get filled
    //int numSongsSotred. numSongs currently stored in songs[]? or is it the array
    //      this is the correct number of songs currently sotred in the array
    //      so use this to insert new songs correctly, songs[] might already have some
    //      songs in it
    //int songArrSize, capacity of songs[] (aparently set this to 50?)
    //
    //return the total number of songs in the system
    //      but if numSongsStored == songArrSize return -2
    //      they explained that terribly. Basically if you run out of room
    //      in songs[] then return -2
    //          the lastly, if the file was not opened successfully, return -1



    //holy shit, why are they so good at making these problems confusing?
    //its like they dont want me to be able to ficure out what this fucntion is supposed to do!
    //if you are grading this tell the person who wrote the descriptio for this
    //problem that I would really appreciate it if they could make it just a little more clear


    //alright lets get going
    //first off, make a return value variable
    int returnVal = 0;
    //check if numSongsStored < songArrSize
    //if its not less then holy shit, thats it, return -2
        //else, check if we can open the file, if we cant then return -1
            //if we can open the file, then
            // use the split function to read lines of the file, and shove Songs into songs[]
            //each line of the txt file is going to be title, artist, genre
            //if its full at any point, and were tryna add another guy, then stop the adding
            // and return -2
            
            //but hey maybe it all goes according to plan!
            //then sweet, cool

    //at the end, return the number of songs in the system
    //this will be songsStored +1 every time we add another songs

    return returnVal;
}



*/
















#include <iostream>
#include <cstring>
#include <fstream>

#include "Song.h"
#include "Song.cpp"

using namespace std;


void printAllSongs(Song songs[], int numsongs){
    //if numsongs is 0 or less
    // print "No songs are stored"
    //else
    // print "Here is a list of songs"
    //TITLE is by ARTIST

    if(numsongs <= 0){
        cout << "No songs are stored" << endl;
    }else{
        cout << "Here is a list of songs" << endl;
        for(int i = 0; i < numsongs; i++){
            cout << songs[i].getTitle() << " is by " << songs[i].getArtist() << endl;
        }
    }
}




int main(){
    return 0;
  /*  */
}