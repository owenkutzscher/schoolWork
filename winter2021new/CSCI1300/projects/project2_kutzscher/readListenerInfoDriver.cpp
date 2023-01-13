//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 2  - Problem 7

//pseudo code:
/*

int readListenerInfo(string fileName, Listener listeners[], int numListenersStored, 
                        int listenerArrSize, int maxCol){
    
    // string fileName, 
    // Listener listeners[], 
    // int numListenersStored, num listeners currently stored in listeners[]
    // int listenerArrSize, capacity of listeners[]. Default val is 100
    // int maxCol, max num columns, this is with reading the txt doc, 
    //      deafult val is 51, but basically just dont go over
    //      this is also with 1 name and then a max of 50 songs, we could select for less
    //
    //
    //ok so the funcions gotta return stuff
    //and we have to check for things in this order I guess
    //if numListenersStored >= listenerArrSizr return -2
    //if file cant b opened, -1
    //if file is empty, 0
    //if all goes well, return the number of listeners in the array, as an integer
    //
    //
    //
    //notes
    //go through .txt file
    //each line will become a listener object, name, then song play counts
    //  we can assume all listener names are distinct
        //as long as we're less than 100 and less than listenerArrSize,
                //error here? maybe change so it doesnt have to be less than 100
        // keep taking lines

        //check  if empty line
        //split it with the split funcion
        //then  take all that, clean it up and put it into listeners[]
        //use the stoi funcion to convert the strings to ints for play counts
        //create listener objects and add guys to listeners[], only add as many columns
        // as maxCol allows and stay less than 51 (including name) aswell
                //error here? maybe max col can be zero and then dont add any guys
    //


    

}

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
int readListenerInfo();






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




int main(){
    
    //Listener owen("ya boi Owen", songys, 4);

    int listenerArrSize = 7;
    Listener listeners[listenerArrSize];
    int numListenersStored = 0;
    int maxCol = 12;
            //if errors check  with listeners already in the arr
    cout << "when I read listener info the number I gt is: " << 
    readListenerInfo("coolListeners.txt", listeners, numListenersStored, listenerArrSize, maxCol) << endl;

    cout << "now ill print listeners[]" << endl;
    //listeners printed below
    for(int i = 0; i < listenerArrSize; i++){
        cout << "name: " << listeners[i].getListenerName() << endl << "and now the playCounts for ^: ";
        //now lets print the play counts by looping through
        for(int k = 0; k < listeners[i].getSize(); k++){
            cout << listeners[i].getPlayCountAt(k) << " ";
        }
        cout << endl;
    }

    return 0;
}
    