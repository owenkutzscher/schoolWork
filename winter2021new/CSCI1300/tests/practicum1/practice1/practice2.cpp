//Owen Kutzscher
//date
//practicum practice

#include <iostream>


using namespace std;


int main(){
    //ask for #s
    int num = 0;
    cout << "Enter the day:" << endl;
    cin >> num;

    


    
    //validate and do it
    switch (num){
        //print what day of the week it is
        


        case 1:
            cout << "MONDAY" << endl;
            break;

        case 2 ... 4:
            cout << "WORKDAY" << endl;
            break;

        case 5:
            cout << "FUNDAY" << endl;
            break;



        case 6:
            cout << "SLEEPDAY" << endl;
            break;
        case 0:
            cout << "SLEEPDAY" << endl;
            break;   

            

        default:
            cout << "INVALID" << endl;

    }
        
    
    



    
    return 0;
}