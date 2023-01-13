//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 1

//pseudo code:
/*

//create the distance array
//populate it with a loop

//create the pasta array
//populate it by indiviually assigning values

//create the sequence array
//populate by using a loop

//create the letters array
//loop through using ASCII

//in main, print the arrays with a function print1DArray()
//wait, we have to paste only our main into  coderunner, so write it ther



*/


#include <iostream>
using namespace std;


int main(){
    //create the distance array
    int distanceSIZE = 10;
    double distance[distanceSIZE];
    
    //populate it with a loop
    for(int i = 0; i < distanceSIZE; i++){
        distance[i] = 42.42;
    }
    //lets print our array
    for(int i = 0; i < distanceSIZE; i++){
        cout << distance[i] << endl;
    }
    cout << endl;
    

    //create the pasta array
    int pastaSIZE = 5;
    //populate it by indiviually assigning values
    string pasta[] = {"Penne", "Bucatini", "Farfalle", "Fusilli", "Rigatoni"};
    
    //lets print the pasta array
    for(int i = 0; i < pastaSIZE; i++){
        cout << pasta[i] << endl;
    }
    cout << endl;



    //create the sequence array
    //first 100 positive intigers in order
    int sequenceSIZE = 100;
    int sequence[sequenceSIZE];

    //populate by using a loop
    int valueToAdd = 1;
    for(int i = 0; i < sequenceSIZE; i++){
        sequence[i] = valueToAdd;
        valueToAdd += 2;
    }
    //and ofc we gotta print him
    for(int i = 0; i < sequenceSIZE; i++){
        cout << sequence[i] << endl;
    }
    cout << endl;




    //create the letters array
    int lettersSIZE = 26*2;
    char letters[lettersSIZE];

    //lets add the letters
    //loop through using ASCII
    //lets add the capitol letters first
    //also this guy below, ccc, is a counter
    int ccc = 65;
    for(int i = 0; i < lettersSIZE; i += 2){
        //we'll add 65 to the current number to access the capitol letters in ASCII
        letters[i] = ccc;
        ccc++;
    }
    //now lets add the consonant letters
    //also this guy below, ccc, is a counter
    int vvv = 97;
    for(int i = 1; i < lettersSIZE; i += 2){
        //we'll add 65 to the current number to access the capitol letters in ASCII
        letters[i] = vvv;
        vvv++;
    }

    //printing time
    for(int i = 0; i < lettersSIZE; i++){
        cout << letters[i] << endl;
    }
    cout << endl;

    




    return 0;
}