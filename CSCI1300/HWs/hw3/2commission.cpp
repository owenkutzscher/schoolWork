//Owen Kutzscher
//9/15/21
//hw # 3

//hw3 Q2

#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    double revenue = 0.0;
    cout << "Enter the value for revenue:" << endl;
    cin >> revenue;

    double commission = 0.0;

    //check for negative, then
    //do stuff if larger or smaller than 65k
    if(revenue < 0){
        cout << "Invalid input." << endl;
    }else{
        if(revenue <= 65000.00){
            commission = revenue * 0.10;
        }else{
            double pt2 = revenue - 65000.00;
            pt2 = pt2 * 0.25;
            commission = (65000.00*0.10) + (pt2);
        }
        
    
        cout << "The commission that you earn is $";
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << commission << endl;
        
        
    }
    
    

    return 0;
}

