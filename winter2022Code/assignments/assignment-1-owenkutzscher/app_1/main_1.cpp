#include <iostream>
#include <fstream>
#include "../code_1/fundamentals_1.hpp"

using namespace std;

//adds numbers from a .txt file into an array from
//smallest to largest.
int main(int argc, char* argv[]) {
    // TODO
    
    

    float sortedArray[100];
    int numElements = 0;
    float newValue = 0;
    string line = " ";


    ifstream numberFile(argv[1]);

    if(numberFile.is_open())
    {
        while(getline(numberFile, line))
        {
            if(line.length() != 0)
            {
                newValue = stof(line);
                numElements = addToArrayAsc(sortedArray, numElements, newValue);
                


                //print current sortedArray
                for(int i = 0; i < numElements-1; i++)
                {
                    cout << sortedArray[i] << ',';
                }

                cout << sortedArray[numElements-1]<<endl;
            }
        }
    }else
    {
        cout << "Failed to open the file." << endl;
    }


    return 0;
}