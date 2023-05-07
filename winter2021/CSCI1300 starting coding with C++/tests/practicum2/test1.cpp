
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Owen Kutzscher
//10/18/21
//practicum 2


void printGoals(string teamNames[], int goals[], int numElements){
    

    for(int i = 0; i < numElements; i++){
        if(goals[i] < 45 || goals[i] > 60){
            cout << teamNames[i] << " " << goals[i] << endl;
        }
    }
}


int main(){
    string teamNames[] = {"San Jose", "Portland", "Colorado", "Vancouver"};
    int goals[] = {70, 60, 54, 42};

    printGoals(teamNames, goals, 4);

    //expected output
    //San Jose 70
    //Vancouver 42
    return 0;
}