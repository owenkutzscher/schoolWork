//Owen Kutzscher
//9/15/21
//hw # 3

//hw3 Q4

#include <iostream>

using namespace std;

// man I really should have used swith statments :///

int main(){
    //ask em for numbers for the options avalable

    int price = 0;

    //this will be useful to determine where to go next and such
    int lastResponse = 0;

    //this will be useful to stop the whole operation
    bool stopIt = 0;
    
    //lets ask abt the type of phone
    cout << "Enter Type of Phone : 1.Apple 2.Samsung" << endl;
    cin >> lastResponse;



    if(lastResponse == 1){
        //apple


        //man I'd like to do functions rn....
        cout << "Enter Year Made : 1.Before 2015 2.After 2015" << endl;
        cin >> lastResponse;

        
        if(lastResponse == 1){
            //before 2015

            cout << "Enter Storage Capacity : 1.32GB 2.64GB" << endl;
            cin >> lastResponse;
            if(lastResponse == 1){
                price = 80;

            }else if(lastResponse == 2){
                price = 120;

            }else{
                stopIt = 1;
            }



        }else if(lastResponse == 2){
            //after 2015
            cout << "Enter Storage Capacity : 1.64GB 2.128GB 3.256GB" << endl;
            cin >> lastResponse;
            if(lastResponse == 1){
                price = 140;
            }else if(lastResponse == 2){
                price = 190;
            }else if(lastResponse == 3){
                price = 250;
            }else{
                stopIt = 1;
            }


        }else{
            stopIt = 1;
        }











    }else if(lastResponse == 2){
        //samsung



        cout << "Enter Year Made : 1.Before 2017 2.After 2017" << endl;
        cin >> lastResponse;
        
        if(lastResponse == 1){
            //before 2017
            cout << "Enter Storage Capacity : 1.32GB 2.64GB 3.128GB" << endl;
            cin >> lastResponse;
            if(lastResponse == 1){
                price = 90;
            }else if(lastResponse == 2){
                price = 125;

            }else if(lastResponse == 3){
                price = 165;
            }else{
                stopIt = 1;
            }




        }else if(lastResponse == 2){
            //after 2017
            cout << "Enter Storage Capacity : 1.128GB 2.256GB" << endl;
            cin >> lastResponse;
            if(lastResponse == 1){
                price = 220;

            }else if(lastResponse == 2){
                price = 260;

            }else{
                stopIt = 1;
            }





        }else{
            stopIt = 1;
        }
        


    }else{
        stopIt = 1;
    }



    //lets return something to the uer shal we
    if(stopIt == 1){
        cout << "Invalid Input." << endl;
    }else{
        cout << "Price of the phone is $" << price << "." << endl;
    }





/*

cout << "Enter" << endl;
cin >> lastResponse;
if(lastResponse == 1){

}else if(lastResponse == 2){

}else{
    stopIt = 1;
}

*/




}

