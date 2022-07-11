//Owen Kutzscher
//9/15/21
//hw # 3

//hw3 Q4

#include <iostream>

using namespace std;


int main(){
    
    int a = 0;
    int b = 0;
    int c = 0;

    cout << "Enter boxers' weights" << endl;
    
    cin >> a;
    cin >> b;
    cin >> c;

    //cout << "weights are a b c : " << a << " " << b << " " << c << endl; 

    //lets see if they are in any order
    if((a < b) && (b < c)){
        cout << "Ascending order" << endl;
    }else if((a > b) && (b > c)){
        cout << "Descending order" << endl;
    }else{
        cout << "Neither" << endl;
    }

    return 0;
}

