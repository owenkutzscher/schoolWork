//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 3

//pseudo code:
/*

//YOOOOO
//DONT FORGET
//WRITE HELLA FUNCTIONS DUDE
//LIKE
//BREAK IT APART N STUFF
//or like not even hella functions just for anything that looks
// like itll b a fat chunk of code, take that out and put it into a function to make it easier


//read the files




*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


int figureOutArrayRows(string fileName){
    //cout << "littie tittie" << endl;

    int arrRows = 0;

    ifstream file(fileName);

    //aight well
    //Im going to assume that the files are going to be presented like how they gave them to me
    //if they want to get weird then that sucks for me i guess

    if(!file.is_open()){
        return -1;
        cout << "fuck it didnt open" << endl;
        //if theres an error, then assign numNames -1 and return that
    }else{



        //go line by line throuhg the file
        while (!file.eof()){

            string line = " ";
            
            //get input
            getline(file, line);


            //cout << "the line length is: " << line.length() << endl;
            //on each line, if it starts with "Player" or its a blank line, then dont count it
            if(line.length() <= 1){
                //cout << "shiiiiiiiiiiiii we got an empty line!!!" << endl;
            }else{
                //cout << "AYYYYYY we got a line of fuckin txt" << endl;

                arrRows++;
                
            }
        }
    }
    arrRows--;
    //cuz like the first line got counted
    return arrRows;
}

void insertStarters(string fileName, string startersArr[][13]){
    //cout << "littie tittie" << endl;

    int arrRows = 0;

    int z = 0;

    ifstream file(fileName);

    //aight well
    //Im going to assume that the files are going to be presented like how they gave them to me
    //if they want to get weird then that sucks for me i guess

    if(!file.is_open()){
        //cout << "fuck it didnt open" << endl;
        //if theres an error, then assign numNames -1 and return that
    }else{
        //go line by line throuhg the file
        while (!file.eof()){
            string line = " ";
            //get input
            getline(file, line);
            //cout << "the line length is: " << line.length() << endl;
            //on each line, if it starts with "Player" or its a blank line, then dont count it
            if(line.length() <= 1){
                //cout << "shiiiiiiiiiiiii we got an empty line!!!" << endl;
            }else{
                string inputValue = "penis";
                startersArr[z][inputValue];
                z++;
            }
        }
    }
}



void makeATeam(string startersFileName, string benchFileName){
    //fuck yea this is going to be the main fucntion
    //basically every comment I have below is going to be its own fucntion
    //that'll make it hella easy
    //more than that
    //I want the fuckin blocks of functions to be their own functions
    //we'll pass in hella arrays and shit yuhhhh

    //I think out strat should be to make some arrays
    //first figure out the dimentions of the arrays we'll make
    int startersArrRows = figureOutArrayRows(startersFileName);
    //cout << "the number of rows for starters is: " << startersArrRows << endl;
    //starters have 13 columns

    //do one for bench
    int benchArrRows = figureOutArrayRows(benchFileName);
    //cout << "the number of rows for starters is: " << benchArrRows << endl;
    //bench has 5 clumns

    //then insert the players in the arrays

    //first lets do starters
    string startersArr[startersArrRows][13];
    insertStarters(startersFileName, startersArr);
/*
    //lets print the startersArr
    for(int i = 0; i < startersArrRows; i++){
        for(int u = 0; u < 13; u++){
            cout << starterArr[i][u] << endl;
        }
    }
*/


    //now the bench bois
    //benchArr = [benchArrRows][5];

    //also store the stats thing in an rray so we can refrence its position to the players position



    

    //now that the elements have been inserted and stored and shit
    // lets read them and for each player we go through, calculate the usg
    //if the usg is greater than 28%, we will add em to our team.
    //and for the bench bois if the TS% is higher than 50% then add em
    // btw make an array for the team we will make

    //aight
    //now print the shit


}





int main(){
    //aight well we gotta fuckin read the files to start


    string startersFileName = " ";
    
    cout << "Enter the filename of starters:" << endl;
    //cin >> startersFileName;
    startersFileName = "starters.txt";

    string benchFileName = " ";
    
    cout << "Enter the filename of bench players:" << endl;
    //cin >> benchFileName;
    benchFileName = "bench.txt";

    makeATeam(startersFileName, benchFileName);



}