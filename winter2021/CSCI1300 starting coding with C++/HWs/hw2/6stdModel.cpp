//Owen Kutzscher
//9/9/21
//hw # 2

//hw2 Q6

#include <iostream>
#include <cmath>
//#include <cstring>
using namespace std;

//note
//cast as double doing (double)x

int main(){
    //get a value
    double x = 0.0;
    cout << "Enter a value for x:" << endl;
    cin >> x;

    //calculate
    double probability = 0.0;
    double eToThePower = exp((-1.0/2.0)*(pow(x, 2.0)));
    //cout << "eToThePower is " << eToThePower << endl;

    probability = (1.0/(pow((2.0*M_PI), (1.0/2.0)))) * eToThePower;


    

    //return stuff
    cout << "The probability at x=" << x << " is "
    << probability << endl;


    return 0;
}