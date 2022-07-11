//Owen Kutzscher
//9/9/21
//hw # 2

//ayyy set percision guy here

//hw2 Q3

#include <iostream>
#include <iomanip>
//#include <cstring>
using namespace std;



//lets calculate the area of a rectangle
int main(){
    double side1 = 0;
    double side2 = 0;

    cout << "Enter the length of side a in inches: " << endl;
    cin >> side1;

    cout << "Enter the length of side b in inches: " << endl;
    cin >> side2;

    //convert to feet!
    side1 = side1/12;
    side2 = side2/12;

    double area = side1 * side2;

    //area = area.setprecision(2);

    //cout << setprecision(3) << area << endl;

    //std::cout << std::setprecision(2) << area << endl;
    
    

    cout << "The area of the rectangular field is ";
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << area;
    cout << " square feet" << endl;
    return 0;
}