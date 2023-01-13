//Owen Kutzscher
//9/15/21
//hw # 3

//hw3 Q1

#include <iostream>

using namespace std;


int main(){
    int age = 0;
    cout << "Enter the age:" << endl;
    cin >> age;

    if(age < 0){
        cout << "Invalid age" << endl;
    }else{
        if(age >= 21){
            cout << "You are allowed to go inside the bar" << endl;
        }else{
            cout << "You are not allowed to go inside the bar" << endl;
        }
    }

    return 0;
}

