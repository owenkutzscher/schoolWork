//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2  - Problem 7

//pseudo code:
/*



*/
















#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

#include "Song.h"
#include "Song.cpp"
#include "Listener.h"
#include "Listener.cpp"

using namespace std;

//function stubs
int split();
string cleanItUp();
int readSongs();
int readListenerInfo();

string lowerCaseIt();
int getSongPlayCount();





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



int readListenerInfo(string fileName, Listener listeners[], int numListenersStored, 
                        int listenerArrSize, int maxCol){
    
    // string fileName, 
    // Listener listeners[], 
    // int numListenersStored, num listeners currently stored in listeners[]
    // int listenerArrSize, capacity of listeners[]. Default val is 100
    // int maxCol, max num columns, this is with reading the txt doc, 
    //      deafult val is 51, but basically just dont go over
    //      this is also with 1 name and then a max of 50 songs, we could select for less
    
    //this si the return value rv
    int rv = 0;
    //
    //ok so the funcions gotta return stuff
    //and we have to check for things in this order I guess

    //first, is listeners[] already full?
    if(numListenersStored >= listenerArrSize){
        rv = -2;
    }else{
        //cool, listeners[] wasnt full
        //but can we open the file?

        //create the variable for our file we are opening
        //cout << "our fileName is: " << fileName << endl;
        ifstream filedFile(fileName);
        //cout << "the fileName is: " << fileName << endl;
        if(!filedFile.is_open()){
            //if file cant b opened, -1
            rv = -1;
        }else{
            //cout << "ayyyyy we opened the file" << endl;
            //if we can open the file, then
            //go through our file...
            //if file is empty retrun 0
            // ^I believe this should just happen automaticly if the fils is empty.
            //and if all goes well, return the number of listeners in the array, as an integer
                    //yea yea if you get errors mess with this

            //
            //now lest get down to buisnes!
            //go through .txt file

            //this will just be a line of text from our file
            string line = " ";

            //we'll split lines and shove em into arrays, the comma is the seperator
            char seperator = ',';

            //this is just to stop the computer searching through the file
            //int fileIndex = 0;&& (fileIndex <= listenerArrSize) fileIndex++;
            
            //this is the place where we will drop a Listener into listeners[]
            int arrDropIndex = numListenersStored;

            

            //well use this to track the number of songs in each listener
            int tempNumSongs = 0;
            


            //each line will become a listener object, name, then song play counts
            //we can assume all listener names are distinct
            while(getline(filedFile, line)){ 
                
      
                //cout << "line is: " << line << endl;

                
                //as long as we're less than 100 and less than listenerArrSize,
                        //error here? maybe change so it doesnt have to be less than 100
                        //or maybe <= 100 or some shit idk
                // keep taking lines
                if((arrDropIndex < 100) && (arrDropIndex < listenerArrSize)){

                    //check  if empty line
                            //if errors, test for empty lines at beginning and end
                    if(line.length() <= 1){
                        //cout << "empty line detected" << endl;
                    }else{
                        //cool the line isnt empty
                        


                        //this is where we will temporarily store lines before we put it into a Listener in listeners[]
                        string tempArr[51];

                        //same as above but with int values
                        int tempIntArr[51];



                        //split it with the split funcion
                        //and then we'll store it in a temp array of strings
                                //if error, we could be shoving more things in than 51
                        
                        //cout << endl;
                        split(line, seperator, tempArr, 51);



                        //this loop inserts the values we want into the temp arrays
                        //that way we can make a new Listener with em

                        //cout << "line " << arrDropIndex << " is: ";
                        tempNumSongs = 0;

                        for(int i = 0; i < maxCol; i++){
                            tempArr[i] = cleanItUp(tempArr[i]);
                            //cout << tempArr[i] << " ";

                            if(i > 0){
                                string s = tempArr[i];
                                //cout << "s is: " << s << endl;
                                if(s != ""){
                                    //cout << "tempArr i is: " << stoi(s) << endl;
                                    tempIntArr[i-1] = stoi(tempArr[i]);
                                    tempNumSongs++;
                                }
                                
                            }
                            

                        }
                        //cout << endl;


                        //then  take all that, clean it up and put it into listeners[]
                                //if getting errors, make sure you are cleaning numbers and names well, and not putting , ,
                                //empty sections of commas in there, 
                        //use the stoi funcion to convert the strings to ints for play counts
                        //create listener objects and add guys to listeners[], only add as many columns
                        //  Listener::Listener(string s, int a[], int numSongs)
                                    //coule b errors with the num songs
                        Listener tempListener(tempArr[0], tempIntArr, tempNumSongs);
                        // as maxCol allows and stay less than 51 (including name) aswell
                                //error here? maybe max col can be zero and then dont add any guys
                        //
                        listeners[arrDropIndex] =  tempListener;

                        arrDropIndex++;
                    }
                    

                }


                //if all goes well, return the number of listeners in the array, as an integer
                rv = arrDropIndex;
                
            }
                




        }
    
    
    }
    //
    //
    


    
    return rv;
}








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




int getSongPlayCount(string listenerName, string songName, Listener listeners[],
                    Song songs[], int currentListenersStored, int currentSongsStored){
    //case in-sensitive
    //if we can find the listener name and the song name, then return 
    // number of plays of that song from that listener
    //return -1 if listener name is found, but song name is not
    //ret -2 i listener name not found but song name is found
    // ret -3 if neither are found

    //strategy
    //bool listener found
    //bool song found
    //then go through our return cases, and if they were both found then hurray!!!
    //then find it and return the play count   

    bool listenerFound = 0;
    bool songFound = 0;
    
    int listenerIndex = 0;
    for(int i = 0; i < currentListenersStored; i++){
        if(lowerCaseIt(listeners[i].getListenerName()) == lowerCaseIt(listenerName)){
            listenerFound = 1;
            listenerIndex = i;
        }
    }   
    
    //cout << "bitch what" << endl;
    int songIndex = 0;
    for(int k = 0; k < currentSongsStored; k++){
        //cout << "looking for song:::" << lowerCaseIt(songs[k].getTitle()) << ":::"<< endl;
        if(lowerCaseIt(songs[k].getTitle()) == lowerCaseIt(songName)){
            
            songFound = 1;
            songIndex = k;
        }
    }



    //cool now lets do some of our return cases  
    //if we can find the listener name and the song name, then return 
    // number of plays of that song from that listener
    //return -1 if listener name is found, but song name is not
    if((listenerFound == 1) && (songFound == 0)){
        return -1;
    }else if((listenerFound == 0) && (songFound == 1)){
        //ret -2 i listener name not found but song name is found
        return -2;
    }else if((listenerFound == 0) && (songFound == 0)){
        return -3;// ret -3 if neither are found      
    }else{
        //else, they were both found, so go and find the number of plays and return it
        int rv = 0;

        //i think literally just return the plays that the song has  listenerIndex  songIndex

        rv = listeners[listenerIndex].getPlayCountAt(songIndex);




        return rv;
    }
    
}



int main(){
    
    //na were gunna free hand this mf
    //cout << "the song play count is: " << getSongPlayCount(string listenerName, string songName, Listener listeners[],
    //                Song songs[], int currentListenersStored, int currentSongsStored) << endl;





    // Returns play count succesfully
    //we'll try this deafult test example!
    Song songs[50];
    int numSongsStored = readSongs("Songs2.txt", songs, 0, 50);
    int numListenersStored = 0;
    int listenerArrSize = 50;
    Listener listener[listenerArrSize];
    numListenersStored = readListenerInfo("coolListeners.txt", listener, numListenersStored, listenerArrSize, 50);
    cout<<getSongPlayCount("Josh", "Goodbye Yellow Brick Road", listener, songs, numListenersStored, numSongsStored)<<endl;


    return 0;
}
    