//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2 - problem 2

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

int split();
string cleanItUp();
int readSongs();




int split(string str, char seperator, string arr[], int arrSIZE){
    //this will be the num pieces out string is split into
    int numPieces = 0;

    int validSeperatorCount = 0;



    //first, lets see if its an empty string, if so
    // numPieces, the return val, is 0 and just dont do anything else
    if(str == ""){
        
        //cout << "bruh there wasnt even a single guy in there what the heck" << endl;
        numPieces = 0;

    }else{

        //start looping and looking through the string for a seperator
        int strSize = str.length();
        for(int i = 0; i < strSize; i++){
            //cout << "testing the char: " << str[i] << endl;

            //lets see if its a seperator
            char c = str[i];
            if(c == seperator){
                //cout << "ayy we caught a seperator, in the act" << endl;

                //we found a seperator, sick
                //lets make sure it doesnt have anything weird with it

                //if the seperator is at the beginning or end, dont do anything
                if((i == 0) || (i == strSize)){
                    //cout << "ayy seperator what are you doing at the beginning/end?!!!" << endl;
                    bool keepGoing = 1;
                    while(keepGoing == 1){
                        if(str[i+1] == seperator){
                            i++;
                            //cout << "hell na no seperator repeating at thebeginning" << endl;
                        }else{
                            keepGoing = 0;
                        }
                    }
                }else{
                    
                    //cool, the seperator isnt at the beginning or the end

                    //wait, what if there were say 3 seperator in a row at the beginning?
                    // test for that
                    //actually we dont need to, if it was at the beginning, then it will do i++
                    // that way we are where we need to be

                    //if the seperator is followed by more seperators, that reach the
                    // end, then dont do anything
                        bool keepGoing = 1;
                        while(keepGoing == 1){
                            if(str[i+1] == seperator){
                                i++;
                                //cout << "hell na no seperator repeating" << endl;
                                if(i == strSize-1){
                                    //if the seperators went till the end then they are invalid
                                    //so take 1 off the count becuse we will be adding 1 on later regarless
                                    //cout << "those seperators went till the end so they are invalid" << endl;
                                    validSeperatorCount--;
                                }
                            }else{
                                keepGoing = 0;
                            }
                        }
                    
                    

                        //if the seperator has more seperators in front of it, then count
                        // it, and skip over the seperators against this one
                        //actually we dont need to do anything!
                        //the loop above checks for all instances of a seperator repeating

                        //if it doesnt have any seperators in front of it,
                        // and it passed all the tests, then count it
                        validSeperatorCount++;

                }

                    



                
            }
        }













        //loop ends here
        //cool we finished looping and finding seperators

        //now count the number of pieces, since we have the number of seperators
        numPieces = validSeperatorCount + 1;

        //if we finished looping, and there was no seperators,
        // then numPieces is 1, we will return that, and now place the whole
        // string in the array as the first element
        if(numPieces == 1){
            arr[0] = str;
        }else if(numPieces > arrSIZE){









            //well the dint state this in the problem so now I have to do this I guess
            //alright we have to add elements into the array until the array is full

            string itemToAdd = "";
            bool addAndReset = 0;
            int z =0;

            int spaceLeft = arrSIZE;

            //bool endOnSeperator = 0;
            while(spaceLeft > 0){
            for(int p = 0; p < strSize; p++){

                char c = str[p];
                
                //cout << "im lookin at the value: " << c << "Im on p = " << p << endl;

                //if its a seperator just skip over it
                while(c == seperator){
                    
                    if(addAndReset == 1){
                        //since we found a seperator, 
                        // lets add the item weve been building into our array
                        //real quick tho, make sure the item to add isnt empty
                        if(itemToAdd != ""){
                            //cout << "im adding the item: " << itemToAdd << endl;
                            arr[z] = itemToAdd;
                            itemToAdd = "";
                            spaceLeft--;
                        }
                        z++;
                    }
                    
                    addAndReset = 0;

                    p++;
                    c = str[p];
                    //if(p == strSize){
                    //    endOnSeperator = 1;
                    //}
                }

                itemToAdd.push_back(c);


                addAndReset = 1;
            }
            }











            
            
            //else if the string is split into more pieces than the size of 
            // the array, then numPieces, return val, is -1
            // and i guess just dont change the array
            numPieces = -1;
            //cout << "banana" << endl;


            
        }else{
            //sick, you passed those tests
            //now loop though and shove guys into an array wherever the
            // seperator ends

            string itemToAdd = "";
            bool addAndReset = 0;
            int z =0;

            bool endOnSeperator = 0;

            for(int p = 0; p < strSize; p++){

                char c = str[p];
                
                //cout << "im lookin at the value: " << c << "Im on p = " << p << endl;

                //if its a seperator just skip over it
                while(c == seperator){
                    
                    if(addAndReset == 1){
                        //since we found a seperator, 
                        // lets add the item weve been building into our array
                        //real quick tho, make sure the item to add isnt empty
                        if(itemToAdd != ""){
                            //cout << "im adding the item: " << itemToAdd << endl;
                            arr[z] = itemToAdd;
                            itemToAdd = "";
                        }
                        z++;
                    }
                    
                    addAndReset = 0;

                    p++;
                    c = str[p];
                    if(p == strSize){
                        endOnSeperator = 1;
                    }
                }

                itemToAdd.push_back(c);


                addAndReset = 1;



                

            }

            if(endOnSeperator == 0){
                if(addAndReset == 1){
                            //since we found a seperator, 
                            // lets add the item weve been building into our array
                            //real quick tho, make sure the item to add isnt empty
                            if(itemToAdd != ""){
                                //cout << "im adding the item: " << itemToAdd << endl;
                                arr[z] = itemToAdd;
                                itemToAdd = "";
                            }
                            z++;
                        }
                }
            }
            

        
    }

        







    //cout << "valid seperator count: " << validSeperatorCount << endl;
    //return num pieces string was split into
    return numPieces;
}



string cleanItUp(string notClean){
    string cleanString = "";
    bool startOfWord = 1;

    
    for(int i = 0; i < notClean.length(); i++){
        if(startOfWord == 1){
            if(notClean.substr(i,1) != " "){
                cleanString.append(notClean.substr(i,1));
                startOfWord = 0;
            }
        }else{
            cleanString.append(notClean.substr(i,1));
        }
        
    }
    return cleanString;
}



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
    //check if numSongsStored >= songArrSize


    //we'll change this to a 1 if songs is filled to the brim and were tryna shove more stuff in
        bool songsFull = 0;


    if(numSongsStored >= songArrSize){
        //if its not less then holy shit, thats it, return -2
        returnVal = -2;
    }else{
        //else, check if we can open the file, if we cant then return -1
        //create the variable for our file we are opening

        //cout << "our fileName is: " << fileName << endl;
        ifstream filedFile(fileName);

        //fstream filedFile;
        //filedFile.open(fileName);

        


        if(!filedFile.is_open()){
            
            //dang we couldnt open it
            //cout << "Could not open file." << endl;
            returnVal = -1;
        }else{
            //cout << "ayyyyy we opened the file" << endl;
            //if we can open the file, then
            //go through our file...
            
            //this will just be a line of text from our file
            string line = " ";

            char seperator = ' ';

            string tempArr[3];
            

            int r = numSongsStored;

            string tempArtist = " ";
            string tempGenre = " ";

            int emptyLines = 0;
            int placeIn = 0;

            int numSongsTooMany = 0;

            while (!filedFile.eof()){
                
                    /*
                //realQuick make sure we arent putting more in the array than it can hold
                if((r - emptyLines) >= songArrSize){
                    filedFile.close();
                    cout << "dang I dont have any room" << endl;
                    ohBoy = 1;
                    
                    //oh boy its not going to work
                    //well return -2
                }else{
                    */

                

                //get input
                getline(filedFile, line);
                
                // use the split function to read lines of the file, and shove Songs into songs[]
                //each line of the txt file is going to be title, artist, genre
                //cout << line << endl;

                //hold up, is the line empty?
                if(line.length() <= 1){
                    emptyLines++;
                    //cout << "empty line detected" << endl;
                }else{
                    seperator = ',';
                    split(line, seperator, tempArr, 3);

                    /*
                    for(int p = 0; p < 3; p++){
                        cout << tempArr[p] << endl;
                    }
                    */

                    //we love palce in
                    //this is used becuase r is the line number were on
                    // and song lines are empty so we want to index - the number of empty lines
                    placeIn = r - emptyLines;
                    

                    //this substr thing is a quick fix, I dont know if itll work long term
                    //all its doing is taking out the space at the beginning of the word
                    //ayy we will clean up our strings
                    //we will use our handy "clean up" function to do that, we just need to take away spaces
                    //so itll check for that
                    
                    string cleanedTitle = cleanItUp(tempArr[0]);
                    string cleanedArtist = cleanItUp(tempArr[1]);
                    string cleanedGenre = cleanItUp(tempArr[2]);

                    //wait!!! if songs is full then just dont add any more
                    if(placeIn >= songArrSize){
                        songsFull = 1;
                        numSongsTooMany++;

                    }else{
                        //if our array isnt full then add our guys to our array!

                        songs[placeIn].setTitle(cleanedTitle);

                        songs[placeIn].setArtist(cleanedArtist);
                        songs[placeIn].setGenre(cleanedGenre);
                    }

                    //if its full at any point, and were tryna add another guy, then stop the adding
                    // and return -2
                    
                    //but hey maybe it all goes according to plan!
                    //then sweet, cool

                    //close the file
                    //at the end, return the number of songs in the system
                    //this will be songsStored +1 every time we add another songs
                        
                }

                r++;
                //}
            }

            //ok so r is our number of songs to start + the number we added
            returnVal = (r - emptyLines) - numSongsTooMany;

            

        }

            
    }
    return returnVal;
    /*
    if(songsFull == 1){
        return -2;
    }else{
        
    }
    */
    
}


int main(){
    string fileName = "coolSongs.txt";
    Song songySong("poop", "cheese", "tweek");
    Song songs[7] = {songySong};
    int numSongsStored = 1;
    int songArrSize = 7;

    int newNumSongs = readSongs(fileName, songs, numSongsStored, songArrSize);

    cout << "ayy the number of songs in here is: " << newNumSongs << endl;

    //test with:
    //maybe if the songs array WILL be filled up we should just return the negative 
    //  number and not put the songs into the array that will fit
    // empty lines
    // a full arr or something
    // an arr thats 
    // more spaces, and spaces after last word?

   
    cout << "ayyy now im going to print the songs array: " << endl;
    cout << "---title---" << endl;
    for(int i = 0; i<songArrSize; i++){
        cout << songs[i].getTitle() << endl;
    } 
    cout << "---artist---" << endl;
    for(int i = 0; i<songArrSize; i++){
        cout << songs[i].getArtist() << endl;
    }
    cout << "---genre---" << endl;
    for(int i = 0; i<songArrSize; i++){
        cout << songs[i].getGenre() << endl;
    }
  /*  */
}