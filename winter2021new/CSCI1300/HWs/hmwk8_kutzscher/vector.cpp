//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

/*

pseudo code

loop until user inputs a -1

get user input

    //test for options and then loop again or stop:


    if its not a positive  # or -1
        respond "The number should be a positive integer or -1"
    else, it was in fact a positive # or -1
        if its -1, then shut down the loop
        else, if vecor is empty, insert user input into the vector
        else, if the input is divisible by 5, remove 
         an element from the front of the vector
        else, if the input is divisble by 3 then remove an element
         from the end of the vector
        else, insert the input value at the end of the vector

when we're done looping, if there are no elements in the vector
    print "The vector is empty"
else, display all elements of the vector,
 in order, seperated by spaces
on the next line, display the minimum value and the maximum value


*/




#include <vector>
#include <iostream>
#include <cstring>
using namespace std;



int main(){

    //this can be changed to a 0 and it will break the loop asking the user for inputs
    bool continueLooping = 1;

    //this is where we will store the users input each iteration of the loop
    int response;

    vector<int> numVec;





    // loop until user inputs a -1

    while(continueLooping == 1){
        // get user input
        cout << "Please enter a number:" << endl;
        cin >> response;
        //cout << "the intiger they entered was: " << response << endl;

        //     //test for options and then loop again or stop:

        if(   !( (response > 0) || (response == -1) )   ){
            //note that if you entered a letter it goes into an infinite loop for some reason, too bad!

            //     if its not a positive  # or -1
            //         respond "The number should be a positive integer or -1"
            cout << "The number should be a positive integer or -1." << endl;

        }else{
            //     else, it was in fact a positive # or -1
            if(response == -1){
                //         if its -1, then shut down the loop
                continueLooping = 0;
            }else{
                //cout << "cool you entered a thing thats not -1 and was valid" << endl;

                
                if(numVec.size() == 0){
                    //  else, if vecor is empty, insert user input into the vector
                    numVec.push_back(response);



                }else{
                    if(response % 5 == 0){
                    //  else, if the input is divisible by 5, remove 
                    //  an element from the front of the vector
                    numVec.erase(numVec.begin());
                    
                    }
                    
                    if(response % 3 == 0){
                        //  else, if the input is divisble by 3 then remove an element
                        //  from the end of the vector
                        if(numVec.size() > 0){
                            numVec.pop_back();
                        }
                        



                    }
                    if( !(response % 5 == 0) && !(response % 3 == 0)){
                        //  else, insert the input value at the end of the vector
                        //cout << "inserted it" << endl;
                        
                        if(numVec.size() > 0){
                            numVec.push_back(response);
                        }
                    }
                }    
                
                

                
                
            }
            
            
        }
        
        
        
    }
    
    // when we're done looping, if there are no elements in the vector
    //     print "The vector is empty"
    if(numVec.size() == 0){
        cout << "The vector is empty." << endl;
    }else{
        // else, display all elements of the vector,
        // in order, seperated by spaces
        cout << "The elements in the vector are:";
        for(int i = 0; i < numVec.size(); i++){
            cout  << " " << numVec.at(i);
        }
        cout << endl;
        // on the next line, display the minimum value and the maximum value
        int max = numVec.at(0);
        int min = numVec.at(0);
        for(int i = 0; i < numVec.size(); i++){
            if(numVec.at(i) > max){
                max = numVec.at(i);
            }
            if(numVec.at(i) < min){
                min = numVec.at(i);
            }
        }
        cout << "Min = " << min << endl;
        cout << "Max = " << max << endl;
    }
    
    
    
    

    


    return 0;
}