//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 1 - Problem 3

//pseudo code:
/*

function
    loop through the letters from the string input, for each one
    check if its a constant
    if it is then add one to the return val
    return the return val


*/


#include <iostream>
#include <cstring>
using namespace std;

bool isConsonant(char letter){
    
    //this is the return value
    bool rV = 1;

    //lets check if its a vowel, if it is then make the return
    //value false / 0
    if((letter == 'A')||(letter == 'a')){
        rV = 0;
    }else if((letter == 'E')||(letter == 'e')){
        rV = 0;
    }else if((letter == 'I')||(letter == 'i')){
        rV = 0;
    }else if((letter == 'O')||(letter == 'o')){
        rV = 0;
    }else if((letter == 'U')||(letter == 'u')){
        rV = 0;
    }else if((letter == 'Y')||(letter == 'y')){
        rV = 0;
    }
    //I added this on to my code
    else if(letter == ' '){
        rV = 0;
    }else if(letter == '.'){
        rV = 0;
    }

    
    return rV;
}




int numConsonant(string sentence){
    //this is what we will be returning
    int returnVal = 0;

    
    
    //lets loop though the string
    for(int i = 0; i < sentence.length(); i++){
        //cout << sentence.substr(i, 1) << endl;
        //string ss = sentence.substr(i,1);
        //char cc = ss.c_str();
        
        char cc = sentence[i];

        if(isConsonant(cc) == 1){
            returnVal++;
        }
    }

    



    return returnVal;
}


int main(){
    
    

    string response = " ";
    cout << "gimmie a sentence, lets count them consonants" <<endl;
    //cin >> response;
    getline(cin, response);

    cout << "numbaa of consonants: " << numConsonant(response) << endl;
    
    

    return 0;
}