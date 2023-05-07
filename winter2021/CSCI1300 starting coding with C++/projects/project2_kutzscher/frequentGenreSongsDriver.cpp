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

using namespace std;

//function stubs
int countGenre();
string lowerCaseIt();
int frequentGenreSongs();
bool checkIfNewGenre();


//this guy makes all the letters lowercase
string lowerCaseIt(string words){
    //well return this guy, the origional word but only lowercase
    string allLower = "";

    //we will go through and test each character in the words
    // storing them in t each time
    char t = ' ';

    //loop though
    for(int j = 0; j < words.length(); j++){

        //first assign t a value from our string input
        //t = char(words.substr(j,1));
        t = char(words[j]);
        //cout << "the thing im checking is: " << t << endl;

        //if its a capitol letter then take away the distance from a capitol to a lowercase letter
        //to make it lowercase in ASCII
 
        if ((t <= 'Z') && (t >= 'A')){
            t = t - ('Z' - 'z');
            //cout << "its a capitol! now its: " << t << endl;
            allLower.append(string(1, t));
        
        //else its not a capitol were chillinnn
        }else{
            allLower.append(string(1, t));
        }


        /*
        if ((t <= "Z") && (t >= "A")){
            t = t - ("Z" - "z");
            allLower.append(t);
        
        //else its not a capitol were chillinnn
        }else{
            allLower.append(t);
        }
       */
    }
    
    
    //cout << "Im bouta return: " << allLower << endl;

    return allLower;
}









//this function will count the number of songs that all are in the same genre
int countGenre(string genre, Song songs[], int numSongsStored){
    int numSongsWithGenre = 0;

    //function summery
    //loop though songs[]
    //for each song, see what its genre is
    //      dont forget to make them all either upper or lower case
    //if its the one we want then numSongsWithGenre++
    //then return the number of songs with the genre

    //variables

    //we will temporarily store genres in this so we can compare them easily
    string genreFound = " ";

    //this function is case insesnitive so we'll make all the letters lowercase 
    // and store it in here
    string allLower = " ";

    //this guy is the genre were looking for, but with all lowercase letters
    // we will compare our genres with lowercase ltters to this guy
    string genreAllLower = lowerCaseIt(genre);




    //loop though songs[]
    for(int i = 0; i < numSongsStored; i++){


        //for each song, see what its genre is
        genreFound = songs[i].getGenre();
        
        //dont forget to make them all either upper or lower case
        allLower = lowerCaseIt(genreFound);

        //cout << "the genre of this one is: " << allLower << endl;

        //if its the one we want then numSongsWithGenre++
        if(allLower == genreAllLower){
            numSongsWithGenre++;
        }
        
    }

    
    //then return the number of songs with the genre
    //Return 0 if no songs match (given genre is not found) 
    //or if the array is empty 
    //or if the number of listeners are invalid (like a negative number).

    return numSongsWithGenre;
}


//this guy loops through a list of genres, if the one were looking for is new
// the  it returns a 1 for true. Else is false
bool checkIfNewGenre(string genreCheckFor, string genres[], int numSongsStored){
    bool rV = 1;

    for(int i = 0; i < numSongsStored; i++){
        if(lowerCaseIt(genres[i]) == lowerCaseIt(genreCheckFor)){
            rV = 0;
        }
    }

    return rV;
}

//finds the most frequent genre, returns number of songs in that genre
int frequentGenreSongs(Song songs[], int numSongsStored){
    
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
        //now look for instances of that gerne by using the countGenre function
        //store the number we get inside an array in the same index as where we stored the genre
    //



    //real quick check if the numSongsStored is positive..
    if(numSongsStored > 0){

    

    //varrrrrr

    //this is just what we'll assign a genre to each time we chech out a song
    string currentGenre = " ";

    //this is an array we will use to store each genre we find, no dupicates
    string genres[numSongsStored];

    //partner with the guy above, used to store the number of a particular genre
    //the indexes of the genre and the number of them corosponds
    int nGenres[numSongsStored];

    //this is what we'll use to index genres and songsWGenre
    //becasue the index of them is independent of our for loop
    int gIndex = 0;

    //this is just a quick lil checker boid dont worry abt him
    bool newGenreFound = 0;

    
    //loop through songs
    for(int i = 0; i < numSongsStored; i++){

        //each song...
        //get the genre
        currentGenre = songs[i].getGenre();

        //cout << "this song has the genre: " << currentGenre << endl;;

        //check if its a new genre with a function
        newGenreFound = checkIfNewGenre(currentGenre, genres, numSongsStored);
        //cout << "newGenreFoud reads a: " << newGenreFound << endl;

        if(newGenreFound == 1){
            
            genres[gIndex] = currentGenre;

            nGenres[gIndex] = countGenre(currentGenre, songs, numSongsStored);
            

            //we've added things to the arrays so bump that index up
            gIndex++;
        }

        
    

    }
    
    //now just return the number that is the most of all the genres
    for(int k = 0; k < gIndex; k++){
        if(nGenres[k] > numSongsMostFreqGenre){
            numSongsMostFreqGenre = nGenres[k];
        }
    }

    
    }
    //more things
    //if 'songs' is empty ir number of songs stored is
    // invalid then return 0
    return numSongsMostFreqGenre;
}






int main(){
    
    //ill just assume the array  is all cleaned up for testing purpouses
        //make arr larger
/**/
    Song songs[4] = {Song("Pump The Breaks", "Dom Dolla", "Tech House"), 
                    Song("Raptor", "Ballarak", "Techno"), 
                    Song("Take It", "Dom Dolla", "teCH houSE"),
                    Song("She Gets It Done", "Corduroy", "Tech House")};


    //Song songs[0];
    cout << "we can declare an arr size 0......." << endl;
    int numSongsStored = 4;
    //int numSongsStored = 0;

    int numMostFrequentGenre = frequentGenreSongs(songs, numSongsStored);

    cout << "the num songs in the genre with most songs is " << numMostFrequentGenre << endl;

    //aight lets test some things
    //it says "if the number of songs stored is invalid"
    //maybe empty array?
    //maybe empty genres?
    
   

    return 0;
}
    