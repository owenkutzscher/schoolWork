//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Practicum 3

#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <iostream>









class AntonymDictionary{

    public:
    //deafult constuctors
    AntonymDictionary();

    //getters


    //setters


    //any other guys
    int loadWords(string);
    int searchForWord(string);
    string getAntonym(string);




    private:
    string words[50];
    string antonyms[50];


};





////////////////////////////////////////////////////////////////////




//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Practicum 3


//default constructors
AntonymDictionary::AntonymDictionary(){
    //initializes all stats
    for(int i = 0; i < 50; i++){
        words[i] = "";
    }
    for(int u = 0; u < 50; u++){
        antonyms[u] = "";
    }
}



//getters

//setters

//other


//int split(string str, char sep, string array[], int arraySize);

int AntonymDictionary::loadWords(string fileName){
    //takes a file name
    //if file exists, return 1
    //if it cant be opened return 0
    //anyways take the first word and put it in words,
    //take the second and put it in antonyms
    //if errors then the last line may or may not end it '\n'

    int returnV;

    
    //cout << "our fileName is: " << fileName << endl;
    ifstream filedFile(fileName);

    //fstream filedFile;
    //filedFile.open(fileName);


    if(!filedFile.is_open()){
        //dang we couldnt open it
        returnV = -1;

    }else{
        returnV = 0;
        //if we can open the file, then
        //go through our file...
        
        //this will just be a line of text from our file
        string line = " ";

        string holder[2];
        int index = 0;

        while (!filedFile.eof()){
            

            //get input
            getline(filedFile, line);


            split(line, ',', holder, 2);

            words[index] = holder[0];
            antonyms[index] = holder[1];
            

            index++;
        }
    }

    return returnV;
}



int AntonymDictionary::searchForWord(string wordToFind){
    //searches for a particular word and returns the index where
    // that word is located
    //if word is not found return -1

    int foundAt = -1;

    for(int i = 0; i < 50; i++){
        if(words[i] == wordToFind){
            foundAt = i;
        }
    }
    return foundAt;
}



string AntonymDictionary::getAntonym(string wordToAntonym){
    //looks for a particular word
    //returns the antonym
    //returns "" if it wasnt found

    string ant = "";

    for(int i = 0; i < 50; i++){
        if(words[i] == wordToAntonym){
            ant = antonyms[i];
        }
    }

    return ant;
}