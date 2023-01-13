//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2  - Problem 5

//pseudo code:
/*


//finds the most frequent genre, returns number of songs in that genre
int frequentGenreSongs(songs[], int numSongsStored){
    
    //we will return this
    //its the number of songs that were in the most frequent genre
    int numSongsMostFreqGenre = 0;

    //
    //loop through songs
    //each song...
        //get the genre
        //if its a new genre...
        //store the genre in an index in genres array
        // index++ for the next genre we find
        //now look for instances of that gerne by looping through the
        // rest of the songs
        //each song were comparing to...
            //if the genre is what were looking for then 
            // increase the currentGenreCount by 1
    //



    //more things
    //if 'songs' is empty ir number of songs stored is
    // invalid then return 0
    return numSongsMostFreqGenre;
}


*/
















#include <iostream>
#include <cstring>
#include <fstream>

#include "Song.h"
#include "Song.cpp"
#include "Listener.h"
#include "Listener.cpp"

using namespace std;

//function stubs




int main(){

    // Song songys[4] = {Song("Pump The Breaks", "Dom Dolla", "Tech House"), 
    //                 Song("Raptor", "Ballarak", "Techno"), 
    //                 Song("Take It", "Dom Dolla", "teCH houSE"),
    //                 Song("She Gets It Done", "Corduroy", "Tech House")};
    //
    int songys[4] = {69, 420, 222, 1};
    Listener owen("ya boi Owen", songys, 4);
    //maybe the 4 could b a 7?

    //Listener owen;
    owen.setListenerName("cheese stick");
    bool c = owen.setPlayCountAt(5, 420000);
    cout << "did it set? " << c << endl;
    
    cout << "total play count is: " << owen.totalPlayCount() << endl;
    cout << "num unique songs is: " << owen.getNumUniqueSongs() << endl;

    

    cout << "listeners name is: " << owen.getListenerName() << endl;
    cout << "listeners size is: " << owen.getSize() << endl;
    cout << "lets print all the elements of the play-count array" << endl;







    // for(int k = 0; k < owen.getSize(); k++)
    //     cout << owen.getPlayCountAt(k) << endl;
    

    
    // return 0;
}
    