//Owen Kutzscher
//9/9/21
//hw # 2

//hw2 Q4

#include <iostream>
//#include <cstring>
using namespace std;







int main(){

    //current number of animals
    int currentFox = 18000;
    int currentBunny = 21000;
    int currentSloth = 10000;

    //get years
    //years x, user input
    int x = 0;
    cout << "Enter the number of years to estimate: " << endl;
    cin >> x;

    //calculate new animals
    int newFox = (115*x) - (100*x);
    int newBunny = (90*x) - (80*x);
    int newSloth = (70*x) - (120*x);

    currentFox = newFox + currentFox;
    currentBunny = newBunny + currentBunny;
    currentSloth = newSloth + currentSloth;

    //if zero or less then make zero
    
    if(currentFox <= 0){
        currentFox = 0;
    }
    if(currentBunny <= 0){
        currentBunny = 0;
    }
    if(currentSloth <= 0){
        currentSloth = 0;
    }

    //return numbers
    cout << "There will be " << currentFox << " foxes, "
                    << currentBunny << " bunnies, and "
                    << currentSloth << " sloths in "
                    << x << " years." << endl;
    
    return 0;
}