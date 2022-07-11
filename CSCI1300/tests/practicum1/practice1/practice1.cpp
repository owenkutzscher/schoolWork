//Owen Kutzscher
//date
//practicum practice

#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    //ask for #s
    double number1 = 0;
    cout << "Enter a number:" << endl;
    cin >> number1;

    double number2 = 0;
    cout << "Enter another number:" << endl;
    cin >> number2;

    char operator1 = ' ';
    cout << "Enter an operator:" << endl;
    cin >> operator1;


    
    //validate and do it
    switch (operator1){
        //print things, and also make it end in .00
        


        case '+':
                //this below is for the .00

                cout << fixed << showpoint;
                cout << setprecision(2);
                cout << number1;

                cout << " + " <<
                number2 << " = " <<
                (number1 + number2) << endl;

                break;

        case '-':
                //this below is for the .00

                cout << fixed << showpoint;
                cout << setprecision(2);
                cout << number1;

                cout << " - " <<
                number2 << " = " <<
                (number1 - number2) << endl;
                
                break;

        case '*':
                //this below is for the .00

                cout << fixed << showpoint;
                cout << setprecision(2);
                cout << number1;

                cout << " * " <<
                number2 << " = " <<
                (number1 * number2) << endl;
                
                break;

        case '/':
                //this below is for the .00

                cout << fixed << showpoint;
                cout << setprecision(2);
                cout << number1;

                cout << " / " <<
                number2 << " = " <<
                (number1 / number2) << endl;
                
                break;

        default:
            cout << "Invalid operator!" << endl;

    }
        
    
    



    
    return 0;
}