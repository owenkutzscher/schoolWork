
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Owen Kutzscher
//9/15/21
//practicum 1





int main(){
    //tempature

    int a = 0;
    int b =0;
    int c =0;

    cout << "Enter the temperature of the first area:" << endl;
    cin >> a;
    cout << "Enter the temperature of the second area:" << endl;
    cin >> b;
    cout << "Enter the temperature of the third area:" << endl;
    cin >> c;

    int highestTemp = 0;
    if((a > b) && (a > c)){
        highestTemp = a;
    }else if((b > c) && (b > a)){
        highestTemp = b;
    }else{
        highestTemp = c;
    }

    cout << "The highest temperature in the list of areas is " 
    << highestTemp << endl;


    return 0;
}