
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Owen Kutzscher
//9/15/21
//practicum 1





int main(){
    //helping john
    
    int team; 
	cout << "Enter a team:" << endl; 
	cin >> team; 
    
	if(team >= 4 && team <= 11){
		cout << "This team belongs to the North." << endl ;

	}else if(team >= 12 && team <= 19){
		cout << "This team belongs to the East." << endl; 

	}else if( team >= 20 && team <= 27){
        cout << "This team belongs to the South." << endl; 

	} else if((team >= 28 && team <= 32) || (team >=1 && team <=3)){
		cout << "This team belongs to the West." << endl; 
	}else{
		cout << "Invalid" << endl; 
	}

	return 0;
}