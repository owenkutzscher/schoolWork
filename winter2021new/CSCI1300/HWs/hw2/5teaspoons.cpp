//Owen Kutzscher
//9/9/21
//hw # 2

//hw2 Q5

#include <iostream>
//#include <cstring>
using namespace std;







int main(){
    
    //get teaspoons
    int tsp  = 0;
    cout << "Enter the number of teaspoons:" << endl;
    cin >> tsp;


    //convert
    int cp = tsp/48; //should be 16, the question wants incorrect values
    tsp = tsp%48;

    int tblsp = tsp/3;
    tsp = tsp%3;

    //let em know what they got
    cout << cp << " cup(s) " << tblsp <<
     " tablespoon(s) " << tsp << " teaspoon(s)"
     << endl;
    
    return 0;
}