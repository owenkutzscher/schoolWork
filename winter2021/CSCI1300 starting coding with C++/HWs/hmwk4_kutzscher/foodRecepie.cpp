//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 4 - Problem 3

//pseudo code:
/*

have a loop, it breaks if you select quit
ask em what they want on the menu
interogate, how much of each ingredient


*/


#include <iostream>


using namespace std;


int main(){
    //the code really starts down below, but im going to do some
    //funcitons up here



/*
    bool canMakeBLT(){
        bool b = false;

        return b;
    }
*/














    //have a loop, it breaks if you select quit
    bool quit = false;
    while(quit == false){
        
        int response = 0;

        //ask em what they want on the menu
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. BLT" << endl;
        cout << "2. Caprese" << endl;
        cout << "3. Veggie" << endl;
        cout << "4. Quit" << endl;
        cin >> response;

        //break if response was 4
        if(response == 4){
            quit = true;
            cout << "Goodbye!" << endl;
        }else{
            //else, they wanna get something from the menu


            if(response == 1){
                //BLT time
                //canMake = canMakeBLT();

                int canMake = 0;
                
                //in order to be abl to make it
                //canMake needs to get all 4 points

                //lets see if they have enough of each thing
                double input = 0.00;
                cout << "How many bacon strips do you have?" << endl;
                cin >> input;
                if(input >= 4){
                    canMake++;
                }
                cout << "How many tomato slices do you have?" << endl;
                cin >> input;
                if(input >= 3){
                    canMake++;
                }
                cout << "How many lettuce leaves do you have?" << endl;
                cin >> input;
                if(input >= 2){
                    canMake++;
                }
                cout << "How many ounces of mayonnaise do you have?" << endl;
                cin >> input;
                if(input >= 0.51){
                    canMake++;
                }



                if(canMake == 4){
                    cout << "You can make a BLT." << endl;
                }else{
                    cout << "You don't have enough for a BLT." << endl;
                }



            }else if(response == 2){
                //Caprese time
                //cout << "caprese time" << endl;

                int canMake = 0;
                
                //in order to be abl to make it
                //canMake needs to get all 4 points

                //lets see if they have enough of each thing
                double input = 0.00;
                cout << "How many mozzarella slices do you have?" << endl;
                cin >> input;
                if(input >= 4){
                    canMake++;
                }
                cout << "How many tomato slices do you have?" << endl;
                cin >> input;
                if(input >= 2){
                    canMake++;
                }
                cout << "How many basil leaves do you have?" << endl;
                cin >> input;
                if(input >= 9){
                    canMake++;
                }
                cout << "How many ounces of balsamic glaze do you have?" << endl;
                cin >> input;
                if(input >= 0.12){
                    canMake++;
                }



                if(canMake == 4){
                    cout << "You can make a caprese sandwich." << endl;
                }else{
                    cout << "You don't have enough for a caprese sandwich." << endl;
                }



            }else if(response == 3){
                //Veggie time
                //cout << "veggie time" << endl;

                int canMake = 0;
                
                //in order to be abl to make it
                //canMake needs to get all 4 points

                //lets see if they have enough of each thing
                double input = 0.00;
                cout << "How many red onion rings do you have?" << endl;
                cin >> input;
                if(input >= 5){
                    canMake++;
                }
                cout << "How many cucumber slices do you have?" << endl;
                cin >> input;
                if(input >= 7){
                    canMake++;
                }
                cout << "How many ounces of diced roasted pepper do you have?" << endl;
                cin >> input;
                if(input >= 2.33){
                    canMake++;
                }
                cout << "How many ounces of hummus do you have?" << endl;
                cin >> input;
                if(input >= 2.5){
                    canMake++;
                }



                if(canMake == 4){
                    cout << "You can make a veggie sandwich." << endl;
                }else{
                    cout << "You don't have enough for a veggie sandwich." << endl;
                }



            }else{
                cout << "Invalid input." << endl;
            }
        }

        //interogate, how much of each ingredient
    }
    
    

    return 0;
}