#include<iostream>
#include<cmath>
#include<iomanip>
#include "../code_1/MessageDecoder.hpp"

#include<cstring>
#include<array>
#include<cctype>

using namespace std;



/*
bool isEmpty(char charArray[], int size)
{


    for(int i = 0; i < size-1; i++)
    {
        cout << "element is: ***" << charArray[i] << "***" << endl;
        if(isblank(charArray[i]))
        {
            cout << "detected element thats not blank" << endl;
            //return false;
        }
    }
    return true;
}

*/




int main(int argc, char* argv[])
{
    // DO NOT MODIFY THIS.
    if(argc>1)
    {
        freopen(argv[1],"r",stdin);
    }

    /* TODO- 
            1. cout #>
            2. get the user input
            3. store them in an array
            4. If the array is empty then print "Nothing to evaluate"
            else call the evaluate function
    */
   
   
   
   
   
   string stringResponse ="";



   cout << "Enter the encoded sentence" << endl;
    cout << "#>";
   getline(cin, stringResponse);

   

   
   

   

   



   if(stringResponse.size() == 0)
   {
    cout << "Nothing to evaluate";
   }
   else
   {
    char response[stringResponse.size()]; // userInput

    strcpy(response, stringResponse.c_str());

    MessageDecoder coolMessage;
    coolMessage.evaluate(response);
   }
   
    
  return 0;
}
