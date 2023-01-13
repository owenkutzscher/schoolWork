//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2  - Problem 4

//pseudo code:
/*

//this function will count the number of songs that all are in the same genre
int countGenre(string genre, Song songs[], int numSongsStored){
    int numSongsWithGenre = 0;

    //loop though songs[]
    //for each song, see what its genre is
    //      *dont forget to make them all either upper or lower case*
    //if its the one we want then numSongsWithGenre++
    //then return the number of songs with the genre

    return numSongsWithGenre;
    Return 0 if no songs match (given genre is not found) 
    or if the array is empty 
    or if the number of listeners are invalid (like a negative number).
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












int main(){
    
    string genre = "Tech house";
    //ill just assume the array  is all cleaned up for testing purpouses
        //make arr larger
    Song songs[4] = {Song("Pump The Breaks", "Dom Dolla", "Tech House"), 
                    Song("Raptor", "Ballarak", "Techno"), 
                    Song("Take It", "Dom Dolla", "teCH houSE"),
                    Song("She Gets It Done", "Corduroy", "Tech House")};
    int numSongsStored = 4;

    int numGenreSongs = countGenre(genre, songs, numSongsStored);

    cout << "number of songs with: " << genre << ", as the genre is: " << numGenreSongs << endl;

    //test with:
    //maybe if the songs array WILL be filled up we should just return the negative 
    //  number and not put the songs into the array that will fit
    // empty lines
    // a full arr or something
    // an arr thats 
    // more spaces, and spaces after last word?

   

  return 0;
}
    