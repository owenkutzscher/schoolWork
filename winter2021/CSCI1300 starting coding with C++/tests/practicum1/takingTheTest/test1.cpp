
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Owen Kutzscher
//9/15/21
//practicum 1





int main(){
    //racers edge

    //ask em for inputs
    double baseCost= 0.00;
    cout << "Enter the base cost of the car:" << endl;
    cin >> baseCost;

    int numUpgrades = 0;
    cout << "Enter the number of upgrades made:" << endl;
    cin >> numUpgrades;

    double costPerUpgrade = 0.00;
    cout << "Enter the cost per upgrade:" << endl;
    cin >> costPerUpgrade;

    //calculate, if discount then apply it
    double finalCost = 0.00;
    if(numUpgrades > 3){
        finalCost = (3.00 * costPerUpgrade) + (((double)numUpgrades - 3.00 ) * 
        costPerUpgrade * 0.50) + baseCost;
    }else{
        finalCost = ((double)numUpgrades * costPerUpgrade) + baseCost;
    }

    //return finalCost, don't forget abt .00 setprecision()
    
    cout << "The final cost of the car is: ";
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << finalCost << endl;

    return 0;
}