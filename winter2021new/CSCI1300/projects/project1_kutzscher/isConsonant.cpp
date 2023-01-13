//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 1 - Problem 2

//pseudo code:
/*

function,
do a bunch of if statments, if its a vowel make the return value 0
else, return a 1;


*/


#include <iostream>
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


int main(){
    
    

    char response = ' ';
    cout << "gimmie a letter, better not be a vowel..." <<endl;
    cin >> response;

    cout << "was it a consonant? " << isConsonant(response) << endl;
    
    

    return 0;
}