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


using namespace std;







double grossRevenue(double price){
    int revenue;
    double tickets = 1001;
    revenue = ((1.00)*price) * ((1.00)*tickets);
    return revenue;
}


int main(){

    cout << "yeeet: " << grossRevenue(1.1) << endl;



    return 0;
}