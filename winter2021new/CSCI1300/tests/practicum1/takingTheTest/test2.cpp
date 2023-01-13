
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Owen Kutzscher
//9/15/21
//practicum 1





int main(){
    //print the beverage time

    char beverage = ' ';
    cout << "Enter the first letter of your beverage:" << endl;
    cin >> beverage;

    //we will return this at the end
    string response = " ";

    switch(beverage){
        case 'T':
            response = "Tea";
            break;
        case 'C':
            response = "Cocoa";
            break;
        case 'W':
            response = "Water";
            break;
        case 'G':
            response = "Gatorade";
            break;

            
        default:
            response = "Invalid";
            break;


    }

    cout << "Your Favorite Beverage: " << response << endl;


    return 0;
}