//Owen Kutzscher
//9/15/21
//hw # 3

//hw3 Q3

#include <iostream>
#include <iomanip>

//cool break statment here

using namespace std;


int main(){
    
    
    
    //take num students
    int numStudents = 0;
    cout << "Enter the number of students in the school district:"
    << endl;

    cin >> numStudents;

    //if negative tell em its invalid
    if(numStudents < 0){
        cout << "Invalid input.";
    }else{
        //calculate total cost

        

        //find discount
        float discountRate = 0.0;

        switch(numStudents){
            case 0 ... 99:
                //cout << "its 1-99!!!!!" << endl;
                discountRate = 0.00;
                break;

            case 100 ... 199:
                //cout << "its 100-199!!!!!" << endl;
                discountRate = 0.10;
                break;

            case 200 ... 399:
                
                discountRate = 0.15;
                break;
            case 400 ... 599:
                
                discountRate = 0.20;
                break;

            default:
                //cout << "its 600+ !!!!!" << endl;
                discountRate = 0.25;
                break;
        }



        
        //find og cost
        double ogCost = ((double)numStudents) * 5.50;

        double totalCost = 0.0;

        //total cost is og cost - discount

        totalCost = ogCost - (ogCost * discountRate);

        //output total cost, do some decimal place shit
        cout << "The total cost for buying art kits is $";
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << totalCost << endl;

    }
    //^end of the if statment for negative numbers
    
    
    

    return 0;
}

