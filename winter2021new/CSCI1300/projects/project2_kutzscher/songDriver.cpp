//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
////Project 2  - Problem 1

//pseudo code:
/*




*/


#include <iostream>
#include <cstring>

#include "Song.h"
#include "Song.cpp"

using namespace std;


//aight I guess this is just where we'll test stuff out
//g++ -std=c++11 stateDriver.cpp State.cpp
// ^ yoooo no need for do the join compilation it makes it freak out
//just do g++ stateDriver

int main(){
    Song newTrack("Broadway Bounce", "Corduroy", "Tech House");
    //Song newTrack;
    newTrack.setTitle("Take It");
    cout << "song name is: " << newTrack.getTitle() << endl;
    newTrack.setArtist("Dom Dolla");
    cout << "song artist is: " << newTrack.getArtist() << endl;
    newTrack.setGenre("still tech house");
    cout << "song genre is: " << newTrack.getGenre() << endl;
}