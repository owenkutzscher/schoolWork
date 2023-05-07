//Owen Kutzscher
//9/15/21
//hw # 3

//hw3 Q3

#include <iostream>
#include <iomanip>

//cool break statment here

using namespace std;


int main(){
    //int price = 0;

    //bool invalid = 0;
    

    int type = 0;
    cout << "Enter Type of Sport: 1.Biking 2.Skiing 3.Fishing 4.Rock Climbing"
    << endl;
    cin >> type;

    switch(type){
        case 1:
            //bike
            cout << "Choose type of Equipment : 1.Mountain Bike 2.Road Bike"
            << endl;
            cin >> type;

            switch(type){
                case 1:
                    //
                    cout << "Price of Mountain Bike is $550." << endl;
                    break;
                    
                case 2:
                    //
                    cout << "Price of Road Bike is $400." << endl;
                    break;
                    
                default:
                    //invalid
                    //invalid = 1;
                    cout << "Invalid Input.";
                    break;
                    

                
                
            }break;


        case 2:
        
        
            //skiing
            cout << "Choose type of Equipment : 1.Cross-Country Skis 2.Downhill Skis"
            << endl;
            cin >> type;

            switch(type){
                case 1:
                    //
                    cout << "Price of Cross-Country Skis is $300." << endl;
                    break;
                    
                case 2:
                    //
                    cout << "Price of Downhill Skis is $500." << endl;
                    break;
                    
                default:
                    //invalid
                    //invalid = 1;
                    cout << "Invalid Input.";
                    break;
                    
                
            }break;
        case 3:
        
        
            //fishing
            cout << "Choose type of Equipment : 1.Regular Rod 2.Fly Fishing Rod"
            << endl;
            cin >> type;

            switch(type){
                case 1:
                    //
                    cout << "Price of Regular Rod is $75." << endl;
                    break;
                    
                case 2:
                    //
                    cout << "Price of Fly Fishing Rod is $125." << endl;
                    break;
                    
                default:
                    //invalid
                    //invalid = 1;
                    cout << "Invalid Input.";
                    break;
                    
                
            }break;
        case 4:
        
        
            //rock climb
            cout << "Choose type of Equipment : 1.Bouldering Pad 2.Top Rope Pad"
            << endl;
            cin >> type;

            switch(type){
                case 1:
                    //
                    cout << "Price of Bouldering Pad is $120." << endl;
                    break;
                    
                case 2:
                    //
                    cout << "Price of Top Rope Pad is $60." << endl;
                    break;
                    
                default:
                    //invalid
                    //invalid = 1;
                    cout << "Invalid Input.";
                    break;
                    
                
            }break;
        
        default:
            
            //invalid
            //invalid = 1;
            cout << "Invalid Input.";
            break;
    }

    /* code runner would not let me use thi for no aparent reason :(
    if(invalid == 1){
        cout << "Invalid Input.";
    }
    */


}